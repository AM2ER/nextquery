//
// Created by ameer on 9/22/19.
//

#include <algorithm>
#include "HttpClient.h"
#include "GoogleHtmlParser.h"
#include "BingHtmlParser.h"
#include "QueryRunner.h"

void QueryRunner::exec(std::string source, std::string url, std::vector<std::string> keywords)
{
    HttpClient httpClient;

    std::string htmlPage = httpClient.query(url, keywords);

    std::unique_ptr<HtmlParser> htmlParser;

    if (source == "google")
    {
        htmlParser.reset(new GoogleHtmlParser());
    }
    else
    {
        htmlParser.reset(new BingHtmlParser());
    }

    const std::vector<QueryResult> searchResult = htmlParser->parse(source, htmlPage);

    std::unique_lock<std::mutex> lck(_mutex);

    results.get()->insert(results.get()->end(), searchResult.begin(), searchResult.end());

    lck.unlock();
}

void QueryRunner::executeQuery(std::string source, std::string url, std::vector<std::string> keywords)
{
    std::thread *args = new std::thread(&QueryRunner::exec, this, source, url, keywords);

    workers.push_back(args);
}

std::vector<QueryResult> QueryRunner::getResults()
{
    std::for_each(workers.begin(), workers.end(), [](std::thread *t) {
        t->join();
    });

    return *results.get();
}
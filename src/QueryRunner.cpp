//
// Created by ameer on 9/22/19.
//

#include "QueryRunner.h"
#include "HttpClient.h"
#include "GoogleHtmlParser.h"
#include "BingHtmlParser.h"

#include <vector>

std::shared_ptr<std::vector<QueryResult>> results;

void QueryRunner::executeQuery(std::string source, std::string url, std::vector<std::string> keywords)
{
    const std::thread &args = std::thread(&QueryRunner::exec, source, url, keywords);

    workers.emplace_back(args);
}

std::vector<QueryResult> *QueryRunner::getResults()
{
    for (std::thread &t : workers)
    {
        t.join();
    }

    return results.get();
}

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

    const std::vector<QueryResult> &searchResult = htmlParser->parse(source, htmlPage);

    std::unique_lock<std::mutex> lck(_mutex);
    results.get()->insert(results.get()->end(), searchResult.begin(), searchResult.end());
    lck.unlock();
}
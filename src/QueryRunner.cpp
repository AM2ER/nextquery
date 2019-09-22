//
// Created by ameer on 9/22/19.
//

#include "QueryRunner.h"
#include "HttpClient.h"
#include "HtmlParser.h"

#include <vector>

std::shared_ptr<std::vector<QueryResult>> results;

void QueryRunner::executeQuery(std::string source, std::string url, std::vector<std::string> keywords)
{
    workers.push_back(std::thread(&QueryRunner::exec, source, url, keywords));
}

std::shared_ptr<std::vector<QueryResult>> QueryRunner::getResults()
{
    for(std::thread &t : workers)
    {
        t.join();
    }

    return results;
}

void QueryRunner::exec(std::string source, std::string url, std::vector<std::string> keywords)
{
    HttpClient httpClient;

    std::string htmlPage = httpClient.query(url, keywords);

    HtmlParser htmlParser;

    const std::vector<QueryResult> &searchResult = htmlParser.parse(source, htmlPage);

    results.get()->insert(results.get()->end(), searchResult.begin(), searchResult.end());
}
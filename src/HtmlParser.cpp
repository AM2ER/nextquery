//
// Created by ameer on 9/15/19.
//

#include <iostream>
#include "HtmlParser.h"

HtmlParser::HtmlParser()
{
    letterMappings["%2B"] = "+";
}

std::vector<QueryResult> HtmlParser::parse(std::string htmlPage)
{
    // std::cout << "boubou " << htmlPage << std::endl;

    size_t pos = htmlPage.find("<div class=\"kCrYT\"><a href=\"/url?q=", 0);

    std::vector<QueryResult> queryResults;

    while (pos != std::string::npos)
    {
        int shift = 35;

        pos = pos + shift;

        int end_pos = htmlPage.find("\">", pos);

        std::string url = htmlPage.substr(pos, end_pos - pos);

        url = encode(url);

        std::cout << url << std::endl;

        pos = end_pos;

        pos = htmlPage.find("<div class=\"BNeawe vvjwJb AP7Wnd\">", pos);

        pos = pos + 36;

        end_pos = htmlPage.find("\">", pos);

        std::string desc = htmlPage.substr(pos, end_pos - pos);

        queryResults.push_back(QueryResult(url, desc));

        pos = end_pos;

        pos = htmlPage.find("<div class=\"kCrYT\"><a href=\"/url?q=", pos);
    }

    return queryResults;
}

std::string HtmlParser::encode(std::string basicString)
{
    for (const auto &[key, value] : letterMappings)
    {
        basicString = ReplaceAll(basicString, key, value);
    }

    return basicString;
}

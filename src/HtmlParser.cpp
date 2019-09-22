//
// Created by ameer on 9/15/19.
//

#include <iostream>
#include "HtmlParser.h"

HtmlParser::HtmlParser()
{
    letterMappings["%2B"] = "+";
}

std::vector<QueryResult> HtmlParser::parse(std::string source, std::string htmlPage)
{
    // std::cout << "boubou " << htmlPage << std::endl;

    size_t pos = htmlPage.find(getTitlePattern(), 0);

    std::vector<QueryResult> queryResults;

    while (pos != std::string::npos)
    {
        int shift = getTitleShift();

        pos = pos + shift;

        int end_pos = htmlPage.find(getTitleEndPattern(), pos);

        std::string url = htmlPage.substr(pos, end_pos - pos);

        url = encode(url);

        std::cout << url << std::endl;

        pos = end_pos;

        pos = htmlPage.find(getDescriptionPattern(), pos);

        pos = pos + getDescriptionShift();

        end_pos = htmlPage.find("<", pos);

        std::string desc = htmlPage.substr(pos, end_pos - pos);

        queryResults.push_back(QueryResult(source, url, desc));

        pos = end_pos;

        pos = htmlPage.find(getTitlePattern(), pos);
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

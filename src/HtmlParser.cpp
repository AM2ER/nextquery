//
// Created by ameer on 9/15/19.
//

#include <iostream>
#include "HtmlParser.h"

std::vector<QueryResult> HtmlParser::parse(std::string htmlPage)
{
    // std::cout << "boubou " << htmlPage << std::endl;

    size_t pos = htmlPage.find("<div class=\"kCrYT\"><a href=\"/url?q=", 0);

    while(pos != std::string::npos)
    {
         int end_pos = htmlPage.find("\">", pos + 38);

         std::string url = htmlPage.substr(pos, end_pos - pos);

         std::cout << url << std::endl;

         pos = htmlPage.find("<div class=\"kCrYT\"><a href=\"/url?q=", end_pos);
    }


    std::vector<QueryResult> queryResults;

    return queryResults;
}
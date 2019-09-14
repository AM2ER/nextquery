//
// Created by ameer on 9/7/19.
//

#include "UrlBuilder.h"
#include "curl/curl.h"

UrlBuilder::UrlBuilder()
{
    letterMappings['+'] = "%2B";

    urls["google"] = "https://www.google.com/search?q=";
    urls["ddg"] = "https://www.duckduckgo.com/?q=";
}

std::string UrlBuilder::build(std::vector<std::string> params)
{
    std::vector<std::string> encodedParams;

    int first = 0;

    std::string url = urls["google"];

    for (std::string element : params)
    {
        for (const auto &[key, value] : letterMappings)
        {
            element = ReplaceAll(element, key, value);
        }

        // append to url query item
        if (first == 0)
        {
            url.append(element);

            first = 1;
        }
        else
        {
            url.append("+");
            url.append(element);
        }
    }

    return url;
}

std::string UrlBuilder::ReplaceAll(std::string str, const char &search, const std::string &replace)
{
    size_t start_pos = 0;

    while ((start_pos = str.find(search, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, 1, replace);
        start_pos += replace.length(); // Handles case where 'search' is a substring of 'replace'
    }

    return str;
}
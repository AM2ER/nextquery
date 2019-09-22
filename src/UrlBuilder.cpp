//
// Created by ameer on 9/7/19.
//

#include "UrlBuilder.h"

UrlBuilder::UrlBuilder()
{
    letterMappings["+"] = "%2B";
    letterMappings["-"] = "%2B";
}

std::string UrlBuilder::build(std::string url, std::vector<std::string> params)
{
    std::vector<std::string> encodedParams;

    int first = 0;

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
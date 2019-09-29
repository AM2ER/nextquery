//
// Created by ameer on 9/7/19.
//

#include <sstream>

#include "HttpClient.h"
#include "UrlBuilder.h"

#include "../curlpp/include/curlpp/cURLpp.hpp"
#include "../curlpp/include/curlpp/Easy.hpp"
#include "../curlpp/include/curlpp/Options.hpp"

std::string HttpClient::query(std::string url, std::vector<std::string> keywords)
{
    curlpp::Cleanup cleaner;
    curlpp::Easy request;

    // Set the writer callback to enable cURL
    // to write result in a memory area
    request.setOpt(new curlpp::options::WriteStream(&std::cout));

    // Setting the URL to retrive.
    request.setOpt(new curlpp::options::Url(urlBuilder.build(url, keywords)));

    std::ostringstream response;
    request.setOpt(new curlpp::options::WriteStream(&response));

    request.perform();

    std::string str = response.str();

    return str;
}
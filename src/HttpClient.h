//
// Created by ameer on 9/7/19.
//

#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <string>
#include "UrlBuilder.h"

class HttpClient
{
public:
    std::string query(std::string url, std::vector<std::string> keywords);

private:
    UrlBuilder urlBuilder;
};


#endif //HTTPCLIENT_H

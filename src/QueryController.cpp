//
// Created by ameer on 9/7/19.
//

#include "QueryController.h"

QueryController::QueryController()
{
    urls["google"] = "https://www.google.com/search?q=";
    urls["bing"] = "https://www.bing.com/search?q=";
}

std::map<std::string, std::string> QueryController::getUrls()
{
    return urls;
}

std::vector<QueryResult> QueryController::createQueryUrl(std::vector<std::string> keywords)
{

}
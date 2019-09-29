//
// Created by ameer on 9/7/19.
//

#ifndef SEARCHREQUEST_H
#define SEARCHREQUEST_H

#include <vector>
#include <string>
#include <map>

#include "QueryResult.h"

class QueryController {
public:
    QueryController();
    std::vector<QueryResult> createQueryUrl(std::vector<std::string> keywords);
    std::map<std::string, std::string> getUrls();
private:
    std::map<std::string, std::string> urls;
};

#endif //SEARCHREQUEST_H

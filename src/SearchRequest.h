//
// Created by ameer on 9/7/19.
//

#ifndef SEARCHREQUEST_H
#define SEARCHREQUEST_H

#include <vector>
#include <string>

class SearchRequest {
public:
    std::vector<std::string> getRequest(std::string url);
};


#endif //SEARCHREQUEST_H

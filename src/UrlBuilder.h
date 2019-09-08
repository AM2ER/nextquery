//
// Created by ameer on 9/7/19.
//

#ifndef URLBUILDER_H
#define URLBUILDER_H

#include <string>
#include <vector>

class UrlBuilder
{
    public:

    std::string build(std::string url, std::vector<std::string> params);
};


#endif //URLBUILDER_H

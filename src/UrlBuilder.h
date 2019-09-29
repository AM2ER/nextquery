//
// Created by ameer on 9/7/19.
//

#ifndef URLBUILDER_H
#define URLBUILDER_H

#include <string>
#include <vector>
#include <map>
#include "AbstractBase.h"

class UrlBuilder : AbstractBase
{
public:
    UrlBuilder();

    std::string build(std::string url, std::vector<std::string> params);

private:
    std::map<std::string,std::string> letterMappings;
};


#endif //URLBUILDER_H

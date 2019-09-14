//
// Created by ameer on 9/7/19.
//

#ifndef URLBUILDER_H
#define URLBUILDER_H

#include <string>
#include <vector>
#include <map>

class UrlBuilder
{
public:
    UrlBuilder();

    std::string build(std::vector<std::string> params);

private:
    std::map<char,std::string> letterMappings;
    std::map<std::string, std::string> urls;

    std::string ReplaceAll(std::string str, const char &search, const std::string& replace);

};


#endif //URLBUILDER_H

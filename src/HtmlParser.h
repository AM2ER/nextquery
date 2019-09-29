//
// Created by ameer on 9/15/19.
//

#ifndef NEXTQUERY_HTMLPARSER_H
#define NEXTQUERY_HTMLPARSER_H


#include <vector>
#include <string>
#include <map>

#include "QueryResult.h"
#include "AbstractBase.h"

class HtmlParser : AbstractBase
{
public:
    HtmlParser();

    virtual std::string getTitlePattern() = 0;
    virtual std::string getTitleEndPattern() = 0;
    virtual std::string getDescriptionPattern() = 0;
    virtual int getTitleShift() = 0;
    virtual int getDescriptionShift() = 0;

    std::vector<QueryResult>& parse(std::string source, std::string htmlPage);

private:
    std::string encode(std::string pattern);

    std::vector<QueryResult> queryResults;
    std::map<std::string, std::string> letterMappings;
};

#endif //NEXTQUERY_HTMLPARSER_H

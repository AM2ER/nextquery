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

    std::vector<QueryResult> parse(std::string htmlPage);

private:
    std::string encode(std::string basicString);

    std::map<std::string, std::string> letterMappings;
};


#endif //NEXTQUERY_HTMLPARSER_H

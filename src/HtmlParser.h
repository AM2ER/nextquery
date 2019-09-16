//
// Created by ameer on 9/15/19.
//

#ifndef NEXTQUERY_HTMLPARSER_H
#define NEXTQUERY_HTMLPARSER_H


#include <vector>
#include <string>

#include "QueryResult.h"

class HtmlParser
{
public:
    std::vector<QueryResult> parse(std::string htmlPage);
};


#endif //NEXTQUERY_HTMLPARSER_H

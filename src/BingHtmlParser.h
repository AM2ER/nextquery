//
// Created by ameer on 9/22/19.
//

#ifndef NEXTQUERY_BINGHTMLPARSER_H
#define NEXTQUERY_BINGHTMLPARSER_H


#include "HtmlParser.h"

class BingHtmlParser : public HtmlParser
{
    std::string getDescriptionPattern();

    std::string getTitlePattern();

    std::string getTitleEndPattern();

    int getTitleShift();

    int getDescriptionShift();
};


#endif //NEXTQUERY_BINGHTMLPARSER_H

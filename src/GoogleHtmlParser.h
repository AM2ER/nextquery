//
// Created by ameer on 9/22/19.
//

#ifndef NEXTQUERY_GOOGLEHTMLPARSER_H
#define NEXTQUERY_GOOGLEHTMLPARSER_H

#include "HtmlParser.h"

class GoogleHtmlParser : public HtmlParser
{
    std::string getDescriptionPattern();

    std::string getTitlePattern();

    std::string getTitleEndPattern();

    int getTitleShift();

    int getDescriptionShift();
};


#endif //NEXTQUERY_GOOGLEHTMLPARSER_H

//
// Created by ameer on 9/22/19.
//

#include "BingHtmlParser.h"

std::string BingHtmlParser::getTitlePattern()
{
    return "<div class=\"b_title\"><h2><a href=\"";
}

std::string BingHtmlParser::getTitleEndPattern()
{
    return "\"";
}

int BingHtmlParser::getTitleShift()
{
    return 32;
}

std::string BingHtmlParser::getDescriptionPattern()
{
    return ">";
}

int BingHtmlParser::getDescriptionShift()
{
    return 32;
}
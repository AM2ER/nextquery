//
// Created by ameer on 9/22/19.
//

#include "GoogleHtmlParser.h"

std::string GoogleHtmlParser::getTitlePattern()
{
    return "<div class=\"kCrYT\"><a href=\"/url?q=";
}

std::string GoogleHtmlParser::getTitleEndPattern()
{
    return "\">";
}

int GoogleHtmlParser::getTitleShift()
{
    return 35;
}

std::string GoogleHtmlParser::getDescriptionPattern()
{
    return "<div class=\"BNeawe vvjwJb AP7Wnd\">";
}

int GoogleHtmlParser::getDescriptionShift()
{
    return 34;
}

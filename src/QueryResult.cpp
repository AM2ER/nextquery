//
// Created by ameer on 9/15/19.
//

#include <string>
#include "QueryResult.h"

QueryResult::QueryResult(std::string title, std::string url, std::string desc)
{
    this->title = title;
    this->url = url;
    this->desc = desc;
}

const std::string &QueryResult::getTitle() const
{
    return title;
}

const std::string& QueryResult::getUrl() const
{
    return url;
}

const std::string &QueryResult::getDesc() const
{
    return desc;
}

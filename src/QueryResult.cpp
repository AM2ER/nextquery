//
// Created by ameer on 9/15/19.
//

#include <string>
#include "QueryResult.h"

QueryResult::QueryResult(std::string source, std::string url, std::string desc)
{
    this->source = source;
    this->url = url;
    this->desc = desc;
}

const std::string QueryResult::getSource() const
{
    return source;
}

const std::string QueryResult::getUrl() const
{
    return url;
}

const std::string QueryResult::getDesc() const
{
    return desc;
}

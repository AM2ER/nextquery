#include <map>

//
// Created by ameer on 9/17/19.
//

#ifndef NEXTQUERY_ABSTRACTBASE_CPP
#define NEXTQUERY_ABSTRACTBASE_CPP

class AbstractBase
{
public:
    std::string ReplaceAll(std::string str, const std::string &search, const std::string &replace)
    {
        size_t start_pos = 0;

        int len = search.length();

        while ((start_pos = str.find(search, start_pos)) != std::string::npos)
        {
            str.replace(start_pos, len, replace);
            start_pos += replace.length(); // Handles case where 'search' is a substring of 'replace'
        }

        return str;
    }
};

#endif //NEXTQUERY_ABSTRACTBASE_CPP
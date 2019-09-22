//
// Created by ameer on 9/15/19.
//

#ifndef NEXTQUERY_QUERYRESULT_H
#define NEXTQUERY_QUERYRESULT_H


class QueryResult
{
public:
    QueryResult(std::string source, std::string url, std::string desc);

    const std::string getSource() const;
    const std::string getUrl() const;
    const std::string getDesc() const;

private:
    std::string source;
    std::string url;
    std::string desc;
};


#endif //NEXTQUERY_QUERYRESULT_H

//
// Created by ameer on 9/22/19.
//

#ifndef NEXTQUERY_QUERYRUNNER_H
#define NEXTQUERY_QUERYRUNNER_H


#include <string>
#include <vector>
#include <thread>

#include "QueryResult.h"

class QueryRunner
{
public:
    void executeQuery(std::string source, std::string url, std::vector<std::string> keywords);
    std::shared_ptr<std::vector<QueryResult>> getResults();

private:
    std::vector<std::thread> workers;
    void exec(std::string source, std::string url, std::vector<std::string> keywords);
};


#endif //NEXTQUERY_QUERYRUNNER_H

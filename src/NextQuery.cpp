#include <iostream>
#include "NextQuery.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "NextQuery " << APP_VERSION_MAJOR << "." << APP_VERSION_MINOR << endl;
        cerr << "Usage is ./NextQuery <space separated list of keywords>" << endl;
        return 1;
    }

    QueryController queryController;

    std::vector<std::string> keywords;

    keywords.push_back("c++");

    std::vector<QueryResult> results = queryController.createQueryUrl(keywords);

    for(QueryResult qr : results)
    {
        std::cout << qr.getSource() << " :: " << qr.getDesc() << std::endl;
        std::cout << qr.getUrl() << std::endl;
        std:cout << "\n";
    }

    return 0;
}
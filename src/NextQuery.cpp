#include <iostream>
#include <fstream>
#include "NextQuery.h"

using namespace std;

void persistToHistory(vector <string> keywords);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "NextQuery " << APP_VERSION_MAJOR << "." << APP_VERSION_MINOR << endl;
        cerr << "Usage for search is ./NextQuery <space separated list of keywords>" << endl;
        cerr << "Usage to see keywords history is ./NextQuery -h" << endl;

        return 1;
    }

    if (string(argv[1]) == "-h")
    {
        string line;

        ifstream file ("history.txt");

        if (file.is_open())
        {
            while ( getline (file, line) )
            {
                cout << line << '\n';
            }

            file.close();
        }
    }
    else
    {
        cout << "Searched " << argc - 1 << " keywords:" << "\n";

        std::vector<std::string> keywords;

        for (int i = 1; i < argc; ++i)
        {
            cout << argv[i] << "\n";

            keywords.push_back(argv[i]);
        }

        persistToHistory(keywords);

        QueryController queryController;

        std::vector<QueryResult> results = queryController.createQueryUrl(keywords);

        for (QueryResult qr : results)
        {
            std::cout << qr.getSource() << " :: " << qr.getDesc() << std::endl;
            std::cout << qr.getUrl() << std::endl;
            std:
            cout << "\n";
        }
    }

    return 0;
}

void persistToHistory(vector<std::string> keywords)
{
    ofstream file("history.txt", std::ios_base::app);

    for (unsigned int i = 0; i < keywords.size(); i++)
    {
        file << keywords[i] << " ";
    }

    file << endl;

    file.close();
}

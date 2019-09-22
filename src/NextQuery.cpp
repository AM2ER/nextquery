#include <iostream>
#include "../config/AppConfig.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "NextQuery " << APP_VERSION_MAJOR << "." << APP_VERSION_MINOR << endl;
        cerr << "Usage is ./NextQuery <space separated list of keywords>" << endl;
        return 1;
    }


    return 0;
}
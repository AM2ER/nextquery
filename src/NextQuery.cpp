#include <iostream>
#include "../config/AppConfig.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "NextQuery " << APP_VERSION_MAJOR << "." << APP_VERSION_MINOR << endl;
        cout << "Usage is list of keywords" << endl;
        return 1;
    }

    std::cout << "Hello World!" << "\n";
    return 0;
}
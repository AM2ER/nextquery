#include <fstream>
#include <string>
//
// Created by ameer on 9/15/19.
//
class FileUtil
{
public:
    static std::string readFile(std::string path);
};

std::string FileUtil::readFile(std::string path)
{
    std::ifstream file(path);

    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}
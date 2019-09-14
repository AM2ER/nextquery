//
// Created by ameer on 9/14/19.
//
#include <gtest/gtest.h>
#include "../src/HttpClient.h"

// The fixture for testing class Foo.
class HttpClientTest : public ::testing::Test
{
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    HttpClient httpClient;

    std::vector<std::string> keywords;

    HttpClientTest()
    {
        // You can do set-up work for each test here.
        std::cout << "setup" << std::endl;
    }

    ~HttpClientTest() override
    {
        // You can do clean-up work that doesn't throw exceptions here.
    }
};

TEST_F(HttpClientTest, queryUrl)
{
    keywords.push_back("c++");

    std::string query = httpClient.query(keywords);

    std::cout << query << std::endl;

    ASSERT_FALSE(query.empty());
}
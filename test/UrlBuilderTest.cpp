//
// Created by ameer on 9/7/19.
//
#include <gtest/gtest.h>
#include "../src/UrlBuilder.h"
#include "../src/QueryController.h"


// The fixture for testing class Foo.
class UrlBuilderTest : public ::testing::Test
{
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    QueryController queryController;
    UrlBuilder urlBuilder;

    std::vector<std::string> keywords;

    UrlBuilderTest()
    {
        // You can do set-up work for each test here.
        std::cout << "setup" << std::endl;
    }

    ~UrlBuilderTest() override
    {
        // You can do clean-up work that doesn't throw exceptions here.
    }
};

TEST_F(UrlBuilderTest, oneKeyword)
{
    keywords.push_back("c++");

    std::string query = urlBuilder.build(queryController.getUrls()["google"], keywords);

    ASSERT_EQ(query, "https://www.google.com/search?q=c%2B%2B");
}

TEST_F(UrlBuilderTest, twoKeyWords)
{
    keywords.push_back("c++");
    keywords.push_back("is");
    keywords.push_back("hard");

    std::string query = urlBuilder.build(queryController.getUrls()["google"], keywords);

    ASSERT_EQ(query, "https://www.google.com/search?q=c%2B%2B+is+hard");
}

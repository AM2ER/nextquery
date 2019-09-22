//
// Created by ameer on 9/15/19.
//
#include <gtest/gtest.h>
#include "../src/HtmlParser.h"
#include "FileUtil.h"

// The fixture for testing class Foo.
class HtmlParserTest : public ::testing::Test
{
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    HtmlParser htmlParser;

    std::vector<std::string> keywords;

    HtmlParserTest()
    {
        // You can do set-up work for each test here.
        std::cout << "setup" << std::endl;
    }

    ~HtmlParserTest() override
    {
        // You can do clean-up work that doesn't throw exceptions here.
    }
};


TEST_F(HtmlParserTest, parseHtmlPage)
{
    std::string htmlPage = FileUtil::readFile("../test/resources/query_response.html");

    std::vector<QueryResult> results = htmlParser.parse("source", htmlPage);

    ASSERT_TRUE(results.size() > 1);

    QueryResult &queryResult = results.front();

    ASSERT_EQ(queryResult.getSource(), "source");
    ASSERT_EQ(queryResult.getUrl(),"https://fr.wikipedia.org/wiki/C%252B%252B&amp;sa=U&amp;ved=2ahUKEwiIm_rZstLkAhUQ1RoKHTnoC7wQFnoECAsQBA&amp;usg=AOvVaw1q-f-t3-FmMZ0lbYGtK1Ud");
    ASSERT_EQ(queryResult.getDesc(),"++ &#8212; Wikip�dia");
}
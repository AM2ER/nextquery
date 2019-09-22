//
// Created by ameer on 9/15/19.
//
#include <gtest/gtest.h>
#include "FileUtil.h"
#include "../src/GoogleHtmlParser.h"
#include "../src/BingHtmlParser.h"

// The fixture for testing class Foo.
class HtmlParserTest : public ::testing::Test
{
protected:
    GoogleHtmlParser googleHtmlParser;
    BingHtmlParser bingHtmlParser;

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


TEST_F(HtmlParserTest, parseGoogleHtmlPage)
{
    std::string htmlPage = FileUtil::readFile("../test/resources/google_query_response.html");

    std::vector<QueryResult> results = googleHtmlParser.parse("google", htmlPage);

    ASSERT_TRUE(results.size() > 1);

    QueryResult &queryResult = results.front();

    ASSERT_EQ(queryResult.getSource(), "google");
    ASSERT_EQ(queryResult.getUrl(),"https://fr.wikipedia.org/wiki/C%252B%252B&amp;sa=U&amp;ved=2ahUKEwiIm_rZstLkAhUQ1RoKHTnoC7wQFnoECAsQBA&amp;usg=AOvVaw1q-f-t3-FmMZ0lbYGtK1Ud");
    ASSERT_EQ(queryResult.getDesc(),"C++ &#8212; Wikip�dia");
}

TEST_F(HtmlParserTest, parseBingHtmlPage)
{
    std::string htmlPage = FileUtil::readFile("../test/resources/bing_query_response.html");

    std::vector<QueryResult> results = bingHtmlParser.parse("bing", htmlPage);

    ASSERT_TRUE(results.size() > 1);

    QueryResult &queryResult = results.front();

    ASSERT_EQ(queryResult.getSource(), "bing");
    ASSERT_EQ(queryResult.getUrl(),"https://fr.wikipedia.org/wiki/C++");
    const std::string &string = queryResult.getDesc();

    std::cout << string << std::endl;

    ASSERT_EQ(string, "C++ \xE2\x80\x94 Wikip&#233;dia");
}
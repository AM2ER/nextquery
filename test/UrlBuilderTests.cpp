//
// Created by ameer on 9/7/19.
//
#include <gtest/gtest.h>
#include "../src/UrlBuilder.h"

using namespace std;

namespace
{
    // The fixture for testing class Foo.
    class UrlBuilderTests : public ::testing::Test
    {
        protected:
        // You can remove any or all of the following functions if its body
        // is empty.
        UrlBuilder urlBuilder;

        vector<string> keywords;

        UrlBuilderTests()
        {
            // You can do set-up work for each test here.
            cout << "setup" << endl;
        }

        ~UrlBuilderTests() override
        {
            // You can do clean-up work that doesn't throw exceptions here.
        }
    };

    TEST_F(UrlBuilderTests, buildSearchUrl)
    {
        keywords.push_back("c++");

        string query = urlBuilder.build("https://www.google.com", keywords);

        ASSERT_EQ(query, "https://www.google.com/search?q=c%2B%2B");
    }

} // namespace

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
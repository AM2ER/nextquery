cmake_minimum_required(VERSION 3.7)

set(THIS tests)

add_executable(${THIS} NextQueryTest.cpp
        UrlBuilderTest.cpp
        HttpClientTest.cpp
        HtmlParserTest.cpp
        FileUtil.h
        ../src/HtmlParser.cpp
        ../src/QueryResult.cpp
        ../src/UrlBuilder.cpp
        ../src/HttpClient.cpp
        ../src/GoogleHtmlParser.cpp
        ../src/BingHtmlParser.cpp
        ../src/QueryController.cpp
        resources/google_query_response.html)

target_link_libraries(${THIS} PUBLIC gtest_main curlpp)

add_test(
        NAME NextQueryTest COMMAND NextQueryTest
)

add_test(
        NAME UrlBuilderTest COMMAND UrlBuilderTest
)

add_test(
        NAME HttpClientTest COMMAND HttpClientTest
)

add_test(
        NAME HtmlParserTest COMMAND HtmlParserTest
)
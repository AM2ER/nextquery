cmake_minimum_required(VERSION 3.7)

set(CORE_LIB core)

# add source code as library
add_library(${CORE_LIB} STATIC
        HttpClient.cpp
        QueryResult.cpp
        QueryRunner.cpp
        QueryController.cpp
        HtmlParser.cpp
        GoogleHtmlParser.cpp
        BingHtmlParser.cpp
        UrlBuilder.cpp
        NextQuery.cpp)

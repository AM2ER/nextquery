cmake_minimum_required(VERSION 3.7)

set(CORE_LIB core)

# add source code as library
add_library(${CORE_LIB} STATIC
        NextQuery.cpp
        HttpClient.cpp
        QueryResult.cpp
        QueryController.cpp
        UrlBuilder.cpp)
cmake_minimum_required(VERSION 3.7)

set(THIS tests)

add_executable(${THIS} NextQueryTests.cpp UrlBuilderTests.cpp ../src/UrlBuilder.cpp)

target_link_libraries(${THIS} PUBLIC
        gtest_main
        )

add_test(
        NAME NextQueryTests COMMAND NextQueryTests
)

add_test(
        NAME UrlBuilderTests COMMAND UrlBuilderTests
)
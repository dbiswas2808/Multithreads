#include <catch2/catch_all.hpp>
#include <iostream>

#pragma GCC optimize("O0")
TEST_CASE("Test Threadpool") {
    std::cout << "Hello, from Multithreads!\n";
    int ii = 0;
    int jj = 0;
    CHECK(ii == jj);
}
#include <iostream>
#include <catch2/catch_all.hpp>

int main(int argc, char* argv[]) {
    std::cout << "Run tests!\n";
    int result = Catch::Session().run(argc, argv);
    std::cout << "End tests!\n";

    return result;
}
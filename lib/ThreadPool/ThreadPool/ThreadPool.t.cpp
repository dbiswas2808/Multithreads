#include <ThreadPool/ThreadPool.h>
#include <iostream>
#include <catch2/catch_all.hpp>

TEST_CASE("Test Threadpool") {
    using namespace multithreads;
    ThreadPool pool;
    std::atomic_size_t counter = 0;

    // Add thread sleep time such that tasks are highly likely to be executed in the reverse order of addition.
    pool.addTask([&counter] {
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        CHECK(counter++ == 2);
    });
    pool.addTask([&counter] {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        CHECK(counter++ == 1);
    });
    pool.addTask([&counter] {
        CHECK(counter++ == 0);
    });
}
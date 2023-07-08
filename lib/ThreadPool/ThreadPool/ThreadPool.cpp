#include <ThreadPool/ThreadPool.h>
#include <tuple>

namespace multithreads {
ThreadPool::ThreadPool() {
    stopFlag = false;
    for (int i = 0; i < std::thread::hardware_concurrency(); i++) {
        workers.emplace_back([this] {
            while (true) {
                std::function<void()> task;
                {
                    std::unique_lock<std::mutex> lock(qMutex);
                    cv.wait(lock, [this] { return stopFlag || !tasks.empty(); });
                    if (stopFlag && tasks.empty()) {
                        return;
                    }
                    task = std::move(tasks.front());
                    tasks.pop();
                }
                task();
            }
        });
    }
}

ThreadPool::~ThreadPool() {
    stop();
}

void ThreadPool::stop() {
    stopFlag = true;  
    cv.notify_all();
}

void ThreadPool::addTask(std::function<void()> task) {
    {
        std::lock_guard lock(qMutex);
        tasks.push(task);
    }
    cv.notify_one();
}
} // namespace multithreads
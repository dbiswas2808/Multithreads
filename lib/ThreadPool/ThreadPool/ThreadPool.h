#include <atomic>
#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

namespace multithreads {

class ThreadPool {
public:
    ThreadPool();
    ~ThreadPool();
    void addTask(std::function<void()> task);
    void stop();
private:
    std::vector<std::jthread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex qMutex;
    std::condition_variable cv;
    std::atomic_bool stopFlag;
};
} // namespace multithreads
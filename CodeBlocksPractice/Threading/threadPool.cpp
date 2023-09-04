#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>

class ThreadPool {
public:
    ThreadPool(size_t numThreads) : stop(false) {
        for (size_t i = 0; i < numThreads; ++i) {
            workers.emplace_back([this] {
                while (true) {
                    std::function<void()> task;

                    {
                        std::unique_lock<std::mutex> lock(queueMutex);
                        condition.wait(lock, [this] { return stop || !tasks.empty(); });

                        if (stop && tasks.empty()) {
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

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            stop = true;
        }

        condition.notify_all();

        for (std::thread& worker : workers) {
            worker.join();
        }
    }

    // Specialization for functions taking an int argument
    template <class F>
    void enqueue(F&& f, int arg) {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            tasks.emplace([=] { f(arg); });
        }

        condition.notify_one();
    }

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;
};


// A function to be executed in the thread pool
void myFunction(int arg) {
    std::cout << "Task " << arg << " is running in thread " << std::this_thread::get_id() << std::endl;
}

int main() {
    ThreadPool pool(8); // Create a thread pool with 4 worker threads

    for (int i = 0; i < 10000; ++i) {
        pool.enqueue(myFunction, i);
    }

    // The tasks will be executed concurrently by the worker threads in the pool

    // Ensure all tasks are completed before exiting
    // The ThreadPool destructor will wait for all threads to finish
    return 0;
}

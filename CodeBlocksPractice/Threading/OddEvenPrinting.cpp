#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;
int count = 1;

void printOdd() {
    while (count <= 100) {
        m.lock();
        if (count % 2 == 1) {
            std::cout << count << " ";
            count++;
        }
        m.unlock();
    }
}

void printEven() {
    while (count <= 100) {
        m.lock();
        if (count % 2 == 0) {
            std::cout << count << " ";
            count++;
        }
        m.unlock();
    }
}

int main() {
    std::thread oddThread(printOdd);
    std::thread evenThread(printEven);

    oddThread.join();
    evenThread.join();

    return 0;
}

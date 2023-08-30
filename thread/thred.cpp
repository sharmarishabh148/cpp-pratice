#include <thread>
#include <iostream>
#include <mutex>

using namespace std;

typedef unsigned long long ull;

ull OddSum = 0;
ull EvenSum = 0;

std::mutex mOddSum;
std::mutex mEvenSum;

void findEven(ull start, ull end) {
    for (ull i= start ; i <= end; i++){
        if ((i&1) == 0){
            mEvenSum.lock();
            EvenSum += i;
            mEvenSum.unlock();
        }
    }
}


void findOdd(ull start, ull end) {
    for (ull i= start ; i <= end; i++){
        if ((i&1) == 0){
            mOddSum.lock(); // if (mOddSum.try_lock())
            OddSum += i;
            mOddSum.unlock();
        }
    }
}

int main(){
    ull start = 0, end= 1900000;
    findOdd(start, end);
    findEven(start, end);

    cout << "OddSum   " << OddSum << endl;
    cout << "EvenSum " << EvenSum << endl;




    std::thread t1(findEven, start, end);
    std::thread t2(findOdd, start, end);



    t1.join();
    t2.join();



    return 0;
}

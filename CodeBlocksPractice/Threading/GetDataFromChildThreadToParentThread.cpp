#include<iostream>
#include<future>
#include<thread>
using namespace std;

void factorial(int number, int& getResult)
{
    int result = 1;
    for(int index = number ; index >= 1; index--)
    {
        result *= index;
    }
    getResult = result;
}

int main()
{
    int getResult;
    thread t1(factorial, 4, std::ref(getResult) );
    t1.join();

    cout<< getResult;
    return 0;
}



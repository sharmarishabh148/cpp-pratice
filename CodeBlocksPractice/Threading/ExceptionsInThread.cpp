#include <iostream>
#include <thread>
using namespace std;

void hello()
{
    cout<<"welcome to C++ multithreading";
}

void foo()
{
    thread t1(hello);
    try
    {
    //Do some work here;
    }
    catch(...)
    {
        t1.join();
        throw;
    }

    t1.join();
}
/*
we can solve that issue, with try catch block.
*/


class ThreadWrapper
{
    thread t;
    public:
        ThreadWrapper(thread&& t): t(std::move(t)){}
        ~ThreadWrapper()
        {
            if (t.joinable()){
                t.join();
            }
        }
};

void foo1()
{
    // USE RAII
    thread t1(hello);
    ThreadWrapper w(std::move(t1));
}
int main(int argc, char **argv)
{
    foo();
    foo1();
    return 0;
}

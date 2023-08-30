#include <bits/stdc++.h>

using namespace std;

void hello()
{
    cout << "Welcome to c++ multithreading" <<endl;
}
void hello_by_thread01()
{
    cout<<"welcome to C++ multithreading, through thread 01";
}
void hello_by_thread02()
{
    cout<<endl<<"welcome to C++ multithreading, through thread 02";
}

int main()
{

    //cout << thread::hardware_concurrency() << endl;
    thread t1(hello);
    //t1.join(); // join means , main thread will wait for t1 to complete.
    t1.detach(); //introducing detach, now thread t1 is independent of main thread

    thread t01(hello_by_thread01);
    t01.join(); // join means, main thread will wait for t01 to complete.
    cout<< endl << "now in main thread from thread 01";

    thread t02(hello_by_thread02);
    t02.join(); // join means, main thread will wait for t02 to complete.
    cout<< endl << "now in main thread from thread 02";

    return 0;
}

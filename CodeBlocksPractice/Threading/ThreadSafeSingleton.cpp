#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::mutex m_lock;
std::once_flag m_flagOneTime;

class Singleton
{
public:
    static Singleton* GetInstanceNonSafe();
    static Singleton* GetInstanceWorse();
    static Singleton* GetInstanceDoubleLocking();
    static Singleton* GetInstanceUsingOnce();

private:
    //zero argument default constructor.
    Singleton(){}
    //Copy constructor.
    Singleton(Singleton &){}
    // overloaded assignment operator.
    const Singleton& operator = (Singleton &){}
    // single pointer which will get refereed in all the places.
    static Singleton *mp_singleton;

};

Singleton* Singleton::mp_singleton = NULL;

Singleton* Singleton::GetInstanceNonSafe()
{
    if(mp_singleton == NULL){
        unique_lock<mutex> lockMutex(m_lock);
        mp_singleton = new Singleton();
        return mp_singleton;
    }
    return mp_singleton;
}

Singleton* Singleton::GetInstanceWorse()
{
    // Now  every thread will come and lock it.
    unique_lock<mutex> lockMutex(m_lock);
    if(mp_singleton == NULL){
        mp_singleton = new Singleton();
        return mp_singleton;
    }
    return mp_singleton;
}

Singleton* Singleton::GetInstanceDoubleLocking()
{
    if(mp_singleton == NULL)
    {
        unique_lock<mutex> lockMutex(m_lock);
        if(mp_singleton == NULL) // check same condition again
        {
            mp_singleton = new Singleton;
        }
    }
    return mp_singleton;
}

Singleton* Singleton::GetInstanceUsingOnce()
{
    std::call_once(m_flagOneTime, [&]()
                                    {
                                        mp_singleton = new Singleton;
                                    }
                    );
    return mp_singleton;
}

void doSomeWork()
{
    Singleton *ptr1 = Singleton::GetInstance();
    cout<<"Address of pointer one is          - "<< &ptr1 <<endl;
    cout<<"Address of pointer Singleton pointer from pointer one is   - "<< &(*ptr1) <<endl;
}

int main(int argc, char ** argv)
{
    thread t1(doSomeWork);
    t1.join();
    thread t2(doSomeWork);
    t2.join();
    return 0;
}

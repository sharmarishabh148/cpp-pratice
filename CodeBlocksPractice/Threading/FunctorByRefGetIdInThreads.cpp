#include <iostream>
#include <thread>
using namespace std;

class PrintMe
{
    public:
        void operator()(string imput)
        {
            cout<<"Printing from thread"<<endl;
            cout<<"msg - "<< imput <<endl;
        }
};

class PrintMeRef
{
    public:
        void operator()(string& imput)
        {
            cout<<"Printing from thread"<<endl;
            cout<<"msg - "<< imput <<endl;
            imput = "changed" + imput;
        }
};

int main(int argc, char **argv)
{
    string s1 = "Hello child thread ";
    //thread t1((PrintMe()), s1);
    //t1.join();


    thread t2((PrintMeRef()), std::ref(s1));
    t2.join();
    cout << "s1 now :" << s1 << endl;
    return 0;
}

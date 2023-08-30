#include<iostream>
#include<memory>
#include<thread>
#include<mutex>
using namespace std;

class DB   // class responsible for all DB operation.
{
    public:
        void execute(const string& str)
        {
            //execute the sql in respective DB
        }
};
class DBConnection
{
    public:
        DBConnection()
        {
            //m_connection = new DB;
        }
        //execute your query
        void executeYourQuery(const string& str)
        {
            unique_lock<mutex> nowLockWithGuard(m_lock);
            m_connection ->execute(str);
            nowLockWithGuard.unlock();
            //After unlocking the mutex, now we can execute other logics
            //which we wanted to execute without mutex.
        }
    private:
        unique_ptr<DB> m_connection;
        std::mutex m_lock;
};

int main(int argc, char **argv)
{
    DBConnection connection;
    string input = "select * from emp;";
    connection.executeYourQuery(input);
    return 0;
}

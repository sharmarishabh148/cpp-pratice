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
            cout << "query :\n" << str <<"\nis executing on Db" << endl;
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

            nowLockWithGuard.lock();
            // we locked it again, execute some logic..
            // ...
            nowLockWithGuard.unlock();
            // we unlocked it gain.

            unique_lock<mutex> nowLockWithGuard02 = std::move(nowLockWithGuard);
            // this will move the ownership of mutex from nowLockWithGuard to
            // nowLockWithGuard02, which is not possible in lock_guard<>
        }
    private:
        unique_ptr<DB> m_connection;
        std::mutex m_lock;
};

int main(int argc, char **argv)
{
    /*
    we cannot use Unique_lock in every condition is because it is a weighted object.
    Though it provide many flexibility, it is heavy object, use it all over the
    place will slow down the performance. lock_guard gives very less flexibility but
    for light weight application it is the best choice.
    */
    DBConnection connection;
    string input = "select * from emp;";
    connection.executeYourQuery(input);
    return 0;
}

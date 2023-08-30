#include <bits/stdc++.h>

// day2 for STL.
using namespace std;
int main()
{
    // SEt.
    set<int> st;
    int arr [] = {2, 5, 1, 2 , 5, 7};

    for (auto i: arr)
    {
        st.insert(i);
    }
    for (auto i: st)
    {
        cout << i << " ";
    }
    cout << "\nset" << endl;

    st.erase(st.begin());
    st.erase(5); // key


    auto it = st.find(7); // log n
    if (it != st.end()){
        cout << "found" << endl;
    }



    //UNORDERED<set>

    unordered_set<int> dictionary;
    // average time complexity is o(1)
    // bit the worst case is linear in nature, o(Set size)


    //Multiset
    multiset<int> ms;

    ms.insert(1);
    ms.insert(1);
    ms.insert(1);

    ms.insert(2);
    ms.insert(2);

    //function are similar to set and logn complexity


    // Key value
    map<string, int> mpp;
    mpp["raj"] = 27;

    mpp.emplace("hi", 20);
    // mpp.empty()
    // find erase

    for(auto it:mpp)
    {
        cout << it.first << " " << it.second << endl;
    }

    //UNORDERED MAP
    unordered_map<int, int> mp;


    // pair

    pair<pair<int,int>, pair<int, int>> pr = {{1,2}, {2,4}};


    //multimap
    multimap<string, int> mmp;
    mmp.emplace("raj", 2);
    mmp.emplace("raj", 5);

    for(auto it:mmp)
    {
        cout << it.first << " " << it.second << endl;
    }
    //Stack
    stack<int> sta;
    sta.push(2);
    sta.push(4);

    cout << sta.top() << endl;
    sta.pop();
    cout << sta.top() << endl;


    while (!sta.empty()){
        sta.pop();
    }
    if (!sta.empty())
        cout << sta.top() << endl;



    // Queue Data Stucture.

    queue<int> q;
    q.push(1);
    q.push(5);
    q.push(3);
    q.push(6);


    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;

    while (!q.empty()){
        q.pop();
    } // everythn is a o(1)

    // priority_queue
    // stores all m sorted order -> log N
    priority_queue<int> pq;
    pq.push(1);
    pq.push(5);
    pq.push(2);
    pq.push(4);

    cout <<"priority_queue" << endl;
    cout << pq.top()<< endl;
    pq.pop();
    cout << pq.top() <<endl;


    // minHeap
    priority_queue< int, vector<int>, greater<int>> mpq;



    // Dequeue

    deque<int> dq;


    list<int>ls;

    return 0;
}

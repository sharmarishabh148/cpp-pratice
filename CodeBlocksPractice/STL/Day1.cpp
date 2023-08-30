#include <bits/stdc++.h>

// When You Have Struct better define a constructor

// Use OF Std namespace .

// Array container
using namespace std;

// container arrays
array<int, 100> arr;




int main(){
    cout << arr.at(0) << endl;

    // iterators
    // begin(), end(), rbegin(), rend()

    array<int, 5> ar = {1, 3, 4, 5, 6};
    for(auto it= ar.begin(); it!=ar.end();it++) {
		cout << *it << " ";
	}
    cout << endl;

    // traverse on the itself
	for (auto i : ar){// for each loop
        cout << i  << " ";
	}

	// arr.size(), arr.front(), arr.back()

    // Maximum pow(10, 6) inside main
    // Maximum pow(10, 7) inside main
    // outside --> segmentation fault.

    // Vector
    vector<int> vec;
    vec.push_back(0);
    vec.pop_back();

    vec.clear();// erase all the elements at once.

    vector<int> vec1(4,0);
    vector<int> vec2(4,10);

    vector<int> vec3(vec2.begin(), vec2.end());
    vector<int> vec4(vec2);

    vector< vector<int>> vec2d;
    vec2d.push_back(vec3);
    vec2d.push_back(vec2);

    cout <<endl;
    for (auto v2 : vec2d)
    {
        for (auto v: v2)
        {
            cout << v <<" ";
        }
        cout <<endl;
    }

    // 2 loops with vec[i][j].

    // define 10 X 20
    vector<vector<int>> vec10By20(10, vector<int> (20,0));
    vec10By20[2].push_back(1);

    vector<int> arrOfVector[4];
    arrOfVector[1].push_back(0);
}

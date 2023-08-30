#include <bits/stdc++.h>
using namespace std;
int partition(vector < int > & arr, int s, int e) {
    int pivot = arr[s];
    int cnt = 0;
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) {
            cnt++;
        }
    }
    //place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);
    //left and right part
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}

void solve(vector < int > & arr, int s, int e) {
    if (s >= e) {
        return;
    }
    //partition
    int p = partition(arr, s, e);
    //left part sorting
    solve(arr, s, p - 1);
    //right part sorting
    solve(arr, p + 1, e);
}

vector < int > quickSort(vector < int > arr) {
    solve(arr, 0, arr.size() - 1);
    return arr;
}

int main(){
    vector < int > v{1,8,5,6,7,4};
    v=quickSort(v);
    for(auto i: v)
        cout << i << " ";
    cout <<endl;
}

#include <bits/stdc++.h>

using namespace std;

int findIndexInRotatedArray(int arr[], int n);
int find_first_Occurence(int arr[], int n , int x )
{
    // When we find mid== x, then need to again search in left half
    int start= 0;
    int end = n-1;

    int ans = -1;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if (arr[mid] == x ){
            ans = mid;
            end = mid -1;
        }
        else if (arr[mid] > x){
            end = mid -1;
        }else if(arr[mid] < x){
            start = mid+1;
        }

    }
    return ans;
}
int find_last_Occurence(int arr[], int n , int x )
{
    // When we find mid== x, then need to again search in right half
    int start= 0;
    int end = n-1;

    int ans = -1;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if (arr[mid] == x ){
            ans = mid;
            start = mid +1;
        }
        else if (arr[mid] > x){
            end = mid -1;
        }else if(arr[mid] < x){
            start = mid+1;
        }

    }
    return ans;

}


int binarySearch (int arr[], int size, int key)
{
    int start= 0;
    int end = size-1;


    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if (arr[mid] ==key ){
            return mid;
        }
        if (arr[mid] > key){
            // left half
            end = mid -1;
        }else{
            start = mid+1;
        }

    }
    return -1;

}

int binarySearch (int arr[], int start, int end, int key)
{
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if (arr[mid] ==key ){
            return mid;
        }
        if (arr[mid] > key){
            // left half
            end = mid -1;
        }else{
            start = mid+1;
        }

    }
    return -1;

}

int SearchInRotatedArray(vector<int> vec, int K) {

    int s = 0;
    int e = vec.size() -1;
    int pivot = findIndexInRotatedArray(vec, e+1);
    if(K >= vec[pivot] && K <=vec[e]){
        // second half normal binary search
        return binarySearch(vec, pivot, e, K);
    }else{
        return binarySearch(vec, s, pivot-1, K);
    }
}


nt peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size()-1;

        while (start < end)
        {
            int mid = start + (end - start)/2;
            /*    /\
                 /  \
                /    \
            */
            if (arr[mid]< arr[mid+1]){
                start = mid+1;
            }else{
                end = mid;
            }

        }
        return start;
}


int findMinInRotatedArray(int arr[], int n){
        //complete the function here
        /*
           /
          /        /n-1 index
         /        /
    0th /        /
                /
        */
        // ist line arr[mid] >= arr[0] s = mid +1

        // else e = mid

        int s = 0;
        int e = n-1;
        // Handle the case where the array is not rotated
        if (arr[s] < arr[e]) {
            return arr[s];
        }
        while(s<e){
            int mid = s + (e - s)/2;
            if (arr[mid] >= arr[0]){
                s = mid +1;
            }else{
                e = mid ;
            }
        }
    return arr[s];
}

int findIndexInRotatedArray(int arr[], int n){
        //complete the function here
        /*
           /
          /        /n-1 index
         /        /
    0th /        /
                /
        */
        // ist line arr[mid] >= arr[0] s = mid +1

        // else e = mid

        int s = 0;
        int e = n-1;
        // Handle the case where the array is not rotated
        if (arr[s] < arr[e]) {
            return s;
        }
        while(s<e){
            int mid = s + (e - s)/2;
            if (arr[mid] >= arr[0]){
                s = mid +1;
            }else{
                e = mid ;
            }
        }
    return s;
}

 int SquareRoot(int N) {
        // code here

    int s = 0;
    int e = N;

    int ans = -1;
    while (s<e){
        int mid = s + (e-s)/2;
        long long int sqaure = mid * mid;
        cout << "s "<< s<< endl;
        cout << "e "<< e << endl;
        if (sqaure == N){
            ans = mid-1;
        }
        if (sqaure < N){
            // go right side.
            ans = mid;
            s = mid +1;
        }else{
            e = mid - 1;
        }
    }
    return ans;
}


int main(){

    int even[] = {2, 4, 6, 8, 10, 12};
    int odd[]  = {1, 3, 5, 7, 9, 11};

    cout << "Index of 12 is "<<binarySearch(even, 6, 12) << endl;

    return 0;
}

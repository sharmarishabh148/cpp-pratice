#include <bits/stdc++.h>
using namespace std;


void show_mem_rep(char *start, int n)
{
    int i;
    for (i = 0; i < n; i++)
         printf(" %.2x", start[i]);
    printf("\n");
}

void checkMachine(){
    unsigned int i = 1;
    char *c = (char*)&i;
    if (*c)
        cout<<"Little endian";
    else
        cout<<"Big endian";
}

int swap_Endians(int value)
{
    int leftmost_byte, left_middle_byle, right_middle_byte, rightmost_byte;
    int result;

    leftmost_byte       = (value & 0x000000FF) >> 0;
    left_middle_byle    = (value & 0x0000FF00) >> 8;
    right_middle_byte   = (value & 0x00FF0000) >> 16;
    rightmost_byte      = (value & 0xFF000000) >> 24;

    // Left shift the 8 bits by 24 so that it is shifted to the leftmost end
    leftmost_byte       <<= 24;
    left_middle_byle    <<= 16;
    right_middle_byte   <<= 8;
    rightmost_byte      <<= 0;
 
    // Result is the concatenation of all these values.
    result = (leftmost_byte | left_middle_byle |
              right_middle_byte | rightmost_byte);
    return result;
}

int findMissingNumber(vector<int> &arr) {
    int n = arr.size() + 1;
    // find sum of all numbers from 1 to n.
    int s1 = 0;
    for (int i = 1; i <= n; i++)
      s1 += i;

    // subtract all numbers in input from sum.
    for (int num : arr)
      s1 -= num;

    // s1, now, is the missing number
    return s1;
}

int main()
{
    checkMachine();
    int i = 0x01234567;
    show_mem_rep((char *)&i, sizeof(i));
    
    cout << "Actual i :0x" <<  std::setfill('0') << std::hex<< i << endl;
    cout << std::hex<< swap_Endians(i) << endl;

    /*vector<int> v1 = {1, 5, 2, 6, 4};
    cout << "Missing Number is :: "<< findMissingNumber(v1)<< endl;*/
    return 0;
}
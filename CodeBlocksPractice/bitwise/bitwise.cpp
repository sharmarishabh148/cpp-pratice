#include <iostream>
using namespace std;

// Sets even bits of n and returns
// modified number.
int evenbitsetnumber(int n)
{
    // Generate 101010...10 number and
    // store in res.
    int count = 0, res = 0;
    for (int temp = n; temp > 0; temp >>= 1) {

        // if bit is even then generate
        // number and or with res
        if (count % 2 == 1)
            res |= (1 << count);

        count++;
    }

    // return OR number
    return (n | res);
}

int main()
{
    int n = 20;
    cout << evenbitsetnumber(n);
    return 0;
}

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isMatching(char top, char c){
    if (c == ')' && top != '(') {
        return false;
    } else if (c == ']' && top != '[') {
        return false;
    } else if (c == '}' && top != '{') {
        return false;
    }
    return true;
}
bool isBalanced(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) {
                return false;
            }
            if(!isMatching (st.top(), c)){
                return false;
            } else {
                //keep matching
                st.pop();
            }
        }
    }
    return st.empty();
}

int main() {
    string s;
    cout << "Enter a string with parentheses: ";
    cin >> s;
    if (isBalanced(s)) {
        cout << "The parentheses in the string are balanced." << endl;
    } else {
        cout << "The parentheses in the string are not balanced." << endl;
    }
    return 0;
}

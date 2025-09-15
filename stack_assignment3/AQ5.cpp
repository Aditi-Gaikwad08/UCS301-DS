#include <iostream>
#include <stack>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;

    for (char c : exp) {
        if (isdigit(c))
            st.push(c - '0');
        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            switch (c) {
            case '+': st.push(val1 + val2); break;
            case '-': st.push(val1 - val2); break;
            case '*': st.push(val1 * val2); break;
            case '/': st.push(val1 / val2); break;
            }
        }
    }
    return st.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression (digits only): ";
    cin >> postfix;

    cout << "Result = " << evaluatePostfix(postfix) << endl;
    return 0;
}

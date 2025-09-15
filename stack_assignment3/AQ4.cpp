#include <iostream>
#include <stack>
using namespace std;

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return -1;
}

string infixToPostfix(string s) {
    stack<char> st;
    string result = "";

    for (char c : s) {
        if (isalnum(c)) result += c; 
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); 
        } else { 
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
    return 0;
}

#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
    stack<int> st;
    int minEle;
public:
    void push(int x) {
        if (st.empty()) {
            st.push(x);
            minEle = x;
        } else if (x >= minEle) {
            st.push(x);
        } else {
            st.push(2*x - minEle); 
            minEle = x;
        }
    }

    void pop() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        int top = st.top(); st.pop();
        if (top < minEle) {
            
            minEle = 2*minEle - top;
        }
    }

    int top() {
        if (st.empty()) return -1;
        int t = st.top();
        return (t < minEle) ? minEle : t;
    }

    int getMin() {
        if (st.empty()) return -1;
        return minEle;
    }

    bool isEmpty() {
        return st.empty();
    }
};

int main() {
    SpecialStack s;
    s.push(3);
    s.push(5);
    cout << "Min: " << s.getMin() << endl; 
    s.push(2);
    s.push(1);
    cout << "Min: " << s.getMin() << endl; 
    s.pop();
    cout << "Min: " << s.getMin() << endl; 
    s.pop();
    cout << "Top: " << s.top() << endl;   
    cout << "Min: " << s.getMin() << endl; 
    return 0;
}

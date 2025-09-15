#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;
public:
    void push(int x) {
        q1.push(x);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack empty\n";
            return;
        }
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        cout << q1.front() << " popped\n";
        q1.pop();
        swap(q1, q2);
    }

    void top() {
        if (q1.empty()) {
            cout << "Stack empty\n";
            return;
        }
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        cout << "Top: " << q1.front() << endl;
        q2.push(q1.front());
        q1.pop();
        swap(q1, q2);
    }
};

int main() {
    Stack s;
    int ch, x;
    do {
        cout << "\n1.Push 2.Pop 3.Top 4.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> x; s.push(x); break;
            case 2: s.pop(); break;
            case 3: s.top(); break;
        }
    } while (ch != 4);
    return 0;
}

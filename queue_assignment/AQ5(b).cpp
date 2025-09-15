#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int n = q.size();
        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack empty\n";
            return;
        }
        cout << q.front() << " popped\n";
        q.pop();
    }

    void top() {
        if (q.empty()) {
            cout << "Stack empty\n";
        } else {
            cout << "Top: " << q.front() << endl;
        }
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

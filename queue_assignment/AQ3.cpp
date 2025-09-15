#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int> &q) {
    int n = q.size();
    queue<int> first, second;

    for (int i = 0; i < n / 2; i++) {
        first.push(q.front());
        q.pop();
    }
    while (!q.empty()) {
        second.push(q.front());
        q.pop();
    }

    while (!first.empty() && !second.empty()) {
        q.push(first.front()); first.pop();
        q.push(second.front()); second.pop();
    }
}

int main() {
    queue<int> q;
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }

    interleave(q);

    cout << "Interleaved: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}

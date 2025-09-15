#include <iostream>
#include <queue>
#include <map>
using namespace std;

void firstNonRepeat(string s) {
    map<char,int> freq;
    queue<char> q;

    for (char c : s) {
        freq[c]++;
        q.push(c);

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    firstNonRepeat(s);
    return 0;
}

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& t) {
    int n = t.size();
    vector<int> ans(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && t[i] > t[st.top()]) {
            int idx = st.top();
            st.pop();
            ans[idx] = i - idx;
        }
        st.push(i);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    vector<int> ans = dailyTemperatures(t);
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}

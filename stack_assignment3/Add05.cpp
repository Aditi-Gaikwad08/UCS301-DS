#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

bool canBeSorted(vector<int>& A) {
    int n = A.size();
    vector<int> sortedA = A;
    sort(sortedA.begin(), sortedA.end());

    stack<int> st;
    int j = 0;

    for (int i = 0; i < n; i++) {
        st.push(A[i]);
        while (!st.empty() && st.top() == sortedA[j]) {
            st.pop();
            j++;
        }
    }
    return j == n;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    if (canBeSorted(A))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

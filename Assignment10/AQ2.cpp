#include <iostream>
#include <unordered_set>
using namespace std;

void printCommonElements(int A[], int n, int B[], int m) {
    unordered_set<int> s;   // to store elements of A

    for (int i = 0; i < n; i++) {
        s.insert(A[i]);
    }

    cout << "Common elements: ";
    for (int j = 0; j < m; j++) {
        if (s.find(B[j]) != s.end()) {
            cout << B[j] << " ";
            // Optional: erase to avoid printing duplicates multiple times
            s.erase(B[j]);
        }
    }
    cout << endl;
}

int main() {
    int A[] = {1, 2, 3, 4};
    int B[] = {3, 4, 5, 6};

    int n = 4, m = 4;

    printCommonElements(A, n, B, m);

    return 0;
}

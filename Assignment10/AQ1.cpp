#include <iostream>
#include <unordered_set>
using namespace std;

bool containsDuplicate(int nums[], int n) {
    unordered_set<int> s;   // hash set

    for (int i = 0; i < n; i++) {
        // if element already present, then duplicate exists
        if (s.find(nums[i]) != s.end()) {
            return true;
        }
        s.insert(nums[i]);
    }
    return false;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int n = 4;

    if (containsDuplicate(nums, n))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}

#include <iostream>
#include <unordered_map>
using namespace std;

int firstNonRepeating(int nums[], int n) {
    unordered_map<int, int> freq;

    // 1st pass: count frequencies
    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }

    // 2nd pass: find first element with frequency 1
    for (int i = 0; i < n; i++) {
        if (freq[nums[i]] == 1) {
            return nums[i];
        }
    }

    // if no non-repeating element
    return -1;
}

int main() {
    int nums[] = {4, 5, 1, 2, 0, 4};
    int n = 6;

    int ans = firstNonRepeating(nums, n);
    if (ans != -1)
        cout << ans << endl;
    else
        cout << "No non-repeating element\n";

    return 0;
}

#include <iostream>
#include <unordered_map>
using namespace std;

void printFrequencies(int nums[], int n) {
    unordered_map<int, int> freq;   // number -> count

    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }

    for (auto it : freq) {
        cout << it.first << " -> " << it.second << " times" << endl;
    }
}

int main() {
    int nums[] = {2, 3, 2, 4, 3, 2};
    int n = 6;

    printFrequencies(nums, n);

    return 0;
}

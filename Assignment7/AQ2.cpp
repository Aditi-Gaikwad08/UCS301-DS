#include <iostream>
#include <vector>
using namespace std;

void improvedSelectionSort(vector<int>& a) {
    int left = 0, right = a.size() - 1;

    while(left < right) {
        int minIndex = left, maxIndex = right;

        if(a[minIndex] > a[maxIndex])
            swap(minIndex, maxIndex);

        for(int i = left+1; i < right; i++) {
            if(a[i] < a[minIndex]) minIndex = i;
            if(a[i] > a[maxIndex]) maxIndex = i;
        }

        swap(a[left], a[minIndex]);

        if(maxIndex == left)
            maxIndex = minIndex;

        swap(a[right], a[maxIndex]);

        left++;
        right--;
    }
}

int main() {
    vector<int> arr = {7, 3, 9, 1, 5, 2};
    improvedSelectionSort(arr);

    for(int x : arr) cout << x << " ";
}

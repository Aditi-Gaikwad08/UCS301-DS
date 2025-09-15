#include<iostream>
using namespace std;

int main() {
    int n, arr[100];
    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for(int i=0; i<n; i++) cin >> arr[i];

    int start = 0, end = n-1;
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    cout << "Reversed array: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    return 0;
}

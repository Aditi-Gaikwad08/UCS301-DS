#include <iostream>
using namespace std;

void heapifyMax(int a[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapifyMax(a, n, largest);
    }
}

void heapifyMin(int a[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && a[l] < a[smallest]) smallest = l;
    if (r < n && a[r] < a[smallest]) smallest = r;

    if (smallest != i) {
        swap(a[i], a[smallest]);
        heapifyMin(a, n, smallest);
    }
}

void heapSortIncreasing(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMax(a, n, i);

    for (int i = n-1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapifyMax(a, i, 0);
    }
}

void heapSortDecreasing(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMin(a, n, i);

    for (int i = n-1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapifyMin(a, i, 0);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {12, 11, 13, 5, 6, 7};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    heapSortIncreasing(arr1, n1);
    cout << "Heap sort (increasing): ";
    printArray(arr1, n1);

    heapSortDecreasing(arr2, n2);
    cout << "Heap sort (decreasing): ";
    printArray(arr2, n2);

    return 0;
}

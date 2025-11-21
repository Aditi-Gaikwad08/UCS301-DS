#include <iostream>
#include <vector>
using namespace std;

// Selection Sort
void selectionSort(vector<int>& a) {
    int n = a.size();
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        for(int j = i+1; j < n; j++) {
            if(a[j] < a[minIndex])
                minIndex = j;
        }
        swap(a[i], a[minIndex]);
    }
}

// Insertion Sort
void insertionSort(vector<int>& a) {
    int n = a.size();
    for(int i = 1; i < n; i++) {
        int key = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

// Bubble Sort
void bubbleSort(vector<int>& a) {
    int n = a.size();
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }
    }
}

// Merge Sort
void merge(vector<int>& a, int l, int mid, int r) {
    vector<int> left(a.begin()+l, a.begin()+mid+1);
    vector<int> right(a.begin()+mid+1, a.begin()+r+1);

    int i = 0, j = 0, k = l;
    while(i < left.size() && j < right.size()) {
        if(left[i] <= right[j]) a[k++] = left[i++];
        else a[k++] = right[j++];
    }
    while(i < left.size()) a[k++] = left[i++];
    while(j < right.size()) a[k++] = right[j++];
}

void mergeSort(vector<int>& a, int l, int r) {
    if(l < r) {
        int mid = (l+r)/2;
        mergeSort(a, l, mid);
        mergeSort(a, mid+1, r);
        merge(a, l, mid, r);
    }
}

// Quick Sort
int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[high]);
    return i+1;
}

void quickSort(vector<int>& a, int low, int high) {
    if(low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p-1);
        quickSort(a, p+1, high);
    }
}

// Utility
void print(vector<int>& a) {
    for(int x : a) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 6};

    // Example runs
    vector<int> a1 = arr;
    selectionSort(a1);
    cout << "Selection Sort: "; print(a1);

    vector<int> a2 = arr;
    insertionSort(a2);
    cout << "Insertion Sort: "; print(a2);

    vector<int> a3 = arr;
    bubbleSort(a3);
    cout << "Bubble Sort: "; print(a3);

    vector<int> a4 = arr;
    mergeSort(a4, 0, a4.size()-1);
    cout << "Merge Sort: "; print(a4);

    vector<int> a5 = arr;
    quickSort(a5, 0, a5.size()-1);
    cout << "Quick Sort: "; print(a5);
}

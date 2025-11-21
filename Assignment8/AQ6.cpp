#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> h;

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (h[parent] < h[i]) {
                swap(h[parent], h[i]);
                i = parent;
            } else break;
        }
    }

    void heapifyDown(int i) {
        int n = h.size();
        while (true) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            int largest = i;

            if (left < n && h[left] > h[largest]) largest = left;
            if (right < n && h[right] > h[largest]) largest = right;

            if (largest != i) {
                swap(h[i], h[largest]);
                i = largest;
            } else break;
        }
    }

public:
    void push(int x) {
        h.push_back(x);
        heapifyUp(h.size() - 1);
    }

    int top() {
        if (h.empty()) return -1;
        return h[0];
    }

    void pop() {
        if (h.empty()) return;
        h[0] = h.back();
        h.pop_back();
        if (!h.empty())
            heapifyDown(0);
    }

    bool empty() {
        return h.empty();
    }

    void print() {
        for (int x : h) cout << x << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap pq;
    pq.push(10);
    pq.push(5);
    pq.push(30);
    pq.push(20);

    cout << "Heap array: ";
    pq.print();

    cout << "Top element: " << pq.top() << endl;
    pq.pop();
    cout << "After one pop, top: " << pq.top() << endl;
    pq.pop();
    cout << "After second pop, top: " << pq.top() << endl;

    return 0;
}

#include <iostream>
using namespace std;
#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;
public:
    CircularQueue() {
        front = -1; rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == (rear + 1) % SIZE);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full\n";
        } else {
            if (front == -1) front = 0;
            rear = (rear + 1) % SIZE;
            arr[rear] = x;
            cout << x << " inserted\n";
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        } else {
            cout << arr[front] << " removed\n";
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % SIZE;
            }
        }
    }

    void peek() {
        if (isEmpty()) cout << "Queue empty\n";
        else cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) cout << "Queue empty\n";
        else {
            cout << "Queue: ";
            int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear) break;
                i = (i + 1) % SIZE;
            }
            cout << endl;
        }
    }
};

int main() {
    CircularQueue q;
    int ch, val;
    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.peek(); break;
            case 4: q.display(); break;
        }
    } while (ch != 5);
    return 0;
}

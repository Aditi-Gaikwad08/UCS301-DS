#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    Node *head;
    CircularLinkedList() {
        head = NULL;
    }

    void insertLast(int val) {
        Node *n = new Node(val);
        if (head == NULL) {
            head = n;
            n->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = n;
        n->next = head;
    }

    void display() {
        if (head == NULL) return;
        Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data;  
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertLast(20);
    cll.insertLast(100);
    cll.insertLast(40);
    cll.insertLast(80);
    cll.insertLast(60);

    cout << "Output: ";
    cll.display();

    return 0;
}

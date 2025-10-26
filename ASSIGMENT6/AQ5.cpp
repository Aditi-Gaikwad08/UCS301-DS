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

class LinkedList {
public:
    Node *head;
    LinkedList() {
        head = NULL;
    }

    void insertLast(int val) {
        Node *n = new Node(val);
        if (head == NULL) {
            head = n;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = n;
    }
    void makeCircular() {
        if (head == NULL) return;
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = head;
    }

    bool isCircular() {
        if (head == NULL)
            return false;

        Node *temp = head->next;
        while (temp != NULL && temp != head)
            temp = temp->next;

        return (temp == head);
    }
};

int main() {
    LinkedList list;

    list.insertLast(2);
    list.insertLast(4);
    list.insertLast(6);
    list.insertLast(7);
    list.insertLast(5);

    if (list.isCircular())
        cout << "Output: True" << endl;
    else
        cout << "Output: False" << endl;

    return 0;
}

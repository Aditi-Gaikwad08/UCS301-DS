#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d) {
        data = d;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node *head;
    DoublyLinkedList() { head = NULL; }

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
        n->prev = temp;
    }

    int size() {
        int count = 0;
        Node *temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

class CircularLinkedList {
public:
    Node *head;
    CircularLinkedList() { head = NULL; }

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

    int size() {
        if (head == NULL) return 0;
        int count = 1;
        Node *temp = head->next;
        while (temp != head) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;

    dll.insertLast(10);
    dll.insertLast(20);
    dll.insertLast(30);

    cll.insertLast(5);
    cll.insertLast(15);
    cll.insertLast(25);
    cll.insertLast(35);

    cout << "Size of Doubly Linked List: " << dll.size() << endl;
    cout << "Size of Circular Linked List: " << cll.size() << endl;

    return 0;
}

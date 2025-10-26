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

    void insertFirst(int val) {
        Node *n = new Node(val);
        if (head != NULL) {
            n->next = head;
            head->prev = n;
        }
        head = n;
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
        n->prev = temp;
    }

    void insertAfter(int key, int val) {
        Node *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node not found\n";
            return;
        }
        Node *n = new Node(val);
        n->next = temp->next;
        n->prev = temp;
        if (temp->next)
            temp->next->prev = n;
        temp->next = n;
    }

    void deleteNode(int key) {
        Node *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node not found\n";
            return;
        }
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;
    }

    bool search(int key) {
        Node *temp = head;
        while (temp) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node *temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class CircularLinkedList {
public:
    Node *head;
    CircularLinkedList() { head = NULL; }

    void insertFirst(int val) {
        Node *n = new Node(val);
        if (head == NULL) {
            n->next = n;
            head = n;
        } else {
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = n;
            n->next = head;
            head = n;
        }
    }

    void insertLast(int val) {
        Node *n = new Node(val);
        if (head == NULL) {
            n->next = n;
            head = n;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = n;
        n->next = head;
    }

    void insertAfter(int key, int val) {
        if (head == NULL) return;
        Node *temp = head;
        do {
            if (temp->data == key) {
                Node *n = new Node(val);
                n->next = temp->next;
                temp->next = n;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found\n";
    }

    void deleteNode(int key) {
        if (head == NULL) return;
        Node *temp = head, *prev = NULL;
        do {
            if (temp->data == key) {
                if (temp == head && temp->next == head) {
                    head = NULL;
                    delete temp;
                    return;
                }
                if (temp == head) {
                    Node *last = head;
                    while (last->next != head)
                        last = last->next;
                    head = head->next;
                    last->next = head;
                    delete temp;
                    return;
                } else {
                    prev->next = temp->next;
                    delete temp;
                    return;
                }
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found\n";
    }

    bool search(int key) {
        if (head == NULL) return false;
        Node *temp = head;
        do {
            if (temp->data == key)
                return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    void display() {
        if (head == NULL) {
            cout << "Empty list\n";
            return;
        }
        Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, ch2, val, key;

    while (true) {
        cout << "\n1. Doubly Linked List\n2. Circular Linked List\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            while (true) {
                cout << "Doubly Linked List\n";
                cout << "1.Insert First\n2.Insert Last\n3.Insert After\n4.Delete\n5.Search\n6.Display\n7.Back\nEnter: ";
                cin >> ch2;
                if (ch2 == 1) {
                    cout << "Data: "; cin >> val;
                    dll.insertFirst(val);
                } else if (ch2 == 2) {
                    cout << "Data: "; cin >> val;
                    dll.insertLast(val);
                } else if (ch2 == 3) {
                    cout << "After Node: "; cin >> key;
                    cout << "Data: "; cin >> val;
                    dll.insertAfter(key, val);
                } else if (ch2 == 4) {
                    cout << "Delete Node: "; cin >> key;
                    dll.deleteNode(key);
                } else if (ch2 == 5) {
                    cout << "Search: "; cin >> key;
                    cout << (dll.search(key) ? "Found\n" : "Not Found\n");
                } else if (ch2 == 6) {
                    dll.display();
                } else break;
            }
        } 
        else if (choice == 2) {
            while (true) {
                cout << "\nCircular Linked List\n";
                cout << "1.Insert First\n2.Insert Last\n3.Insert After\n4.Delete\n5.Search\n6.Display\n7.Back\nEnter: ";
                cin >> ch2;
                if (ch2 == 1) {
                    cout << "Data: "; cin >> val;
                    cll.insertFirst(val);
                } else if (ch2 == 2) {
                    cout << "Data: "; cin >> val;
                    cll.insertLast(val);
                } else if (ch2 == 3) {
                    cout << "After Node: "; cin >> key;
                    cout << "Data: "; cin >> val;
                    cll.insertAfter(key, val);
                } else if (ch2 == 4) {
                    cout << "Delete Node: "; cin >> key;
                    cll.deleteNode(key);
                } else if (ch2 == 5) {
                    cout << "Search: "; cin >> key;
                    cout << (cll.search(key) ? "Found\n" : "Not Found\n");
                } else if (ch2 == 6) {
                    cll.display();
                } else break;
            }
        } 
        else break;
    }
    return 0;
}

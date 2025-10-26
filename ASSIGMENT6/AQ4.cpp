#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node *next;
    Node *prev;
    Node(char d) {
        data = d;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node *head;

    DoublyLinkedList() {
        head = NULL;
    }

    void insertLast(char val) {
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

    bool isPalindrome() {
        if (head == NULL)
            return true;

        Node *left = head;
        Node *right = head;

        // Move right pointer to last node
        while (right->next)
            right = right->next;

        // Compare from both ends
        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
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

int main() {
    DoublyLinkedList dll;
    int n;
    char ch;

    cout << "Enter number of characters: ";
    cin >> n;

    cout << "Enter characters: ";
    for (int i = 0; i < n; i++) {
        cin >> ch;
        dll.insertLast(ch);
    }

    cout << "List: ";
    dll.display();

    if (dll.isPalindrome())
        cout << "Output: True" << endl;
    else
        cout << "Output: False" << endl;

    return 0;
}

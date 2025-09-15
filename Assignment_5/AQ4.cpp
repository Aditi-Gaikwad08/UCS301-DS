#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;
    
public:
    SinglyLinkedList() {
        head = nullptr;
    }
    
    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    // Display the linked list
    void displayList() {
        if (head == nullptr) {
            cout << "NULL" << endl;
            return;
        }
        
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << "->";
            } else {
                cout << "->NULL";
            }
            temp = temp->next;
        }
        cout << endl;
    }
    
    // Iterative approach to reverse the linked list
    void reverseList() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        
        while (current != nullptr) {
            next = current->next;  // store next node
            current->next = prev;  // reverse the link
            prev = current;        // move prev forward
            current = next;        // move current forward
        }
        head = prev;  // update head
    }
    
    // Destructor to free memory
    ~SinglyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList sll;
    
    cout << "=== Linked List Reversal ===" << endl;
    cout << "Creating linked list: 1->2->3->4->NULL" << endl;
    sll.insertAtEnd(1);
    sll.insertAtEnd(2);
    sll.insertAtEnd(3);
    sll.insertAtEnd(4);
    
    cout << "Original List: ";
    sll.displayList();
    
    cout << "Reversing the list..." << endl;
    sll.reverseList();
    
    cout << "Reversed List: ";
    sll.displayList();
    
    return 0;
}

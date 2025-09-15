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
            cout << "List is empty." << endl;
            return;
        }
        
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << "->";
            }
            temp = temp->next;
        }
        cout << endl;
    }
    
    // Find middle using two-pass approach
    int findMiddle() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return -1;
        }
        
        // First pass: count total nodes
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        
        // Second pass: move to middle node
        int middleIndex = count / 2;
        temp = head;
        for (int i = 0; i < middleIndex; i++) {
            temp = temp->next;
        }
        
        return temp->data;
    }
    
    void findAndDisplayMiddle() {
        cout << "Linked List: ";
        displayList();
        
        if (head == nullptr) return;
        
        int middle = findMiddle();
        cout << "Middle element: " << middle << endl;
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
    
    cout << "=== Example Test Case ===" << endl;
    cout << "Creating linked list: 1->2->3->4->5" << endl;
    sll.insertAtEnd(1);
    sll.insertAtEnd(2);
    sll.insertAtEnd(3);
    sll.insertAtEnd(4);
    sll.insertAtEnd(5);
    
    sll.findAndDisplayMiddle();
    
    cout << "\n=== Additional Test Cases ===" << endl;
    
    // Test with even number of elements
    SinglyLinkedList sll2;
    cout << "\nTest with even elements: 1->2->3->4" << endl;
    sll2.insertAtEnd(1);
    sll2.insertAtEnd(2);
    sll2.insertAtEnd(3);
    sll2.insertAtEnd(4);
    sll2.findAndDisplayMiddle();
    
    // Test with single element
    SinglyLinkedList sll3;
    cout << "\nTest with single element: 42" << endl;
    sll3.insertAtEnd(42);
    sll3.findAndDisplayMiddle();
    
    // Test with custom input
    cout << "\n=== Custom Input Test ===" << endl;
    SinglyLinkedList customList;
    int n, value;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    if (n > 0) {
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++) {
            cin >> value;
            customList.insertAtEnd(value);
        }
        
        cout << "\nCustom list result:" << endl;
        customList.findAndDisplayMiddle();
    } else {
        cout << "Invalid input. Number of elements should be positive." << endl;
    }
    
    return 0;
}

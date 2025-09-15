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
    
    // Insert at end (helper function to build the list)
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
    
    // Method 1: Two-pass approach (count nodes, then find middle)
    int findMiddleMethod1() {
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
        
        // Second pass: find middle node
        int middleIndex = count / 2;  // For 1-based indexing: (count / 2) + 1
        temp = head;
        for (int i = 0; i < middleIndex; i++) {
            temp = temp->next;
        }
        
        return temp->data;
    }
    
    // Method 2: Two-pointer approach (Tortoise and Hare algorithm)
    int findMiddleMethod2() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return -1;
        }
        
        Node* slow = head;    // Tortoise - moves one step at a time
        Node* fast = head;    // Hare - moves two steps at a time
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;        // Move slow pointer by 1
            fast = fast->next->next;  // Move fast pointer by 2
        }
        
        return slow->data;
    }
    
    // Find and display middle using both methods
    void findAndDisplayMiddle() {
        cout << "Linked List: ";
        displayList();
        
        if (head == nullptr) {
            return;
        }
        
        int middle1 = findMiddleMethod1();
        int middle2 = findMiddleMethod2();
        
        cout << "Middle element (Method 1 - Two Pass): " << middle1 << endl;
        cout << "Middle element (Method 2 - Two Pointer): " << middle2 << endl;
        
        // Note about even vs odd length
        Node* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        
        if (count % 2 == 0) {
            cout << "Note: List has even length (" << count << "). Returning the second middle element." << endl;
        } else {
            cout << "Note: List has odd length (" << count << "). Returning the exact middle element." << endl;
        }
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
    
    // Test with the given example: 1->2->3->4->5
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
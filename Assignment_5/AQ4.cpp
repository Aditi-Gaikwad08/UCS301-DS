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
    
    // Method 1: Iterative approach to reverse the linked list
    void reverseIterative() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        
        while (current != nullptr) {
            // Store next node
            next = current->next;
            
            // Reverse the link
            current->next = prev;
            
            // Move pointers one position ahead
            prev = current;
            current = next;
        }
        
        // Update head to point to the new first node
        head = prev;
    }
    
    // Method 2: Recursive approach to reverse the linked list
    Node* reverseRecursiveHelper(Node* node) {
        // Base case: if node is nullptr or last node
        if (node == nullptr || node->next == nullptr) {
            return node;
        }
        
        // Recursively reverse the rest of the list
        Node* newHead = reverseRecursiveHelper(node->next);
        
        // Reverse the current link
        node->next->next = node;
        node->next = nullptr;
        
        return newHead;
    }
    
    void reverseRecursive() {
        head = reverseRecursiveHelper(head);
    }
    
    // Method 3: Using stack (alternative approach)
    void reverseUsingStack() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        
        // Create an array to store node values (acting like a stack)
        const int MAX_NODES = 1000;
        int values[MAX_NODES];
        int count = 0;
        
        // Push all values to stack
        Node* temp = head;
        while (temp != nullptr && count < MAX_NODES) {
            values[count++] = temp->data;
            temp = temp->next;
        }
        
        // Pop values from stack and update nodes
        temp = head;
        for (int i = count - 1; i >= 0; i--) {
            temp->data = values[i];
            temp = temp->next;
        }
    }
    
    // Create a copy of the current list (for testing multiple methods)
    SinglyLinkedList createCopy() {
        SinglyLinkedList copy;
        Node* temp = head;
        while (temp != nullptr) {
            copy.insertAtEnd(temp->data);
            temp = temp->next;
        }
        return copy;
    }
    
    // Check if list is empty
    bool isEmpty() {
        return head == nullptr;
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
    
    // Test with the given example: 1->2->3->4->NULL
    cout << "=== Example Test Case ===" << endl;
    cout << "Creating linked list: 1->2->3->4->NULL" << endl;
    sll.insertAtEnd(1);
    sll.insertAtEnd(2);
    sll.insertAtEnd(3);
    sll.insertAtEnd(4);
    
    cout << "Original List: ";
    sll.displayList();
    
    // Test Method 1: Iterative
    SinglyLinkedList sll1 = sll.createCopy();
    cout << "\nMethod 1 - Iterative Reversal:" << endl;
    cout << "Before: ";
    sll1.displayList();
    sll1.reverseIterative();
    cout << "After:  ";
    sll1.displayList();
    
    // Test Method 2: Recursive
    SinglyLinkedList sll2 = sll.createCopy();
    cout << "\nMethod 2 - Recursive Reversal:" << endl;
    cout << "Before: ";
    sll2.displayList();
    sll2.reverseRecursive();
    cout << "After:  ";
    sll2.displayList();
    
    // Test Method 3: Using Stack concept
    SinglyLinkedList sll3 = sll.createCopy();
    cout << "\nMethod 3 - Stack-based Reversal:" << endl;
    cout << "Before: ";
    sll3.displayList();
    sll3.reverseUsingStack();
    cout << "After:  ";
    sll3.displayList();
    
    cout << "\n=== Additional Test Cases ===" << endl;
    
    // Test with single element
    SinglyLinkedList single;
    single.insertAtEnd(42);
    cout << "\nSingle element test:" << endl;
    cout << "Before: ";
    single.displayList();
    single.reverseIterative();
    cout << "After:  ";
    single.displayList();
    
    // Test with empty list
    SinglyLinkedList empty;
    cout << "\nEmpty list test:" << endl;
    cout << "Before: ";
    empty.displayList();
    empty.reverseIterative();
    cout << "After:  ";
    empty.displayList();
    
    // Custom input test
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
        
        cout << "\nCustom list reversal (using iterative method):" << endl;
        cout << "Original: ";
        customList.displayList();
        customList.reverseIterative();
        cout << "Reversed: ";
        customList.displayList();
    } else {
        cout << "Invalid input. Number of elements should be positive." << endl;
    }
    
    return 0;
}
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
    
    // Count occurrences of a key
    int countOccurrences(int key) {
        int count = 0;
        Node* temp = head;
        
        while (temp != nullptr) {
            if (temp->data == key) {
                count++;
            }
            temp = temp->next;
        }
        
        return count;
    }
    
    // Delete all occurrences of a key
    void deleteAllOccurrences(int key) {
        // Delete from the beginning if head nodes contain the key
        while (head != nullptr && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        
        // Delete from the rest of the list
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->data == key) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }
    
    // Count and delete all occurrences (main function for the problem)
    void countAndDeleteOccurrences(int key) {
        cout << "Original Linked List: ";
        displayList();
        
        int count = countOccurrences(key);
        cout << "Count of " << key << ": " << count << endl;
        
        deleteAllOccurrences(key);
        
        cout << "Updated Linked List: ";
        displayList();
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
    
    // Create the example linked list: 1->2->1->2->1->3->1
    cout << "Creating the linked list: 1->2->1->2->1->3->1" << endl;
    sll.insertAtEnd(1);
    sll.insertAtEnd(2);
    sll.insertAtEnd(1);
    sll.insertAtEnd(2);
    sll.insertAtEnd(1);
    sll.insertAtEnd(3);
    sll.insertAtEnd(1);
    
    int key = 1;
    cout << "\nKey to count and delete: " << key << endl;
    cout << "\n--- Results ---" << endl;
    sll.countAndDeleteOccurrences(key);
    
    cout << "\n--- Testing with custom input ---" << endl;
    SinglyLinkedList customList;
    int n, value;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        customList.insertAtEnd(value);
    }
    
    cout << "Enter the key to count and delete: ";
    cin >> key;
    
    cout << "\n--- Custom Results ---" << endl;
    customList.countAndDeleteOccurrences(key);
    
    return 0;
}
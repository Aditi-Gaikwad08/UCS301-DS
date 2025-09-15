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
    
    // (a) Insertion at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << "Node " << val << " inserted at the beginning." << endl;
    }
    
    // (b) Insertion at the end
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
        cout << "Node " << val << " inserted at the end." << endl;
    }
    
    // (c) Insertion in between (before or after a specific value)
    void insertBefore(int newVal, int targetVal) {
        if (head == nullptr) {
            cout << "List is empty. Cannot insert before " << targetVal << endl;
            return;
        }
        
        if (head->data == targetVal) {
            insertAtBeginning(newVal);
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != targetVal) {
            temp = temp->next;
        }
        
        if (temp->next == nullptr) {
            cout << "Node " << targetVal << " not found." << endl;
            return;
        }
        
        Node* newNode = new Node(newVal);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Node " << newVal << " inserted before " << targetVal << endl;
    }
    
    void insertAfter(int newVal, int targetVal) {
        Node* temp = head;
        while (temp != nullptr && temp->data != targetVal) {
            temp = temp->next;
        }
        
        if (temp == nullptr) {
            cout << "Node " << targetVal << " not found." << endl;
            return;
        }
        
        Node* newNode = new Node(newVal);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Node " << newVal << " inserted after " << targetVal << endl;
    }
    
    // (d) Deletion from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete from beginning." << endl;
            return;
        }
        
        Node* temp = head;
        head = head->next;
        cout << "Node " << temp->data << " deleted from beginning." << endl;
        delete temp;
    }
    
    // (e) Deletion from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete from end." << endl;
            return;
        }
        
        if (head->next == nullptr) {
            cout << "Node " << head->data << " deleted from end." << endl;
            delete head;
            head = nullptr;
            return;
        }
        
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        
        cout << "Node " << temp->next->data << " deleted from end." << endl;
        delete temp->next;
        temp->next = nullptr;
    }
    
    // (f) Deletion of a specific node
    void deleteSpecificNode(int val) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete node " << val << endl;
            return;
        }
        
        if (head->data == val) {
            deleteFromBeginning();
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }
        
        if (temp->next == nullptr) {
            cout << "Node " << val << " not found." << endl;
            return;
        }
        
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        cout << "Node " << val << " deleted." << endl;
        delete nodeToDelete;
    }
    
    // (g) Search for a node and display its position from head
    void searchNode(int val) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        
        Node* temp = head;
        int position = 1;
        
        while (temp != nullptr) {
            if (temp->data == val) {
                cout << "Node " << val << " found at position " << position << " from head." << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        
        cout << "Node " << val << " not found in the list." << endl;
    }
    
    // (h) Display all the node values
    void displayList() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        
        cout << "Linked List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << " -> NULL" << endl;
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

void displayMenu() {
    cout << "\n========== Singly Linked List Operations ==========" << endl;
    cout << "1. Insert at beginning" << endl;
    cout << "2. Insert at end" << endl;
    cout << "3. Insert before a specific node" << endl;
    cout << "4. Insert after a specific node" << endl;
    cout << "5. Delete from beginning" << endl;
    cout << "6. Delete from end" << endl;
    cout << "7. Delete a specific node" << endl;
    cout << "8. Search for a node" << endl;
    cout << "9. Display all nodes" << endl;
    cout << "10. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    SinglyLinkedList sll;
    int choice, value, target;
    
    do {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                sll.insertAtBeginning(value);
                break;
                
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                sll.insertAtEnd(value);
                break;
                
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter target value (insert before): ";
                cin >> target;
                sll.insertBefore(value, target);
                break;
                
            case 4:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter target value (insert after): ";
                cin >> target;
                sll.insertAfter(value, target);
                break;
                
            case 5:
                sll.deleteFromBeginning();
                break;
                
            case 6:
                sll.deleteFromEnd();
                break;
                
            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                sll.deleteSpecificNode(value);
                break;
                
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                sll.searchNode(value);
                break;
                
            case 9:
                sll.displayList();
                break;
                
            case 10:
                cout << "Exiting program..." << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        
    } while (choice != 10);
    
    return 0;
}
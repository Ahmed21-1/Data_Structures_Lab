#include <iostream>
#include <string>
using namespace std;

// Node Class for Linked List
class Node {
public:
    string orderID;
    Node* next;

    // Node Constructor
    Node(string id) {
        orderID = id;
        next = 0;
    }
};

// Stack Class using Singly Linked List
class restaurantStack {
private:
    Node* top;

public:
    // Constructor
    restaurantStack() {
        top = 0;
    }

    // Destructor to free memory
    ~restaurantStack() {
        while (top != 0) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // 1. PUSH operation
    void push(string id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
    }

    // 3. POP operation
    void pop() {
        if (top == 0) {
            cout << "Stack Underflow! No pending requests.\n";
            return;
        }
        Node* temp = top;
        cout << "Handled request: " << top->orderID << endl;
        top = top->next;
        delete temp;
    }

    // 4. Display TOP request
    void peek() {
        if (top == 0) {
            cout << "No pending requests.\n";
        } else {
            cout << "New TOP request: " << top->orderID << endl;
        }
    }

    // 2 & 5. Display all requests
    void display() {
        if (top == 0) {
            cout << "No pending requests!\n";
            return;
        }
        cout << "restaurant Requests (TOP to bottom):\n";
        Node* temp = top;
        while (temp != 0) {
            cout << "- " << temp->orderID << endl;
            temp = temp->next;
        }
    }
};

int main() {
    restaurantStack restaurant;

    // 1. Push patient request IDs
    restaurant.push("ord-101");
    restaurant.push("ord-102");
    restaurant.push("ord-103");
    restaurant.push("ord-104");

    // 2. Display all requests from TOP to bottom
    cout << "--- Initial Requests ---\n";
    restaurant.display();

    // 3. Perform one POP to handle latest request
    cout << "\n--- Handling Request ---\n";
    restaurant.pop();

    // 4. Display new TOP request
    cout << "\n--- Current Status ---\n";
    restaurant.peek();

    // 5. Display remaining requests
    cout << "\n--- Remaining Requests ---\n";
    restaurant.display();

    return 0;
}

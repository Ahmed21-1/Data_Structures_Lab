#include <iostream>
#include <string>
using namespace std;

// Node Class for Linked List
class Node {
public:
    string patientID;
    Node* next;

    // Node Constructor
    Node(string id) {
        patientID = id;
        next = 0;
    }
};

// Stack Class using Singly Linked List
class HospitalStack {
private:
    Node* top;

public:
    // Constructor
    HospitalStack() {
        top = 0;
    }

    // Destructor to free memory
    ~HospitalStack() {
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
        cout << "Handled request: " << top->patientID << endl;
        top = top->next;
        delete temp;
    }

    // 4. Display TOP request
    void peek() {
        if (top == 0) {
            cout << "No pending requests.\n";
        } else {
            cout << "New TOP request: " << top->patientID << endl;
        }
    }

    // 2 & 5. Display all requests
    void display() {
        if (top == 0) {
            cout << "No pending requests!\n";
            return;
        }
        cout << "Patient Requests (TOP to bottom):\n";
        Node* temp = top;
        while (temp != 0) {
            cout << "- " << temp->patientID << endl;
            temp = temp->next;
        }
    }
};

int main() {
    HospitalStack hospital;

    // 1. Push patient request IDs
    hospital.push("P101");
    hospital.push("P102");
    hospital.push("P103");
    hospital.push("P104");

    // 2. Display all requests from TOP to bottom
    cout << "--- Initial Requests ---\n";
    hospital.display();

    // 3. Perform one POP to handle latest request
    cout << "\n--- Handling Request ---\n";
    hospital.pop();

    // 4. Display new TOP request
    cout << "\n--- Current Status ---\n";
    hospital.peek();

    // 5. Display remaining requests
    cout << "\n--- Remaining Requests ---\n";
    hospital.display();

    return 0;
}

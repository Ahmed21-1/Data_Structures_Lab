#include <iostream>
#include <string>
using namespace std;

class TextEditorStack {
private:
    string arr[4];
    int top;
    int size;

public:
    TextEditorStack() {
        top = -1;
        size = 4;
    }

    void push(string action) {
        if (top == size - 1) {
            cout << "Stack Overflow!\n";
        } else {
            top++;
            arr[top] = action;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!\n";
        } else {
            cout << "Undone action: " << arr[top] << endl;
            top--;
        }
    }

    void peek() {
        if (top == -1) {
            cout << "No actions available.\n";
        } else {
            cout << "Current TOP action: " << arr[top] << endl;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty!\n";
        } else {
            cout << "Stack actions (TOP to bottom):\n";
            for (int i = top; i >= 0; i--) {
                cout << "- " << arr[i] << endl;
            }
        }
    }
};

int main() {
    TextEditorStack editor;

    // 1. Push actions
    editor.push("Type \"Hello\"");
    editor.push("Type \"World\"");
    editor.push("Add \"!\"");
    editor.push("Delete \"!\"");

    // 2. Display all actions from TOP to bottom
    cout << "--- Initial Stack ---\n";
    editor.display();

    // 3. Perform two POP operations (Simulate Undo)
    cout << "\n--- Performing 2 Undos ---\n";
    editor.pop();
    editor.pop();

    // 4. Display current TOP action
    cout << "\n--- Current Status ---\n";
    editor.peek();

    // 5. Display remaining actions
    cout << "\n--- Remaining Actions ---\n";
    editor.display();

    return 0;
}

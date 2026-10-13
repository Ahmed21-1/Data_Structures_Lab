#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    string arr[4];    // Array with size 4
    int top;          // Keeps track of TOP
    int size;         // Stores array size

public:
    // Constructor
    Stack()
    {
        top = -1;     // Stack is initially empty
        size = 4;     // Array size is 4
    }

    // PUSH: Add an element
    void push(string value)
    {
        // Check if stack is full
        if (top == size - 1)
        {
            cout << "Stack Overflow!\n";
        }
        else
        {
            top++;
            arr[top] = value;
            cout << value << " pushed into stack.\n";
        }
    }

    // POP: Remove the top element
    void pop()
    {
        // Check if stack is empty
        if (top == -1)
        {
            cout << "Stack Underflow! \n";
        }
        else
        {
            cout << arr[top] << " popped from stack.\n"; 
            top--;
        }
    }

    // PEEK: Display the top element
    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty\n";
        }
        else
        {
            cout << "Top element is: " << arr[top] << endl;
        }
    }

    // DISPLAY: Show all stack elements
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is Empty! \n"; 
        }
        else
        {
            cout << "Stack elements: ";
            // Display from TOP to bottom
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    // Check whether stack is empty
    bool isEmpty()
    {
        return top == -1;
    }
};

int main() {
    Stack s;

    // Insert elements
    s.push("google");
    s.push("youtube");
    s.push("fb");
    s.push("github");

    // Display all elements
    s.display();

    // Display top element
    s.peek();

    // Remove top element
    s.pop();

    // Display elements after POP
    s.display();

    return 0;
}

//1)uni dept task
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string val) {
        name = val;
        left = 0;
        right = 0;
    }
};

class DepartmentTree {
public:
    Node* root;

    DepartmentTree() {
        root = 0;
    }

    void displayHierarchy(Node* node) {
        if (node == 0) return;

        cout << "Member: " << node->name << endl;
        if (node->left)
            cout << "  |- Left Child: " << node->left->name << endl;
        else
            cout << "  |- Left Child: None" << endl;

        if (node->right)
            cout << "  |- Right Child: " << node->right->name << endl;
        else
            cout << "  |- Right Child: None" << endl;
        
        cout << "-----------------------------------" << endl;

        displayHierarchy(node->left);
        displayHierarchy(node->right);
    }

    void destroy(Node* node) {
        if (node == 0) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    ~DepartmentTree() {
        destroy(root);
    }
};

int main() {
    DepartmentTree dept;

    // Creating 7 nodes
    dept.root = new Node("Dr. Ali (HOD)");
    dept.root->left = new Node("Prof. Usman (Coord 1)");
    dept.root->right = new Node("Prof. Sara (Coord 2)");

    dept.root->left->left = new Node("Dr. Tariq (Faculty 1)");
    dept.root->left->right = new Node("Dr. Aisha (Faculty 2)");

    dept.root->right->left = new Node("Dr. Bilial (Faculty 3)");
    dept.root->right->right = new Node("Dr. Zain (Faculty 4)");

    cout << "=== UNIVERSITY DEPARTMENT HIERARCHY ===" << endl << endl;
    dept.displayHierarchy(dept.root);

    return 0;
}

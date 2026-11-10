//task 4 AVL tree balancing hospital appointment system
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int token;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        token = val;
        left = 0;
        right = 0;
        height = 1;
    }
};

class AVLTree {
private:
    Node* root;

    int getHeight(Node* n) {
        if (n == 0) return 0;
        return n->height;
    }

    int getBalance(Node* n) {
        if (n == 0) return 0;
        return getHeight(n->left) - getHeight(n->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, int token) {
        if (node == 0) return new Node(token);

        if (token < node->token)
            node->left = insert(node->left, token);
        else if (token > node->token)
            node->right = insert(node->right, token);
        else
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && token < node->left->token)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && token > node->right->token)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && token > node->left->token) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && token < node->right->token) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node* node) {
        if (node == 0) return;
        inorder(node->left);
        cout << node->token << " (Height: " << node->height << ", BF: " << getBalance(node) << ")\n";
        inorder(node->right);
    }

    void destroy(Node* node) {
        if (node == 0) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    AVLTree() { root = 0; }
    ~AVLTree() { destroy(root); }

    void insertToken(int token) {
        root = insert(root, token);
    }

    void display() {
        cout << "=== HOSPITAL APPOINTMENT SYSTEM (BALANCED AVL TREE) ===" << endl;
        cout << "In-Order Traversal with Node Height and Balance Factor:\n";
        inorder(root);
        cout << "\nRoot Token of Balanced Tree: " << (root ? root->token : -1) << endl;
    }
};

int main() {
    AVLTree hospitalTree;
    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    for (int t : tokens) {
        hospitalTree.insertToken(t);
    }

    hospitalTree.display();
    return 0;
}

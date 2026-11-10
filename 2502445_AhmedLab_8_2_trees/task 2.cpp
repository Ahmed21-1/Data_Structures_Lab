//task 2 E shopping(BFS)
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Node {
public:
    string category;
    Node* left;
    Node* right;

    Node(string val) {
        category = val;
        left = 0;
        right = 0;
    }
};

class ShoppingTree {
private:
    Node* root;

    void destroy(Node* node) {
        if (node == 0) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    ShoppingTree() { root = 0; }
    ~ShoppingTree() { destroy(root); }

    void createTree() {
        root = new Node("Electronics");
        root->left = new Node("Clothing");
        root->right = new Node("Mobiles");

        root->left->left = new Node("Laptops");
        root->left->right = new Node("Men");

        root->right->left = new Node("Women");
        root->right->right = new Node("Accessories");
    }

    void BFS() {
        if (root == 0) return;

        queue<Node*> q;
        q.push(root);

        cout << "BFS (Level-Order) Traversal of Categories:\n";
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            cout << "[" << current->category << "] ";

            if (current->left != 0) q.push(current->left);
            if (current->right != 0) q.push(current->right);
        }
        cout << endl;
    }
};

int main() {
    ShoppingTree store;
    store.createTree();
    store.BFS();
    return 0;
}

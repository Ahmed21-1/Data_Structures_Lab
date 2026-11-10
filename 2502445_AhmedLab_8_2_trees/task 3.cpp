//task 3 DFS
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string folderName;
    Node* left;
    Node* right;

    Node(string val) {
        folderName = val;
        left = 0;
        right = 0;
    }
};

class FileExplorer {
private:
    Node* root;

    void inorder(Node* node) {
        if (node == 0) return;
        inorder(node->left);
        cout << node->folderName << " -> ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == 0) return;
        cout << node->folderName << " -> ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == 0) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->folderName << " -> ";
    }

    void destroy(Node* node) {
        if (node == 0) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    FileExplorer() { root = 0; }
    ~FileExplorer() { destroy(root); }

    void buildExplorer() {
        root = new Node("Root_C:");
        root->left = new Node("Documents");
        root->right = new Node("Pictures");

        root->left->left = new Node("Assignments");
        root->left->right = new Node("Projects");

        root->right->left = new Node("Vacation");
        root->right->right = new Node("Screenshots");
    }

    void showDFS() {
        cout << "--- IN-ORDER TRAVERSAL (Left -> Root -> Right) ---" << endl;
        inorder(root);
        cout << "END\n\n";

        cout << "--- PRE-ORDER TRAVERSAL (Root -> Left -> Right) ---" << endl;
        preorder(root);
        cout << "END\n\n";

        cout << "--- POST-ORDER TRAVERSAL (Left -> Right -> Root) ---" << endl;
        postorder(root);
        cout << "END\n\n";
    }
};

int main() {
    FileExplorer explorer;
    explorer.buildExplorer();
    explorer.showDFS();
    return 0;
}

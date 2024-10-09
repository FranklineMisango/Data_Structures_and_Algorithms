#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    int size; 

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1), size(1) {}
};

// AVL Tree class
class AVLTree {
public:
    // Public operations
    void insert(int key);
    void remove(int key);
    void modify(int oldKey, int newKey);
    int kthMin(int k);

private:
    // Private operations
    int height(Node* node);
    int size(Node* node);
    int balanceFactor(Node* node);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* insert(Node* root, int key);
    Node* remove(Node* root, int key);
    Node* findMin(Node* node);
    Node* modify(Node* root, int oldKey, int newKey);
    int kthMin(Node* root, int k);

    // Private member
    Node* root = nullptr;
};

// AVL Tree insertion
void AVLTree::insert(int key) {
    root = insert(root, key);
}

// AVL Tree deletion
void AVLTree::remove(int key) {
    root = remove(root, key);
}

// AVL Tree modification
void AVLTree::modify(int oldKey, int newKey) {
    root = modify(root, oldKey, newKey);
}

// AVL Tree kthMin operation
int AVLTree::kthMin(int k) {
    return kthMin(root, k);
}

// Helper function to get the height of a node
int AVLTree::height(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

// Helper function to get the size of a node
int AVLTree::size(Node* node) {
    return (node == nullptr) ? 0 : node->size;
}

// Helper function to calculate the balance of a node
int AVLTree::balanceFactor(Node* node) {
    return (node == nullptr) ? 0 : height(node->left) - height(node->right);
}

// Helper function to perform a right rotation
Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights and sizes
    y->height = max(height(y->left), height(y->right)) + 1;
    y->size = size(y->left) + size(y->right) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    x->size = size(x->left) + size(x->right) + 1;

    return x;
}

// Rotate left
Node* AVLTree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights and sizes
    x->height = max(height(x->left), height(x->right)) + 1;
    x->size = size(x->left) + size(x->right) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    y->size = size(y->left) + size(y->right) + 1;

    return y;
}

// Insert keys 
Node* AVLTree::insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    // Perform standard BST insert
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    } else {
        return root; 
    }

    // Update height and size of the current node
    root->height = max(height(root->left), height(root->right)) + 1;
    root->size = size(root->left) + size(root->right) + 1;

    // Get the balance of this node
    int balance = balanceFactor(root);

    // Perform rotations if necessary
    if (balance > 1) {
        if (key < root->left->key) {
            // Left-Left Case
            return rotateRight(root);
        } else {
            // Left-Right Case
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }
    if (balance < -1) {
        if (key > root->right->key) {
            // Right-Right Case
            return rotateLeft(root);
        } else {
            // Right-Left Case
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}


// Helper functions  for the specified commands 
Node* AVLTree::findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node* AVLTree::remove(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->key) {
        root->left = remove(root->left, key);
    } else if (key > root->key) {
        root->right = remove(root->right, key);
    } else {
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = (root->left != nullptr) ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp; 
            }

            delete temp;
        } else {

            Node* temp = findMin(root->right);

            root->key = temp->key;

            root->right = remove(root->right, temp->key);
        }
    }

    if (root == nullptr) {
        return root;
    }

    root->height = max(height(root->left), height(root->right)) + 1;
    root->size = size(root->left) + size(root->right) + 1;

    int balance = balanceFactor(root);

    if (balance > 1) {
        if (balanceFactor(root->left) >= 0) {
            
            return rotateRight(root);
        } else {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }
    if (balance < -1) {
        if (balanceFactor(root->right) <= 0) {
            return rotateLeft(root);
        } else {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}

Node* AVLTree::modify(Node* root, int oldKey, int newKey) {
    root = remove(root, oldKey);

   
    root = insert(root, newKey);

    return root;
}

int AVLTree::kthMin(Node* root, int k) {
    if (root == nullptr || k <= 0 || k > root->size) {
        return -1; 
    }

    int leftSize = size(root->left);

    if (k == leftSize + 1) {
        return root->key; 
    } else if (k <= leftSize) {
        return kthMin(root->left, k);
    } else {
        return kthMin(root->right, k - leftSize - 1);
    }
}

int main() {
    AVLTree avlTree;

    std::string operation;  
    int key, k;

    while (cin >> operation) {
        if (operation == "A") {
            cin >> key;
            avlTree.insert(key);
        } else if (operation == "D") {
            cin >> key;
            avlTree.remove(key);
        } else if (operation == "C") {
            int newKey;
            cin >> key >> newKey;
            avlTree.modify(key, newKey);
        } else if (operation == "M") {
            cin >> k;
            cout << avlTree.kthMin(k) << endl;
        } else if (operation == "END") {
            break;
        }
    }
    return 0;

}

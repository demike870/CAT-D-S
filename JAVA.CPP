#include <iostream>

// Node structure for the binary tree
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the binary tree
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to perform inorder traversal of the binary tree
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Function to perform preorder traversal of the binary tree
void preorderTraversal(Node* root) {
    if (root != nullptr) {
        std::cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform postorder traversal of the binary tree
void postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        std::cout << root->data << " ";
    }
}

// Function to search for a node in the binary tree
bool search(Node* root, int data) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == data) {
        return true;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to find the minimum value in the binary tree
int findMin(Node* root) {
    if (root == nullptr) {
        // Handle empty tree case appropriately (e.g., throw an exception or return a special value)
        return -1; // Or throw an exception
    }
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}

// Function to find the maximum value in the binary tree
int findMax(Node* root) {
    if (root == nullptr) {
        // Handle empty tree case appropriately
        return -1; // Or throw an exception
    }
    while (root->right != nullptr) {
        root = root->right;
    }
    return root->data;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 13);

    std::cout << "Inorder traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Preorder traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    postorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Search for 6: " << (search(root, 6) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 15: " << (search(root, 15) ? "Found" : "Not Found") << std::endl;

    std::cout << "Minimum value: " << findMin(root) << std::endl;
    std::cout << "Maximum value: " << findMax(root) << std::endl;

    return 0;
}

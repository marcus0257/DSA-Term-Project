#include <iostream>
#include "splay.h"

using namespace std;

// Constructor for a node that takes a key
SplayNode::SplayNode(std::string key) {
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
}

// Method for creating a new node
SplayNode* SplayTree::New_Node(std::string key) {
    // Creating a temp node with two empty children
    SplayNode* p_node = new SplayNode(key);
    p_node->left = p_node->right = nullptr;
    return p_node;
}

// Method for rotating a node to the right
SplayNode* SplayTree::rotateRight(SplayNode* OldKey) {
    SplayNode* NewKey = OldKey->left;
    OldKey->left = NewKey->right;
    NewKey->right = OldKey;
    return NewKey;
}

// Method for rotating a node to the left
SplayNode* SplayTree::rotateLeft(SplayNode* OldKey) {
    SplayNode* NewKey = OldKey->right;
    OldKey->right = NewKey->left;
    NewKey->left = OldKey;
    return NewKey;
}

// Method for splaying a node to the root
SplayNode* SplayTree::splay(std::string key, SplayNode* root) {
    // If the tree is empty, return nullptr
    if (!root) {
        return nullptr;
    }

    // Creating a temporary left, right, and parent node
    SplayNode parent;
    SplayNode* leftTree = &parent;
    SplayNode* rightTree = &parent;

    // Infinite loop to keep rotating until key is closer to the root of the tree
    while (true) {
        // If the key is less than the root, rotate right
        if (key < root->key) {
            // If the root has no left child, break the loop
            if (!root->left)
                break;

            // If the key is less than the left child, rotate right twice
            if (key < root->left->key) {
                root = rotateRight(root);
                if (!root->left)
                    break;
            }
            rightTree->left = root;
            rightTree = rightTree->left;
            root = root->left;
            rightTree->left = nullptr;
        }
        // If the key is greater than the root, rotate left twice
        else if (key > root->key) {
            if (!root->right)
                break;

            if (key > root->right->key) {
                root = rotateLeft(root);
                if (!root->right)
                    break;
            }
            leftTree->right = root;
            leftTree = leftTree->right;
            root = root->right;
            leftTree->right = nullptr;
        } else
            break;
    }

    // Update tree with temporary left and right tree
    leftTree->right = root->left;
    rightTree->left = root->right;
    root->left = parent.right;
    root->right = parent.left;
    return root;
}

// Method for inserting a node into the tree
SplayNode* SplayTree::insert(std::string key, SplayNode* root) {
    // Creating a new temporary variable
    SplayNode* temp = nullptr;

    // Initializing temp with the value we want to insert
    if (!temp) {
        temp = New_Node(key);
    } else {
        temp->key = key;
    }

    // If tree is empty, set key to the value we want to insert
    if (!root) {
        root = temp;
        temp = nullptr;
        return root;
    }

    // Splay the key to the root of the tree, or move the key closer to the root of the tree
    root = splay(key, root);

    // If the key is less than the root, set the left child of the root to the key
    if (key < root->key) {
        temp->left = root->left;
        temp->right = root;
        root->left = nullptr;
        root = temp;
    }
    // If the key is greater than the root, set the right child of the root to the key
    else if (key > root->key) {
        temp->right = root->right;
        temp->left = root;
        root->right = nullptr;
        root = temp;
    }
    // Tree is empty and return new root value
    else {
        return root;
    }
    temp = nullptr;
    return root;
}

// Method for removing a node from the tree
SplayNode* SplayTree::remove(std::string key, SplayNode* root) {
    // Check if the current root is null (base case for recursion)
    if (!root) {
        return nullptr;
    }

    // Check if the key to remove is equal to the key of the current root
    if (key == root->key) {
        SplayNode* temp;

        // If the left child is null, set temp to the current root and return null
        if (!root->left) {
            temp = root;
            return nullptr;
        }

        // If either the left or right child is null, update temp accordingly
        if ((!root->right) != (!root->left)) {
            if (!root->left) {
                temp = root->right;
            } else {
                temp = root->left;
            }

            // Delete the current root and return the updated temp node
            delete root;
            return temp;
        }

        // If both children are present, find the successor (temp) in the right subtree
        temp = root->right;

        while (temp->left) {
            temp = temp->left;
        }

        // Replace the key of the current root with the successor key
        root->key = temp->key;

        // Recursively remove the successor from the right subtree
        root->right = remove(temp->key, root->right);

        // Return the updated root
        return root;
    }

    // If the key to remove is less than the current root's key, recursively remove from the left subtree
    if (key < root->key) {
        root->left = remove(key, root->left);
    } else {
        // If the key to remove is greater than or equal to the current root's key,
        // recursively remove from the right subtree
        root->right = remove(key, root->right);
    }

    // Return null (no structural change in the current subtree)
    return nullptr;
}

// Recursive call
void SplayTree::insert(std::string key) {
    this->root = this->insert(key, this->root);
}

// Recursive call
void SplayTree::remove(std::string key) {
    this->root = this->remove(key, this->root);
}

// Recursive call
SplayNode* SplayTree::search(std::string key) {
    return this->search(key, this->root);
}

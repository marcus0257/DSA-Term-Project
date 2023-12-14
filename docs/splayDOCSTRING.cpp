/**
 * @file splay.cpp
 * @brief Implementation of Splay Tree data structure in C++.
 */
#include <iostream>

/**
 * @class SplayNode
 * @brief Represents a node in the Splay Tree.
 */
class SplayNode {
public:
    int key; ///< Key value of the node.
    SplayNode* left; ///< Pointer to the left child.
    SplayNode* right; ///< Pointer to the right child.

    /**
     * @brief Default constructor for node.
     */
    SplayNode();

    /**
     * @brief Constructor for a node that takes a key.
     * @param key Key value to be assigned to the node.
     */
    SplayNode(int key);

    /**
     * @brief Default destructor for node.
     */
    ~SplayNode();
};

/**
 * @class SplayTree
 * @brief Represents a Splay Tree.
 */
class SplayTree {
public:
    SplayNode* root; ///< Pointer to the root of the tree.

    /**
     * @brief Default tree constructor.
     */
    SplayTree();

    /**
     * @brief Tree destructor.
     */
    ~SplayTree();

    /**
     * @brief Method for rotating a node to the right.
     * @param OldKey Node to be rotated.
     * @return New root after rotation.
     */
    SplayNode* rotateRight(SplayNode* OldKey);

    /**
     * @brief Method for rotating a node to the left.
     * @param OldKey Node to be rotated.
     * @return New root after rotation.
     */
    SplayNode* rotateLeft(SplayNode* OldKey);

    /**
     * @brief Method for splaying a node to the root.
     * @param key Key value to be splayed.
     * @param root Root of the tree.
     * @return New root after splaying.
     */
    SplayNode* splay(int key, SplayNode* root);

    /**
     * @brief Creates a new node with the given key.
     * @param key Key value for the new node.
     * @return Newly created node.
     */
    SplayNode* New_Node(int key);

    /**
     * @brief Method for inserting a node into the tree.
     * @param key Key value to be inserted.
     * @param root Root of the tree.
     * @return New root after insertion.
     */
    SplayNode* insert(int key, SplayNode* root);

    /**
     * @brief Method for removing a node from the tree.
     * @param key Key value to be removed.
     * @param root Root of the tree.
     * @return New root after removal.
     */
    SplayNode* remove(int key, SplayNode* root);

    /**
     * @brief Recursive call to insert a key into the tree.
     * @param key Key value to be inserted.
     */
    void insert(int key);

    /**
     * @brief Recursive call to remove a key from the tree.
     * @param key Key value to be removed.
     */
    void remove(int key);

    /**
     * @brief Recursive call to perform pre-order traversal of the tree.
     */
    void preorder();

    /**
     * @brief Recursive call to perform in-order traversal of the tree.
     */
    void inorder();

    /**
     * @brief Recursive call to perform post-order traversal of the tree.
     */
    void postorder();

    /**
     * @brief Recursive call to search for a key in the tree and splay it.
     * @param key Key value to be searched.
     * @return Root after splaying.
     */
    SplayNode* search(int key);

private:
    /**
     * @brief Recursive method to perform pre-order traversal of the tree.
     * @param root Current root node.
     */
    void preorder(SplayNode* root);

    /**
     * @brief Recursive method to perform in-order traversal of the tree.
     * @param root Current root node.
     */
    void inorder(SplayNode* root);

    /**
     * @brief Recursive method to perform post-order traversal of the tree.
     * @param root Current root node.
     */
    void postorder(SplayNode* root);
};



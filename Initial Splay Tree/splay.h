#ifndef SPLAY_H
#define SPLAY_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

class SplayNode {
private:
    int key;  // Change from std::string to int
    SplayNode* left;
    SplayNode* right;
    bool color = false;

public:
    SplayNode();
    SplayNode(int key);  // Change from std::string to int
    ~SplayNode();

    friend class SplayTree;
};

class SplayTree {
private:
    SplayNode* root;
    SplayNode* rotateLeft(SplayNode* root);
    SplayNode* rotateRight(SplayNode* root);
    SplayNode* splay(int key, SplayNode* root);  // Change from std::string to int
    SplayNode* insert(int key, SplayNode* root);  // Change from std::string to int
    SplayNode* remove(int key, SplayNode* root);  // Change from std::string to int
    void preorder(SplayNode* root);
    void inorder(SplayNode* root);
    void postorder(SplayNode* root);
    //void destroy(SplayNode* root);
    SplayNode* search(int key, SplayNode* root);  // Change from std::string to int
    SplayNode* New_Node(int key);  // Change from std::string to int

public:
    SplayTree();
    ~SplayTree();

    void insert(int key);  // Change from std::string to int
    void remove(int key);  // Change from std::string to int
    void preorder();
    void inorder();
    void postorder();
    //void destroy();
    SplayNode* search(int key);  // Change from std::string to int
};

#endif

#ifndef SPLAY_H
#define SPLAY_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

class SplayNode {
private:
    int key;  
    SplayNode* left;
    SplayNode* right;

public:
    SplayNode();
    SplayNode(int key);  
    ~SplayNode();

    friend class SplayTree;
};

class SplayTree {
private:
    SplayNode* root;
    SplayNode* rotateLeft(SplayNode* root);
    SplayNode* rotateRight(SplayNode* root);
    SplayNode* splay(int key, SplayNode* root);  
    SplayNode* insert(int key, SplayNode* root); 
    SplayNode* remove(int key, SplayNode* root);  
    void preorder(SplayNode* root);
    void inorder(SplayNode* root);
    void postorder(SplayNode* root);
    //void destroy(SplayNode* root);
    SplayNode* search(int key, SplayNode* root); 
    SplayNode* New_Node(int key);  

public:
    SplayTree();
    ~SplayTree();

    void insert(int key);  
    void remove(int key);  
    void preorder();
    void inorder();
    void postorder();
    //void destroy();
    SplayNode* search(int key);  // Change from std::string to int
};

#endif

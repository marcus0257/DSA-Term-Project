#ifndef SPLAY_H
#define SPLAY_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

class SplayNode {
private:
    std::string key;  // Change from int to std::string
    SplayNode* left;
    SplayNode* right;
    bool color = false;

public:
    SplayNode();
    SplayNode(std::string key);  // Change from int to std::string
    ~SplayNode();

    friend class SplayTree;
};

class SplayTree {
private:
    SplayNode* root;
    SplayNode* rotateLeft(SplayNode* root);
    SplayNode* rotateRight(SplayNode* root);
    SplayNode* splay(std::string key, SplayNode* root);  // Change from int to std::string
    SplayNode* insert(std::string key, SplayNode* root);  // Change from int to std::string
    SplayNode* remove(std::string key, SplayNode* root);  // Change from int to std::string
    void preorder(SplayNode* root);
    void inorder(SplayNode* root);
    void postorder(SplayNode* root);
    //void destroy(SplayNode* root);
    SplayNode* search(std::string key, SplayNode* root);  // Change from int to std::string
    SplayNode* New_Node(std::string key);  // Change from int to std::string

public:
    SplayTree();
    ~SplayTree();

    void insert(std::string key);  // Change from int to std::string
    void remove(std::string key);  // Change from int to std::string
    void preorder();
    void inorder();
    void postorder();
    //void destroy();
    SplayNode* search(std::string key);  // Change from int to std::string
};

#endif

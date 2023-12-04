#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

struct SplayNode // node declaration
{
    std::string key;
    SplayNode* left;
    SplayNode* right;
};

class SplayTree
{
public:
    //right rotation
    SplayNode* RR_Rotate(SplayNode* k2);

    //left rotation
    SplayNode* LL_Rotate(SplayNode* k2);

    //splay, bring given value to the root of the tree
    SplayNode* Splay(const std::string& key, SplayNode* root);

    //creates new node
    SplayNode* New_Node(const std::string& key);

    //inserts node with given key
    SplayNode* insert(const std::string& key, SplayNode* root);

    //deletes node with given key
    SplayNode* Delete(const std::string& key, SplayNode* root);

    //returns the given key at the root of the tree
    SplayNode* Search(const std::string& key, SplayNode* root);

    //prints inorder traversal
    void InOrder(SplayNode* root);

    //prints preorder traversal
    void PreOrder(SplayNode* root);

    //prints postorder traversal
    void PostOrder(SplayNode* root);

};

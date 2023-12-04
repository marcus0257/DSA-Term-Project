#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
#include <fstream>

struct SplayNode // node declaration
{
    int key;
    std::string query;
    bool purple;
    SplayNode* left;
    SplayNode* right;
};

class SplayTree
{
public:
SplayNode* root;
    //right rotation
    SplayNode* RR_Rotate(SplayNode* k2);

    //left rotation
    SplayNode* LL_Rotate(SplayNode* k2);

    //splay, bring given value to the root of the tree
    SplayNode* Splay(int key, SplayNode* root);

    //creates new node
    SplayNode* New_Node(int key, std::string query,bool purple);

    //inserts node with given key
    SplayNode* insert(int key, std::string query,bool purple, SplayNode* root);
    void insert(int key, std::string query,bool purple){this->root = insert(key,query,purple,root);};


    //deletes node with given key
    SplayNode* Delete(int key, SplayNode* root);

    //returns the given key at the root of the tree
    SplayNode* Search(int key, SplayNode* root);

    //prints inorder traversal
    void InOrder(std::ofstream& outfile, SplayNode* root);

    //prints preorder traversal
    void PreOrder(SplayNode* root);

    //prints postorder traversal
    void PostOrder(SplayNode* root);

    void LevelOrder(std::ofstream& outfile, SplayNode* root);


};
//added query to insert and node creation and as a data member
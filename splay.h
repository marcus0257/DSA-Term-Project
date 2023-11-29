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
    SplayNode* RR_Rotate(SplayNode* k2);

    SplayNode* LL_Rotate(SplayNode* k2);

    SplayNode* Splay(const std::string& key, SplayNode* root);

    SplayNode* New_Node(const std::string& key);

    SplayNode* insert(const std::string& key, SplayNode* root);

    SplayNode* Delete(const std::string& key, SplayNode* root);

    SplayNode* Search(const std::string& key, SplayNode* root);

    void InOrder(SplayNode* root);

    void PreOrder(SplayNode* root);

    void PostOrder(SplayNode* root);

};

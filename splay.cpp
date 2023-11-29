#include "splay.h"

using namespace std;

SplayNode* SplayTree::RR_Rotate(SplayNode* k2)
{
    SplayNode* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    return k1;
}

SplayNode* SplayTree::LL_Rotate(SplayNode* k2)
{
    SplayNode* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    return k1;
}

SplayNode* SplayTree::Splay(const string& key, SplayNode* root)
{
    if (!root)
        return nullptr;

    SplayNode header;
    header.left = header.right = nullptr;
    SplayNode* LeftTreeMax = &header;
    SplayNode* RightTreeMin = &header;

    while (1)
    {
        if (key < root->key)
        {
            if (!root->left)
                break;

            if (key < root->left->key)
            {
                root = RR_Rotate(root);
                if (!root->left)
                    break;
            }

            RightTreeMin->left = root;
            RightTreeMin = RightTreeMin->left;
            root = root->left;
            RightTreeMin->left = nullptr;
        }
        else if (key > root->key)
        {
            if (!root->right)
                break;

            if (key > root->right->key)
            {
                root = LL_Rotate(root);
                if (!root->right)
                    break;
            }

            LeftTreeMax->right = root;
            LeftTreeMax = LeftTreeMax->right;
            root = root->right;
            LeftTreeMax->right = nullptr;
        }
        else
            break;
    }

    LeftTreeMax->right = root->left;
    RightTreeMin->left = root->right;
    root->left = header.right;
    root->right = header.left;
    return root;
}

SplayNode* SplayTree::New_Node(const string& key)
{
    SplayNode* p_node = new SplayNode;
    if (!p_node)
    {
        fprintf(stderr, "Out of memory!\n");
        exit(1);
    }
    p_node->key = key;
    p_node->left = p_node->right = nullptr;
    return p_node;
}

SplayNode* SplayTree::insert(const string& key, SplayNode* root)
{
    static SplayNode* p_node = nullptr;
    if (!p_node)
        p_node = New_Node(key);
    else
        p_node->key = key;

    if (!root)
    {
        root = p_node;
        p_node = nullptr;
        return root;
    }

    root = Splay(key, root);

    if (key < root->key)
    {
        p_node->left = root->left;
        p_node->right = root;
        root->left = nullptr;
        root = p_node;
    }
    else if (key > root->key)
    {
        p_node->right = root->right;
        p_node->left = root;
        root->right = nullptr;
        root = p_node;
    }
    else
        return root;

    p_node = nullptr;
    return root;
}

SplayNode* SplayTree::Delete(const string& key, SplayNode* root)
{
    SplayNode* temp;
    if (!root)
        return nullptr;

    root = Splay(key, root);

    if (key != root->key)
        return root;
    else
    {
        if (!root->left)
        {
            temp = root;
            root = root->right;
        }
        else
        {
            temp = root;
            root = Splay(key, root->left);
            root->right = temp->right;
        }

        delete temp;
        return root;
    }
}

SplayNode* SplayTree::Search(const string& key, SplayNode* root)
{
    return Splay(key, root);
}

void SplayTree::InOrder(SplayNode* root)
{
    if (root)
    {
        InOrder(root->left);
        cout << "key: " << root->key;
        if (root->left)
            cout << " | left: " << root->left->key;
        if (root->right)
            cout << " | right: " << root->right->key;
        cout << "\n";
        InOrder(root->right);
    }
}

void SplayTree::PreOrder(SplayNode* root)
{
    if (root)
    {
        cout << "key: " << root->key;
        if (root->left)
            cout << " | left: " << root->left->key;
        if (root->right)
            cout << " | right: " << root->right->key;
        cout << "\n";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void SplayTree::PostOrder(SplayNode* root)
{
    if (root)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << "key: " << root->key;
        if (root->left)
            cout << " | left: " << root->left->key;
        if (root->right)
            cout << " | right: " << root->right->key;
        cout << "\n";
    }
}

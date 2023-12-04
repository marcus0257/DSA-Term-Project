#include "splay.h"

using namespace std;

//this method is responsible for rotating the given nodes to the right
SplayNode* SplayTree::RR_Rotate(SplayNode* k2)
{
    SplayNode* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    return k1;
}

//this method is responsible for rotating given nodes to the left
SplayNode* SplayTree::LL_Rotate(SplayNode* k2)
{
    SplayNode* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    return k1;
}

//this is the method which splays the node, brings the node to the root of the tree
SplayNode* SplayTree::Splay(const string& key, SplayNode* root)
{
    //if node is null, return nullptr
    if (!root)
        return nullptr;

    //create two empty trees for splaying 
    SplayNode header;
    header.left = header.right = nullptr;
    SplayNode* LeftTreeMax = &header;
    SplayNode* RightTreeMin = &header;

    while (1)
    {
        //if given value is less than root data
        if (key < root->key)
        {
            //if root left is a nullptr
            if (!root->left)
                break;

            //if given value is less than root->left's value, perform a right rotation to bring the tree closer to the root
            if (key < root->left->key)
            {
                root = RR_Rotate(root);
                if (!root->left)
                    break;
            }

            //use temp tree to reassemble the root
            RightTreeMin->left = root;
            RightTreeMin = RightTreeMin->left;
            root = root->left;
            RightTreeMin->left = nullptr;
        }

        //if given value is greater than root data
        else if (key > root->key)
        {
            //if there is no right child
            if (!root->right)
                break;

            //if right child is greater than given data
            if (key > root->right->key)
            {
                //perform a left rotation to bring node closer to the root
                root = LL_Rotate(root);
                if (!root->right)
                    break;
            }

            //reassemble the tree using opposite temp tree
            LeftTreeMax->right = root;
            LeftTreeMax = LeftTreeMax->right;
            root = root->right;
            LeftTreeMax->right = nullptr;
        }
        else
            break;
    }

    //assemble the root tree now that data has been splayed closer to the root
    LeftTreeMax->right = root->left;
    RightTreeMin->left = root->right;
    root->left = header.right;
    root->right = header.left;
    return root;
}

SplayNode* SplayTree::New_Node(const string& key)
{
    //creating a temp node with two empty children
    SplayNode* p_node = new SplayNode;
    p_node->key = key;
    p_node->left = p_node->right = nullptr;
    return p_node;
}

SplayNode* SplayTree::insert(const string& key, SplayNode* root)
{
    static SplayNode* p_node = nullptr;
    //if p_node was not created, create a new node, else set value equal to given key
    if (!p_node)
        p_node = New_Node(key);
    else
        p_node->key = key;

    //if root is a nullptr, set root equal to given value and return tree
    if (!root)
    {
        root = p_node;
        p_node = nullptr;
        return root;
    }

    //rotate the tree to bring inserted value to the root of the tree
    root = Splay(key, root);

    //if value is less than root data, we will insert it to the left subtree
    if (key < root->key)
    {
        
        p_node->left = root->left;
        p_node->right = root;
        root->left = nullptr;
        root = p_node;
    }
        //else insert it to the right subtree
    else if (key > root->key)
    {
        p_node->right = root->right;
        p_node->left = root;
        root->right = nullptr;
        root = p_node;
    }
    else
        return root;

    //destroy p_node 
    p_node = nullptr;
    return root;
}

// Delete a node with the given key from the splay tree
SplayNode* SplayTree::Delete(const string& key, SplayNode* root)
{
    SplayNode* temp;
    if (!root)
        return nullptr;

    // Splay the tree with the given key
    root = Splay(key, root);

    if (key != root->key)
        return root;
    else
    {
        // Remove the node with the given key
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

        // Delete the removed node
        delete temp;
        return root;
    }
}

// Search for a node with the given key in the splay tree
SplayNode* SplayTree::Search(const string& key, SplayNode* root)
{
    // Splay the tree with the given key, bringing the searched node to the root
    return Splay(key, root);
}

// Perform an in-order traversal of the splay tree and print node information
void SplayTree::InOrder(SplayNode* root)
{
    if (root)
    {
        // Visit left subtree
        InOrder(root->left);
        
        // Print node information
        cout << "key: " << root->key;
        if (root->left)
            cout << " | left: " << root->left->key;
        if (root->right)
            cout << " | right: " << root->right->key;
        cout << "\n";

        // Visit right subtree
        InOrder(root->right);
    }
}

// Perform a pre-order traversal of the splay tree and print node information
void SplayTree::PreOrder(SplayNode* root)
{
    if (root)
    {
        // Print node information
        cout << "key: " << root->key;
        if (root->left)
            cout << " | left: " << root->left->key;
        if (root->right)
            cout << " | right: " << root->right->key;
        cout << "\n";

        // Visit left subtree
        PreOrder(root->left);
        
        // Visit right subtree
        PreOrder(root->right);
    }
}

// Perform a post-order traversal of the splay tree and print node information
void SplayTree::PostOrder(SplayNode* root)
{
    if (root)
    {
        // Visit left subtree
        PostOrder(root->left);
        
        // Visit right subtree
        PostOrder(root->right);

        // Print node information
        cout << "key: " << root->key;
        if (root->left)
            cout << " | left: " << root->left->key;
        if (root->right)
            cout << " | right: " << root->right->key;
        cout << "\n";
    }
}

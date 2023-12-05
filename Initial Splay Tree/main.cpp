#include "splay.h"
#include <iostream>

int main(){

    SplayTree tree;

    for(int i = 0; i<15; i++){
        tree.insert(i);
    }
    //preorder traversal prints the root of the tree first
    tree.preorder();

    //for every search, the searched node is splayed to the top of the tree
    tree.search(7);
    tree.search(8);
    tree.search(4);

    //root of tree should be 4 since it was the most recently searched, 7 and 8 should be realtively quick to access from 4,
    // as they were very recently searched
    tree.preorder();

    return 0;
}

//feel free to play around with different search values and ranges for the for loop

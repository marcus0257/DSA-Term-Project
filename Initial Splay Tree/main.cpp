#include <iostream>
#include "splay.h"

int main()
{
    SplayTree tree;
    int phrase = 1;
    int phrase1 = 2;
    int phrase2 = 3;
    int phrase3 = 9;
    int phrase4 = 6;

    tree.insert(phrase);
    tree.insert(phrase1);
    tree.insert(phrase2);
    tree.insert(phrase3);
    tree.insert(phrase4);


    tree.search(2);

    tree.preorder();

    return 0;
}

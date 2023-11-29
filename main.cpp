#include <iostream>
#include "splay.h"

int main()
{
    SplayTree st;
    SplayNode* root = nullptr;
    std::string phrase = "The quick brown fox jumps over the lazy dog";

    st.insert(phrase, root);

    std::cout << "\n";
    return 0;
}

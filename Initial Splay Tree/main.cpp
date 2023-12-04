#include <iostream>
#include "splay.h"

int main()
{
    //example of how the last key inserted is closer to the root of the tree
    SplayTree st;
    SplayNode* root = nullptr;
    std::string phrase = "The quick brown fox jumps over the lazy dog";
    std::string phrase = "Where is the nearest hospital";
    std::string phrase = "who is the president";
    std::string phrase = "youtube";
    std::string phrase = "youtube.com";
    std::string phrase = "google.com";
    
    st.insert(phrase, root);
    

    return 0;
}

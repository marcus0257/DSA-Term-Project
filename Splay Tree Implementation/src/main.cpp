#include "splay.h"
#include <fstream>
#include <sstream>
//this file becomes backend.exe
int main(int argc, char* argv[]){
    //set up tree based on state
    std::ifstream ifs("src/state.txt");

    SplayTree tree;

    std::string line;

    int num;
    std::string query;
    bool purple;

    while(std::getline(ifs,line)){
        std::stringstream ss(line);
        ss >> num >> purple; 
        if(ss >> std::ws && ss.peek() == '"')
            std::getline(ss, query);
        tree.insert(num,query,purple);
    }
    //perform search
    tree.Search(atoi(argv[1]),tree.root);

    //save state
    std::ofstream outfile("src/state.txt");
    tree.LevelOrder(outfile, tree.root);
    tree.InOrder(outfile, tree.root);
    outfile.close();

    std::cout << "Tree updated" << std::endl;
    
    return 0;
}

#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
//this file beocomes json.exe
//this file writes the info.json
int main(){
    std::ofstream outfile("public/info.json");
    std::ifstream ifs("src/state.txt");
    std::vector<int> index;
    std::vector<std::string> q;
    std::vector<bool> purp;

    int num;
    bool purple;
    std::string query;
    std::string line;
    
    while(std::getline(ifs,line)){
        std::stringstream ss(line);
        ss >> num >> purple; 
        if(ss >> std::ws && ss.peek() == '"')
            std::getline(ss, query);
        index.push_back(num);
        q.push_back(query);
        purp.push_back(purple);
    }

    outfile << '{' << std::endl << "    \"queries\" :[";

    for(int i = 0; i<q.size(); i++){
        if(i != q.size()-1)
        outfile << q[i] << ',' << std::endl;
        else
        outfile << q[i] << "],"<< std::endl;
    }

    outfile << std::endl << "\"indexes\": [";

    for(int i = 0; i<index.size(); i++){
        if(i != index.size()-1)
        outfile << index[i] << ',' << std::endl;
        else
        outfile << index[i] << "],"<< std::endl;
    }

    outfile << std::endl << "\"purple\": [";

    for(int i = 0; i<purp.size(); i++){
        if(i != purp.size()-1)
        outfile << purp[i] << ',' << std::endl;
        else
        outfile << purp[i] << "]}"<< std::endl;
    }

std::cout << "frontend updated" << std::endl;
}

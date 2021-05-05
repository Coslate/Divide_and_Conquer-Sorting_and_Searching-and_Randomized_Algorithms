//main.cpp
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <solution.h>
#include <math.h>

bool debug_addr     = false;
bool debug_key      = true;
bool debug_name     = true;

std::vector<std::vector<std::string>> input_edge_list;

//Generate the correspondence between Node & LinkedListNode.
std::unordered_map<std::string, LinkedListNode*> map_node_st2lln;

std::unordered_set<StrPair> total_edge;

std::vector<StrPair> total_edge_v;

std::unordered_set<std::string> total_node;

std::unordered_map<int, int> map_cut2num;

int min_cut_edge = INT_MAX;

int trial_num = 0;

//Adjacent list of a graph
//AdjList adj_list(true, false);

void readFile(std::string filename, std::vector<std::vector<std::string>> &input_edge_list){
    std::string line;
    std::ifstream myfile (filename);
    if (myfile.is_open()){
        while ( std::getline (myfile,line) ){
            std::istringstream iss(line); 
            std::vector<std::string> tmp_vec;
            for(std::string s; iss >> s;){
                tmp_vec.push_back(s);
            }
            input_edge_list.push_back(tmp_vec);
        }
        myfile.close();
    }else std::cout << "Unable to open file"; 
}

int main(int argc, char*argv[]){
    if(argc < 2){
        std::cerr<<"Error: There should be at least one input argument like ./main arg1"<<std::endl;
        return EXIT_FAILURE;
    }
    
    std::cout<<"------Karger Min-Cut Problem-----"<<std::endl;
    readFile(argv[1], input_edge_list);

/*
    for(const auto &in : input_edge_list){
        for(const auto &elem : in){
            std::cout<<elem<<" ";
        }
        std::cout<<std::endl;
    }
*/

    std::cout<<"> buildEdgeInfo..."<<std::endl;
    buildEdgeInfo(map_node_st2lln, input_edge_list, total_edge, total_edge_v, total_node);

/*
    std::cout<<"----------adj_list------------"<<std::endl;
    for(const auto &element : map_node_st2lln){
        LinkedListNode* the_node = element.second;
        std::cout<<">>>> map_node_st2lln->the_node = "<<the_node->GetName()<<"("<<the_node<<")..."<<std::endl;
        adj_list.PrintAdjList(map_node_st2lln, the_node, debug_addr, debug_name, debug_key);
    }
    std::cout<<"----------total_node------------"<<std::endl;
    for(const auto &elem: total_node){
        std::cout<<elem<<std::endl;
    }
    std::cout<<"total num of nodes = "<<total_node.size()<<std::endl;
    std::cout<<"----------total_edge------------"<<std::endl;
    for(const auto &elem: total_edge){
        std::cout<<"("<<elem.first<<", "<<elem.second<<")"<<std::endl;
    }
    std::cout<<"total num of edges = "<<total_edge.size()<<std::endl;
*/

    std::cout<<"> kargerRandomContraction..."<<std::endl;
    unsigned seed         = (unsigned)time(NULL);//get time sequence
    srand(seed);//use current time as seed
    trial_num = total_node.size() * total_node.size() * log(total_node.size());//trial_num = n*n*ln(n) -> the success probability >= 1-1/n
    kargerRandomContraction(trial_num, total_edge_v, total_node, map_node_st2lln, map_cut2num, min_cut_edge);
    
    for(const auto &elem: map_cut2num){
        std::cout<<"cut = "<<elem.first<<", occured num = "<<elem.second<<std::endl;
    }
    std::cout<<"min_cut = "<<min_cut_edge<<std::endl;

    return EXIT_SUCCESS;
}

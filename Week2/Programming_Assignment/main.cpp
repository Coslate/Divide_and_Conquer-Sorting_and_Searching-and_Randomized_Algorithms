//main.cpp
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <solution.h>

std::vector<int> input_arr;
std::vector<int> sorted_arr;
long inv_num = 0;

void readFile(std::string filename, std::vector<int> &input_arr){
    std::string line;
    std::ifstream myfile (filename);
    if (myfile.is_open()){
        while ( std::getline (myfile,line) ){
            std::istringstream iss(line); 
            std::string s; iss >> s;
            input_arr.push_back(std::stoi(s));
        }
        myfile.close();
    }else std::cout << "Unable to open file"; 
}

int main(int argc, char*argv[]){
    if(argc < 2){
        std::cerr<<"Error: There should be at least one input argument like ./main arg1."<<std::endl;
        return EXIT_FAILURE;
    }
    
    readFile(argv[1], input_arr);
    std::cout<<"---Integer Multiplication Problem---"<<std::endl;
    std::cout<<"> Input..."<<std::endl;
    for(const auto &elem : input_arr){
        std::cout<<elem<<std::endl;
    }
    
    std::cout<<"> Calculating Recursively..."<<std::endl;
    inverseNumberCount(input_arr, 0, input_arr.size()-1, inv_num, sorted_arr);
    std::cout<<"> Result..."<<std::endl;
    std::cout<<"ans = "<<inv_num<<std::endl;


    return EXIT_SUCCESS;
}

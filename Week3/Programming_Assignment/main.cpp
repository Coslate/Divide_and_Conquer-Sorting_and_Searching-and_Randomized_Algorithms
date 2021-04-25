//main.cpp
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <solution.h>

std::vector<int> input_arr;
int comp_num = 0;
int pivot_choice = 0;

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
    if(argc < 4){
        std::cerr<<"Error: There should be at least one input argument like ./main arg1 -pivot $v."<<std::endl;
        std::cerr<<"       -pivot $v, $v = [choose_first_pivot]/[choose_last_pivot]/[choose_median_three_pivot]."<<std::endl;
        return EXIT_FAILURE;
    }

    if(std::strcmp(argv[2], "-pivot") == 0){
        if(std::strcmp(argv[3], "choose_first_pivot") == 0){
            pivot_choice = 0;
        }else if(std::strcmp(argv[3], "choose_last_pivot") == 0){
            pivot_choice = 1;
        }else if(std::strcmp(argv[3], "choose_median_three_pivot") == 0){
            pivot_choice = 2;
        }else{
            std::cerr<<"Error: There should be at least one input argument like ./main arg1 -pivot $v."<<std::endl;
            std::cerr<<"       -pivot $v, $v = [choose_first_pivot]/[choose_last_pivot]/[choose_median_three_pivot]."<<std::endl;
            return EXIT_FAILURE;
        }
    }
    
    readFile(argv[1], input_arr);
    std::cout<<"---QuickSort Problem---"<<std::endl;
    /*
    std::cout<<"> Input..."<<std::endl;
    for(const auto &elem : input_arr){
        std::cout<<elem<<std::endl;
    }
    */

    if(pivot_choice == 0){
        std::cout<<"> Calculating QuickSort by always choosing the first element in an array as pivot..."<<std::endl;
    }else if(pivot_choice == 1){
        std::cout<<"> Calculating QuickSort by always choosing the last element in an array as pivot..."<<std::endl;
    }else if(pivot_choice == 2){
        std::cout<<"> Calculating QuickSort by always choosing the median of first, last, and middle element(median of three) in an array as pivot..."<<std::endl;
    }

    quickSortRecur(input_arr, 0, int(input_arr.size()-1), comp_num, pivot_choice);
    comp_num += int(input_arr.size()-1);

    /*
    std::cout<<"Sorted version of input = "<<std::endl;
    for(const auto &elem : input_arr){
        std::cout<<elem<<std::endl;
    }
    */
    std::cout<<"The number of comparison = "<<comp_num<<std::endl;

    return EXIT_SUCCESS;
}

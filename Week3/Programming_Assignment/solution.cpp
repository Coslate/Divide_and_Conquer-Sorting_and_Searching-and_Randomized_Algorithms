//solution.cpp
#include <solution.h>

void partitionSubroutine(std::vector<int> &input_arr, const int &start_idx, const int &end_idx, int &first_start_idx, int &first_end_idx, int &sec_start_idx, int &sec_end_idx, const int &pivot_val, const int &pivot_idx){
    std::swap(input_arr[start_idx], input_arr[pivot_idx]);
    int i = start_idx+1;

    /*
    std::cout<<"<><><><>"<<std::endl;
    std::cout<<"start_idx = "<<start_idx<<", end_idx = "<<end_idx<<std::endl;
    std::cout<<"i = "<<i<<", pivot_val = "<<pivot_val<<", pivot_idx = "<<pivot_idx<<std::endl;
    std::cout<<"orig : input_arr = ";
    for(const auto &elem: input_arr){
        std::cout<<elem<<" ";
    }
    std::cout<<std::endl;
    */

    for(int j=start_idx+1;j<=end_idx;++j){
        if(input_arr[j] < pivot_val){
            std::swap(input_arr[i], input_arr[j]);
            ++i;
        }
    }

    if(i <= end_idx){
        std::swap(input_arr[start_idx], input_arr[i-1]);
    }else{//all elements after start_idx are smaller than pivot.
        std::swap(input_arr[start_idx], input_arr[end_idx]);
    }

    /*
    std::cout<<"after : input_arr = ";
    for(const auto &elem: input_arr){
        std::cout<<elem<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"after, i = "<<i<<std::endl;
    std::cout<<"<><><><>"<<std::endl;
    */

    first_start_idx = start_idx;
    first_end_idx   = ((i-2) < start_idx) ? start_idx : i-2;
    sec_start_idx   = i;
    sec_end_idx     = end_idx;
}

void pivotSelectionFirst(const std::vector<int> &input_arr, const int &start_idx, int &pivot_idx, int &pivot_val){
    pivot_val = input_arr[start_idx];
    pivot_idx = start_idx;
}

void pivotSelectionFinal(const std::vector<int> &input_arr, const int &end_idx, int &pivot_idx, int &pivot_val){
    pivot_val = input_arr[end_idx];
    pivot_idx = end_idx;
}

void pivotSelectionThreeMedian(const std::vector<int> &input_arr, const int &start_idx, const int &end_idx, int &pivot_idx, int &pivot_val){
    int first_idx_val = input_arr[start_idx];
    int final_idx_val = input_arr[end_idx];
    int med_idx_val   = 0;
    int med_idx       = (start_idx+end_idx)/2;
    int size_of_input = end_idx - start_idx + 1;
    std::vector<int> tmp_vec;

    if(size_of_input %2 == 0){
        med_idx = start_idx + size_of_input/2 - 1;
    }else{
        med_idx = start_idx + size_of_input/2;
    }

    med_idx_val = input_arr[med_idx];
    tmp_vec.push_back(first_idx_val);
    tmp_vec.push_back(med_idx_val);
    tmp_vec.push_back(final_idx_val);
    std::sort(tmp_vec.begin(), tmp_vec.end());

    pivot_val = tmp_vec[1];
    if(tmp_vec[1] == first_idx_val){
        pivot_idx = start_idx;
    }

    if(tmp_vec[1] == med_idx_val){
        pivot_idx = med_idx;
    }

    if(tmp_vec[1] == final_idx_val){
        pivot_idx = end_idx;
    }
}

void quickSortRecur(std::vector<int> &input_arr, const int &start_idx, const int &end_idx, int &comp_num, const int &pivot_choice){
    if(start_idx == end_idx){
        return;
    }
    
    int pivot_val       = 0;
    int pivot_idx       = 0;
    int first_start_idx = 0;
    int first_end_idx   = 0;
    int sec_start_idx   = 0;
    int sec_end_idx     = 0;

    if(pivot_choice == 0){
        pivotSelectionFirst(input_arr, start_idx, pivot_idx, pivot_val);
    }else if(pivot_choice == 1){
        pivotSelectionFinal(input_arr, end_idx, pivot_idx, pivot_val);
    }else if(pivot_choice == 2){
        pivotSelectionThreeMedian(input_arr, start_idx, end_idx, pivot_idx, pivot_val);
    }

    partitionSubroutine(input_arr, start_idx, end_idx, first_start_idx, first_end_idx, sec_start_idx, sec_end_idx, pivot_val, pivot_idx);
    /*
    std::cout<<"input_arr = ";
    for(const auto &elem: input_arr){
        std::cout<<elem<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"start_idx, end_idx = "<<start_idx<<", "<<end_idx<<std::endl;
    std::cout<<"pivot_val = "<<pivot_val<<std::endl;
    std::cout<<"pivot_idx = "<<pivot_idx<<std::endl;
    std::cout<<"first_start_idx, first_end_idx = "<<first_start_idx<<", "<<first_end_idx<<std::endl;
    std::cout<<"sec_start_idx, sec_end_idx = "<<sec_start_idx<<", "<<sec_end_idx<<std::endl;
    */

    comp_num += ((first_end_idx > first_start_idx) ? (first_end_idx - first_start_idx) : 0) + ((sec_end_idx > sec_start_idx) ? (sec_end_idx - sec_start_idx) : 0);

    /*
    std::cout<<"comp_num = "<<comp_num<<std::endl;
    std::cout<<"------------"<<std::endl;
    */

    if(first_end_idx > first_start_idx){
        quickSortRecur(input_arr, first_start_idx, first_end_idx, comp_num, pivot_choice);
    }
    if(sec_end_idx > sec_start_idx){
        quickSortRecur(input_arr, sec_start_idx, sec_end_idx, comp_num, pivot_choice);
    }
}

//solution.cpp
#include <solution.h>

/*
int inverseNumberIterative(const std::vector<int> &input_arr, const int start_idx, const int end_idx, std::vector<int> &sorted_arr){
    std::pair<int, int> idx_pair = std::make_pair(start_idx, end_idx);
    std::stack< std::pair<int, int> > divide_stack;
    std::stack< std::pair<int, int> > conquer_stack;

    divide_stack.push(idx_pair);
    while(!divide_stack.empty()){
        std::pair<int, int> cur_idx = divide_stack.top();
        int start_idx = cur_idx.first;
        int end_idx   = cur_idx.second;
        divide_stack.pop();


    
    }


}

//Divide and Conquer
void inverseNumber(const std::vector<int> &input_arr, int &inv_num){
    std::vector<int> sorted_arr1;
    std::vector<int> sorted_arr2;
    int input_arr_size = int(input_arr.size());

    int inv_num1 = inverseNumberIterative(input_arr, 0,                  input_arr_size/2, sorted_arr1);
    int inv_num2 = inverseNumberIterative(input_arr, input_arr_size/2+1, input_arr_size-1, sorted_arr2);

}
*/

void inverseNumberCountSplit(const std::vector<int> &sorted_arr_l, const std::vector<int> &sorted_arr_r, std::vector<int> &sorted_arr, long &inv_num){
    size_t idx_l = 0;
    size_t idx_r = 0;

    while((idx_r < sorted_arr_r.size()) && (idx_l < sorted_arr_l.size())){
        if(sorted_arr_l[idx_l] <= sorted_arr_r[idx_r]){
            sorted_arr.push_back(sorted_arr_l[idx_l]);
            ++idx_l;
        }else{
            sorted_arr.push_back(sorted_arr_r[idx_r]);
            ++idx_r;
            inv_num += sorted_arr_l.size() - idx_l;
        }
    }

    if(idx_r < sorted_arr_r.size()){
        for(size_t i = idx_r;i<sorted_arr_r.size();++i){
            sorted_arr.push_back(sorted_arr_r[i]);
        }
    }

    if(idx_l < sorted_arr_l.size()){
        for(size_t i = idx_l;i<sorted_arr_l.size();++i){
            sorted_arr.push_back(sorted_arr_l[i]);
        }
    }

}

void inverseNumberCount(const std::vector<int> &input_arr, const int &start_idx, const int &end_idx, long &inv_num, std::vector<int> &sorted_arr){
    if(start_idx == end_idx){
        sorted_arr.push_back(input_arr[start_idx]);
        inv_num = 0;
        return;
    }
    
    long inv_num_cur = 0;
    long inv_num_l = 0;
    long inv_num_r = 0;
    std::vector<int> sorted_arr_l;
    std::vector<int> sorted_arr_r;
    int mid_idx = (start_idx + end_idx)/2;

    inverseNumberCount(input_arr, start_idx, mid_idx, inv_num_l, sorted_arr_l);
    inverseNumberCount(input_arr, mid_idx+1, end_idx, inv_num_r, sorted_arr_r);
    inverseNumberCountSplit(sorted_arr_l, sorted_arr_r, sorted_arr, inv_num_cur);
    inv_num = inv_num_l + inv_num_r + inv_num_cur;
}



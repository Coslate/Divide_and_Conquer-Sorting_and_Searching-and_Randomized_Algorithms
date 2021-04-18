#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cfloat>
#include <utility>
#include <stack>


void inverseNumberCountSplit(const std::vector<int> &sorted_arr_l, const std::vector<int> &sorted_arr_r, std::vector<int> &sorted_arr, long &inv_num);

void inverseNumberCount(const std::vector<int> &input_arr, const int &start_idx, const int &end_idx, long &inv_num, std::vector<int> &sorted_arr);

#endif

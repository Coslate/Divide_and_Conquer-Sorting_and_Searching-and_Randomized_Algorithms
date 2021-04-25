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

void partitionSubroutine(std::vector<int> &input_arr, const int &start_idx, const int &end_idx, int &first_start_idx, int &first_end_idx, int &sec_start_idx, int &sec_end_idx, const int &pivot_val, const int &pivot_idx);

void pivotSelectionFirst(const std::vector<int> &input_arr, const int &start_idx, int &pivot_idx, int &pivot_val);

void pivotSelectionFinal(const std::vector<int> &input_arr, const int &end_idx, int &pivot_idx, int &pivot_val);

void pivotSelectionThreeMedian(const std::vector<int> &input_arr, const int &start_idx, const int &end_idx, int &pivot_idx, int &pivot_val);

void quickSortRecur(std::vector<int> &input_arr, const int &start_idx, const int &end_idx, int &comp_num, const int &pivot_choice);

#endif

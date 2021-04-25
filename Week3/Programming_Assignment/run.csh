#! /bin/csh -f

make clean
make

#./main ./test3.txt -pivot choose_first_pivot > ./ans.first.test3.log
#./main ./test3.txt -pivot choose_last_pivot > ./ans.last.test3.log
#./main ./test3.txt -pivot choose_median_three_pivot > ./ans.median.test3.log
./main ./QuickSort.txt -pivot choose_first_pivot > ./ans.log
./main ./QuickSort.txt -pivot choose_last_pivot >> ./ans.log
./main ./QuickSort.txt -pivot choose_median_three_pivot >> ./ans.log

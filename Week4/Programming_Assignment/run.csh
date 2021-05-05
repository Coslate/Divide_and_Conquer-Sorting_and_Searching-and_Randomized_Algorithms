#! /bin/csh -f

make clean
make


#run formal released case
./main ./kargerMinCut.txt > ./ans.log

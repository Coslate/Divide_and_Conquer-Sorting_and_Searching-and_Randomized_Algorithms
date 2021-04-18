#! /bin/csh -f

make clean
make

#./main ./test.txt
./main ./IntegerArray.txt  > ./ans.log

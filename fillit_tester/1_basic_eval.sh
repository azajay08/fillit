#! /usr/bin/env bash

make re -C ../
echo "\n\n\n\n\n"
cat testfiles/tetris
echo 
echo $(printf "\e[4;1;45mBASIC EVALUATION TESTS\e[0m")
echo ------------------------------------------
echo $(printf "\e[4;1;35mTEST 1 INVALID PIECE\e[0m")
echo ------------------------------------------
cat testfiles/testf
echo 
echo ------------------------------------------
echo $(printf "\e[4;1;32mEXPECTED:\e[0m")
echo 
echo error
echo ------------------------------------------
echo $(printf "\e[4;1;33mRESULT:\e[0m")
echo 
.././fillit testfiles/testf
echo ------------------------------------------
echo $(printf "\e[4;1;35mTEST 1 PIECE\e[0m")
echo ------------------------------------------
cat testfiles/test1
echo
echo ------------------------------------------ 
echo $(printf "\e[4;1;32mEXPECTED:\e[0m")
echo 
echo AA
echo AA
echo ------------------------------------------
echo $(printf "\e[4;1;33mRESULT:\e[0m")
echo 
time .././fillit testfiles/test1
echo ------------------------------------------
echo $(printf "\e[4;1;35mTEST MULTIPLE PIECEs\e[0m")
echo ------------------------------------------
cat testfiles/test2
echo 
echo ------------------------------------------
echo $(printf "\e[4;1;32mEXPECTED:\e[0m")
echo 
echo ABBBB.
echo ACCC..
echo AGGCDD
echo A.GDD.
echo EEGFF.
echo EE..FF
echo 
echo ------------------------------------------
echo $(printf "\e[4;1;33mRESULT:\e[0m")
echo 
time .././fillit testfiles/test2
echo ------------------------------------------
echo $(printf "\e[4;1;35mTEST 4 TOO MANY ARGUMENTS\e[0m")
echo ------------------------------------------
echo $(printf "\e[4;1;32mEXPECTED:\e[0m")
echo 
echo usage: "./fillit [input_file]"
echo ------------------------------------------
echo $(printf "\e[4;1;33mRESULT:\e[0m")
echo 
.././fillit testfiles/testf testfiles/test1
echo ------------------------------------------
echo $(printf "\e[4;1;35mTEST 5 TOO FEW ARGUMENTS\e[0m")
echo ------------------------------------------
echo $(printf "\e[4;1;32mEXPECTED:\e[0m")
echo 
echo usage: "./fillit [input_file]"
echo ------------------------------------------
echo $(printf "\e[4;1;33mRESULT:\e[0m")
echo 
.././fillit
echo ------------------------------------------
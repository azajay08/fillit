#! /usr/bin/env bash

make re -C ../
echo "\n\n\n\n\n"
cat testfiles/tetris
echo 
echo $(printf "\e[4;1;45mERROR HANDLING TESTS\e[0m")
echo ------------------------------------------
echo $(printf "\e[4;1;35mTEST 1 INVALID PIECE\e[0m")
echo ------------------------------------------
cat testfiles/error1
echo 
echo ------------------------------------------
echo $(printf "\e[4;1;32mEXPECTED:\e[0m")
echo 
echo error
echo ------------------------------------------
echo $(printf "\e[4;1;33mRESULT:\e[0m")
echo 
.././fillit testfiles/error1
echo ------------------------------------------
echo $(printf "\e[4;1;35mTEST 2 INVALID PIECE\e[0m")
echo ------------------------------------------
cat testfiles/error2
echo 
echo ------------------------------------------
echo $(printf "\e[4;1;32mEXPECTED:\e[0m")
echo 
echo error
echo ------------------------------------------
echo $(printf "\e[4;1;33mRESULT:\e[0m")
echo 
.././fillit testfiles/error2
echo ------------------------------------------
echo $(printf "\e[4;1;35mTEST 3 INVALID PIECE\e[0m")
echo ------------------------------------------
cat testfiles/error3
echo 
echo ------------------------------------------
echo $(printf "\e[4;1;32mEXPECTED:\e[0m")
echo 
echo error
echo ------------------------------------------
echo $(printf "\e[4;1;33mRESULT:\e[0m")
echo 
.././fillit testfiles/error3
echo ------------------------------------------
echo $(printf "\e[4;1;35mTEST 4 INVALID PIECE\e[0m")
echo ------------------------------------------
cat testfiles/error4
echo 
echo ------------------------------------------
echo $(printf "\e[4;1;32mEXPECTED:\e[0m")
echo 
echo error
echo ------------------------------------------
echo $(printf "\e[4;1;33mRESULT:\e[0m")
echo 
.././fillit testfiles/error4
echo ------------------------------------------
echo $(printf "\e[4;1;35mTEST 5 INVALID PIECE\e[0m")
echo ------------------------------------------
cat testfiles/error5
echo 
echo ------------------------------------------
echo $(printf "\e[4;1;32mEXPECTED:\e[0m")
echo 
echo error
echo ------------------------------------------
echo $(printf "\e[4;1;33mRESULT:\e[0m")
echo 
.././fillit testfiles/error5
echo ------------------------------------------
echo $(printf "\e[4;1;35mTEST 6 INVALID PIECES\e[0m")
echo ------------------------------------------
cat testfiles/error6
echo 
echo ------------------------------------------
echo $(printf "\e[4;1;32mEXPECTED:\e[0m")
echo 
echo error
echo ------------------------------------------
echo $(printf "\e[4;1;33mRESULT:\e[0m")
echo 
.././fillit testfiles/error6
echo ------------------------------------------
echo $(printf "\e[4;1;35mTEST 7 INVALID SPACING\e[0m")
echo ------------------------------------------
cat testfiles/error7
echo 
echo ------------------------------------------
echo $(printf "\e[4;1;32mEXPECTED:\e[0m")
echo 
echo error
echo ------------------------------------------
echo $(printf "\e[4;1;33mRESULT:\e[0m")
echo 
.././fillit testfiles/error7
echo ------------------------------------------
echo $(printf "\e[4;1;35mTEST 8 INVALID CHARACTER\e[0m")
echo ------------------------------------------
cat testfiles/errorchar
echo 
echo ------------------------------------------
echo $(printf "\e[4;1;32mEXPECTED:\e[0m")
echo 
echo error
echo ------------------------------------------
echo $(printf "\e[4;1;33mRESULT:\e[0m")
echo 
.././fillit testfiles/errorchar
echo ------------------------------------------
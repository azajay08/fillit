#! /usr/bin/env bash

make re -C ../
echo "\n\n\n\n\n"
cat testfiles/tetris
echo 
echo $(printf "\e[4;1;45mRANDOM SOLVERS\e[0m")
echo ------------------------------------------
echo $(printf "\e[4;1;35mTEST 1\e[0m")
echo ------------------------------------------
cat testfiles/random1
echo 
echo ------------------------------------------
echo $(printf "\e[4;1;32mEXPECTED:\e[0m")
echo 
echo ABBBBDD
echo ACCCDDE
echo AF.C..E
echo AFGGG.E
echo .FFGHHE
echo II..HH.
echo II.....
echo ------------------------------------------
echo $(printf "\e[4;1;33mRESULT:\e[0m")
echo 
time .././fillit testfiles/random1
echo ------------------------------------------
echo $(printf "\e[4;1;35mTEST 2\e[0m")
echo ------------------------------------------
cat testfiles/random2
echo 
echo ------------------------------------------
echo $(printf "\e[4;1;32mEXPECTED:\e[0m")
echo 
echo B...A
echo BCCAA
echo B.CCA
echo BEDDD
echo EEE.D
echo ------------------------------------------
echo $(printf "\e[4;1;33mRESULT:\e[0m")
echo 
time .././fillit testfiles/random2
echo ------------------------------------------
echo $(printf "\e[4;1;35mTEST 3\e[0m")
echo ------------------------------------------
cat testfiles/random3
echo 
echo ------------------------------------------
echo $(printf "\e[4;1;32mEXPECTED:\e[0m")
echo 
echo ABBBBE
echo A.CCCE
echo AGGGCE
echo AFGDDE
echo .FDDHH
echo .FF.HH
echo ------------------------------------------
echo $(printf "\e[4;1;33mRESULT:\e[0m")
echo 
time .././fillit testfiles/random3
echo ------------------------------------------

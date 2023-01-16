#! /usr/bin/env bash

make re -C ../
echo "\n\n\n\n\n"
cat testfiles/tetris
echo 
echo $(printf "\e[4;1;45mEVERY PIECE SOLVER\e[0m")
echo ------------------------------------------
cat testfiles/everypiece
echo 
echo ------------------------------------------
echo $(printf "\e[4;1;32mEXPECTED:\e[0m")
echo ABBBBCD..
echo AEEG.CDDD
echo AE.GCCFFF
echo AEPGGOOOF
echo NPPJJJOII
echo NNPJHKK.I
echo NSHHHKKMI
echo SSLLQRRMM
echo SLLQQQRRM
echo 
echo ------------------------------------------
cat testfiles/CBS
echo 
echo $(printf "\e[4;1;33mRESULT:\e[0m")
echo 
time .././fillit testfiles/everypiece
echo ------------------------------------------
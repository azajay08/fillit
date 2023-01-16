#! /usr/bin/env bash

make re -C ../
echo "\n\n\n\n\n"
cat testfiles/tetris
echo 
echo $(printf "\e[4;1;45m26 PIECE SOLVER\e[0m")
echo ------------------------------------------
cat testfiles/26piece.txt
echo 
echo ------------------------------------------
echo $(printf "\e[4;1;32mEXPECTED:\e[0m")
echo ABBBBCCCCDD
echo AEFFFFGIDD.
echo AE.HH.GIKKK
echo AEHH..GI..K
echo MEJJJJGILLP
echo MNNNNQ.LL.P
echo MOOOOQSSSSP
echo MRU..QTTTTP
echo .RU..QVVVV.
echo .RUWWWWXXXX
echo .RUYYYYZZZZ
echo 
echo ------------------------------------------
cat testfiles/CBS
echo 
echo $(printf "\e[4;1;33mRESULT:\e[0m")
echo 
time .././fillit testfiles/26piece.txt
echo ------------------------------------------
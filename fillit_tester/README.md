# fillit_tester - 42 (Hive Helsinki) 🧩
This is a tester for the 42 (Hive Helsinki) project - fillit

This is a combination of tests for the project fillit. It includes 
the basic evaluation tests, some error handling tests, some random
solver tests, a test for every possible valid piece and a test for
26 pieces. Also includes a timer ⏲️

# Instructions
`git clone https://github.com/azajay08/fillit_tester.git fillit_tester`  
into the root of your project. `cd` into the fillit_tester directory  
To run the tests, for example type, `sh 1basic_eval.sh`
There are 5 sets of tests in total, so just type the test file after the `sh`. It works if the `Makefile` is in the root of the project, if not, just change the path on the `sh` files.

# Evaluation
The `1basic_eval.sh` test runs some of the same files as the evaluation tests.  
The test with just 1 piece must be solved in under 1 second. The test with 7 pieces has a bonus grading system as so.  
30 seconds+ -> 0 pts 🐢  
20-30 seconds -> 1 pt  
10-20 seconds -> 2 pt  
5-10 seconds -> 3pt  
1-5 seconds -> 4pt  
< 1 second -> 5 pt 🚀

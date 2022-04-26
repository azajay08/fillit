# fillit - 42 (Hive Heslinki) 🧩
Fillit is a paired group project. The goal is to take a file as an argument which contains valid Tetris pieces up to the count of 26, and fits them into the smallest square possible. Valid pieces are considered as such:  

<img width="314" alt="Screenshot 2022-04-26 at 16 09 56" src="https://user-images.githubusercontent.com/86073849/165307710-7249ec80-f406-4d1a-88dd-83173fd5f167.png">  

A valid piece can only be made up of `#` and `.`. Anything else will be considered invalid and it will show as an `error`. When the program has taken a file as an argument containing only valid pieces, it then parses the pieces and changes the `#` into capital alphabetical characters in order, hence why only 26 pieces max can be considered valid. Each piece in the file must be separated by a new line, if it isn't, it will be considered invalid and will show an `error`. If a piece is separated by more than one new line, it will considered invalid and display `error` If you feed the executable something other than 1 existng file as an argument, it will display its correct usage `usage: ./fillit <input_file>`

## Evaluation
....  
....  
..##  
..##  

^^This test with just 1 piece must be solved in under 1 second. The test with 7 random pieces has a bonus grading system as so.  
30 seconds+ -> 0 pts 🐢  
20-30 seconds -> 1 pt  
10-20 seconds -> 2 pt  
5-10 seconds -> 3pt  
1-5 seconds -> 4pt  
< 1 second -> 5 pt 🚀


`cd`

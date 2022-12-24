# fillit - 42 (Hive Helsinki) 🧩  

<p align="center">
<img src="https://user-images.githubusercontent.com/86073849/209414432-65b5c7cd-72ea-4e09-a8a8-88c917154b0b.png" alt="cube" width="400"/>
</p>
  
Fillit is a paired group project at Hive Helsinki(42). As with all Hive projects, they come with restraints and limitations. We have to abide by the rules of `Norminette`. Here are some of the rules we must follow:

```
* The mandatory part must be written in C
* 25 lines maximum per function
* 5 functions maximum per file
* 80 columns wide maximum
* 5 variables per function maximum
* For loops are forbidden
* Declaration and an initialisation cannot be on the same line
* A function can take 4 named parameters maximum
* Functions allowed:
  * write
  * malloc
  * free
  * read
  * open
  * close
  * exit
```
The goal is to take a file as an argument which contains valid Tetris pieces up to the count of 26, and fit them into the smallest square possible. It is basically a Tetris solver. Valid pieces are considered as such:  

<img width="314" alt="Screenshot 2022-04-26 at 16 09 56" src="https://user-images.githubusercontent.com/86073849/165307710-7249ec80-f406-4d1a-88dd-83173fd5f167.png">  

A valid piece can only be made up of `#` and `.`. Anything else will be considered invalid and it will show as an `error`. When the program has taken a file as an argument containing only valid pieces, it then parses the pieces and changes the `#` into capital alphabetical characters in order, hence why only 26 pieces max can be considered valid. Each piece in the file must be separated by a new line, if it isn't, it will be considered invalid and will show an `error`. If a piece is separated by more than one new line, it will considered invalid and display `error` If you feed the executable something other than 1 existng file as an argument, it will display its correct usage:  
`usage: ./fillit <input_file>`. Providing that the pieces are valid, when it is solved, it will look something like this...  


<img width="125" alt="Screenshot 2022-04-26 at 17 03 23" src="https://user-images.githubusercontent.com/86073849/165317940-f2d2f753-f400-4bca-aecd-849d10558980.png">  

## Evaluation
In this evaluation, there are a few test files provided. These will test a single valid piece(shown below), a test file containing 7 random simple valid pieces, and some invalid pieces to test.  

This test with just 1 piece must be solved in under 1 second...  
<img width="127" alt="Screenshot 2022-04-26 at 16 50 10" src="https://user-images.githubusercontent.com/86073849/165315128-037754f3-7dff-4596-834f-de1b364e5a19.png">  

There is a test file with 7 random pieces, when solved looks like this...  
<img width="127" alt="Screenshot 2022-04-26 at 16 46 29" src="https://user-images.githubusercontent.com/86073849/165314438-b6759bf8-37c5-4e29-8df4-bbabe8ec6e4a.png">  
This has a bonus grading system, these are the time limits for solving:  
30 seconds+ -> 0 pts 🐢  
20-30 seconds -> 1 pt  
10-20 seconds -> 2 pt  
5-10 seconds -> 3pt  
1-5 seconds -> 4pt  
< 1 second -> 5 pt 🚀  

Our project scored 5 bonus points for this part. If we tested it with every possible piece(19 different tetriminos), it would solve it in just under 10 seconds.



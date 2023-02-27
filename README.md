# Gradebook

## Summary
Our project utilizes an input file, along with user input, in order to create an output that would inform the user about their requested grades. Through this project the user can change any specific grade, and/or add a new grade to any category in the input file. Once changes to the input file are complete, the user can choose to return just a name of an assignment and its grade, or each grade in a chosen category along with its total. If the user chooses the course option, they have three choices: each grade in the category and the overall course grade, each overall category grade and then the course grade, or just the course grade. The user can choose as many of these options as they choose as the program will not close until they choose to quit. 

## Compilation Instructions

To compile this program you will need an IDE, such as CLion, that has a c++ compiler, such as GNU with g++. You will then need to bring main.cpp, gradebook.cpp, gradebook.h, and any text files which would contain your grades into the same directory within your IDE of choice. You will then have to type "g++ -std=c++11 main.cpp gradebook.cpp -o gradebook" into the terminal order to compile your code into an executable file called 'gradebook'.

## Runtime Instructions
Command Line Arguments
runtime instructions

## Planning

For our gradebook we knew we were in for a large program with plenty of chances for issues. Due to this, we decided that it would be best
if we all got together to plan and write out pseudocode before anything else. After we had reached a plan we were comfortable with, it was time
start implementing. We thought it would be best to code in CS50, that way we would all be able to be in the file and making changes at the same time. 
Using this, we were all able to meet up and code together without being in eachothers way and not sharing our laptop when explaining an issue we were having. Our next issue was breaking up the code so everyone had an even portion of work. After plenty of deliberation, our best plan was as follows:

Addie: Finding the individual grade of an assignment. 
Cassidy: Finding the overall grade of a category of assignments. 
Chace: Finding the overall course grade, dropping the lowest lab, creating an outfile. 
Jordan: Putting everything together in the main file, making the code user friendly, and error handling. 
We found that this plan of action worked best and while we helped eachother in our respective sections, we stuck to our plan.

## Video Link for Presentation
https://youtu.be/hdTI5UHsdtA

## Sample Screenshots
1
This is our starting file before any code is run.

2
In this screenshot we added a grade to the end of the Labs category. Input a 1 in the first menu to add a grade, then input the category that you would like to add the grade to. Then, input the value of the new grade, which in this case is 100.

3
In this screenshot we changed a grade in the Assignments category. Input a 2 in the first menu to change a grade, then input the name of the category that you would like to change a grade in. Then, input the assignment number that you would like to change and the new grade when prompted, which in this case is 70. 

4
In this screenshot, we asked the program to display an individual assignment and grade. We don’t want to manipulate the text file so we skip past the first menu, and input a 1 to choose Individual. Then, input the name of the assignment using the specified format, and it returns the assignment name and the amount of points granted for that assignment.

5
In this screenshot, we asked the program to display a category of grades. Again, we don’t want to manipulate the text file so we skip past the first menu. Then, input 2 to choose Category, and enter the category using the specified format. It then returns a list of the amount of points granted for each assignment and the total number of points granted out of the total amount of points possible for that category.

6
In this screenshot, we are asking the program to display all grades within each category along with a total course grade. We skip past the first menu and input a 3 in the second menu to see Course options. We then choose 1 for all grades within their categories and overall, and it returns every grade in the text file in the form of the amount of points granted as well as the total out of the total amount of points possible.

7
In this screenshot, we ask the program to output category totals and course total. We skip the first menu and input a 3 in the second menu for Course options. We then input a 2 for category and course totals, and it returns a list of each category, the amount of points earned out of the total amount of points possible, and the total earned points out of total amount of points possible.

8
In this screenshot, we ask the program to just display the course total overall. We skip the first menu again, input a 3 for Course options, then input a 3 for course overall. The program then outputs the total amount of points earned out of the total possible points.

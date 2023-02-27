# Gradebook

## Summary
Our project utilizes an input file, along with user input, in order to create an output that would inform the user about their requested grades. Through this project the user can change any specific grade, and/or add a new grade to any category in the input file. Once changes to the input file are complete, the user can choose the individual option to return just a name of an assignment and its grade, or the cateogry option to see each grade in a chosen category along with its total. If the user chooses the course option, they have three choices: each grade in the category and the overall course grade, each overall category grade and then the course grade, or just the course grade. The user can choose as many of these options as they choose as the program will not close until they choose to quit. 

## Compilation Instructions

To compile this program you will need an IDE, such as CLion, that has a c++ compiler, such as GNU with g++. You will then need to bring main.cpp, gradebook.cpp, gradebook.h, and any text files which would contain your grades into the same directory within your IDE of choice. You will then have to type "g++ -std=c++11 main.cpp gradebook.cpp -o gradebook" into the terminal order to compile your code into an executable file called 'gradebook'.

## Runtime Instructions

Once compiled, to run the program you just have to provide the input file name as a Command Line Argument. To do so, type in the terminal "\your input file" for instance you could run \Cassidys.txt and it will read into, and allow you to write into the file called Cassidys.txt. Once you run this line, you can start changing/adding grades and then selecting grade calculations of your choice. First to add a grade type "1", then you will be prompted to enter what category you would like to add a grade. If you would like to add a new lab, type "Labs", if you would like to add a project type "Projects", etc. (Note that there is only one exam so if you would like to add it, just type "Exam" in the singular form not plural). Then you will be asked what the score is that you would like to add, enter this score out of a 100% grading sceheme. To Change a grade type "2", you will then be prompted to enter which category you would like to change a grade in. For instance,  if you would like to change Lab 1, type "Labs". Then you will be prompted to enter which specific grade you would like to change so you would just enter "1" to signify Lab 1. Then you will be asked what the score is that you would like to change it too, enter this score out of a 100% grading sceheme. If you are done adding and changing grades in the txt file, type "3". Once you have typed "3" you will be prompted to select what computations you would like to complete with the grades. To get just the name of an assignment and its grade type "1". Once you do so you will be prompted to select which assignment you would like to see the grade of; for instance if you would like to see what you got on the first lab type "Lab1", to see what you got on the second project type "Project2", etc. In order to see each grade in a chosen category along with its total, type "2". You will then be prompted to enter which category you would like to see this information for so to see each lab grade and your overall grade in lab, type "Labs", for exam type "Exam", etc. For the overall course grade option type "3", from here you will be prompted with three smaller sub-options. To see each grade in the category and the overall course grade, type "1", to see each overall category grade and then the course grade type "2", and to see just the course grade, type "3". After you get the individual, cateogry, or course grades you requested you will be presented with the same menu of options. At this point you can either choose to complete another functionality using the instructions above, or you can quit by typing "4". 

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
<img width="468" alt="Screen Shot 2023-02-27 at 3 03 53 PM" src="https://user-images.githubusercontent.com/90719981/221709225-1a9f975b-29a5-42d3-b0bb-d9d6d5c7b760.png">
This is our starting file before any code is run.

<img width="1096" alt="Screen Shot 2023-02-27 at 3 04 29 PM" src="https://user-images.githubusercontent.com/90719981/221709348-785efcc9-d422-417a-87fc-6866d38014b7.png">
In this screenshot we added a grade to the end of the Labs category. Input a 1 in the first menu to add a grade, then input the category that you would like to add the grade to. Then, input the value of the new grade, which in this case is 100.

<img width="1085" alt="Screen Shot 2023-02-27 at 3 04 53 PM" src="https://user-images.githubusercontent.com/90719981/221709454-ff0dd65a-d9f1-4f23-b188-9f53f9a41ba2.png">
In this screenshot we changed a grade in the Assignments category. Input a 2 in the first menu to change a grade, then input the name of the category that you would like to change a grade in. Then, input the assignment number that you would like to change and the new grade when prompted, which in this case is 70. 

<img width="1094" alt="Screen Shot 2023-02-27 at 3 05 22 PM" src="https://user-images.githubusercontent.com/90719981/221708793-0dbedef5-09d7-40b0-b579-83704181ab50.png">
In this screenshot, we asked the program to display an individual assignment and grade. We don’t want to manipulate the text file so we skip past the first menu, and input a 1 to choose Individual. Then, input the name of the assignment using the specified format, and it returns the assignment name and the amount of points granted for that assignment.

<img width="1065" alt="Screen Shot 2023-02-27 at 3 05 58 PM" src="https://user-images.githubusercontent.com/90719981/221708814-15c3e960-bfa9-4608-9021-0f71dc63d936.png">
In this screenshot, we asked the program to display a category of grades. Again, we don’t want to manipulate the text file so we skip past the first menu. Then, input 2 to choose Category, and enter the category using the specified format. It then returns a list of the amount of points granted for each assignment and the total number of points granted out of the total amount of points possible for that category.

<img width="1073" alt="Screen Shot 2023-02-27 at 3 06 41 PM" src="https://user-images.githubusercontent.com/90719981/221708832-38bfc1f6-f28a-4dc3-bedb-6d564ae25328.png">
In this screenshot, we are asking the program to display all grades within each category along with a total course grade. We skip past the first menu and input a 3 in the second menu to see Course options. We then choose 1 for all grades within their categories and overall, and it returns every grade in the text file in the form of the amount of points granted as well as the total out of the total amount of points possible.

<img width="1104" alt="Screen Shot 2023-02-27 at 3 07 05 PM" src="https://user-images.githubusercontent.com/90719981/221708861-59b63669-6411-4ce3-a388-8fd917e0e4a2.png">
In this screenshot, we ask the program to output category totals and course total. We skip the first menu and input a 3 in the second menu for Course options. We then input a 2 for category and course totals, and it returns a list of each category, the amount of points earned out of the total amount of points possible, and the total earned points out of total amount of points possible.

<img width="1068" alt="Screen Shot 2023-02-27 at 3 07 58 PM" src="https://user-images.githubusercontent.com/90719981/221708879-8726fb4c-e843-40cd-874b-ef1eb492c39d.png">
In this screenshot, we ask the program to just display the course total overall. We skip the first menu again, input a 3 for Course options, then input a 3 for course overall. The program then outputs the total amount of points earned out of the total possible points.

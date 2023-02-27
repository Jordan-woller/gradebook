# Gradebook

## Summary
Our project utilizes an input file, along with user input, in order to create an output that would inform the user about their requested grades. Through this project the user can change any specific grade, and/or add a new grade to any category in the input file. Once changes to the input file are complete, the user can choose to return just a name of an assignment and its grade, or each grade in a chosen category along with its total. If the user chooses the course option, they have three choices: each grade in the category and the overall course grade, each overall category grade and then the course grade, or just the course grade. The user can choose as many of these options as they choose as the program will not close until they choose to quit. 

## Planning

For our gradebook we knew we were in for a large program with plenty of chances for issues. Due to this, we decided that it would be best
if we all got together to plan and write out pseudocode before anything else. After we had reached a plan we were comfortable with, it was time
start implementing. We thought it would be best to code in CS50, that way we would all be able to be in the file and making changes at the same time. 
Using this, we were all able to meet up and code together without being in eachothers way and not sharing our laptop when explaining an issue we were having. Our next issue was breaking up the code so everyone had an even portion of work. After plenty of deliberation, our best plan was as follows.

Addie: Finding the individual grade of an assignment
Cassidy: Finding the overall grade of a category of assignments
Chace: Finding the overall course grade, dropping the lowest lab, creating an outfile
Jordan: Putting everything together in the main file, making the code user friendly, and error handling

We found that this plan of action worked best and while we helped eachother in our respective sections, we stuck to our plan.

## Compilation Instructions
compilation instructions

# Runtime Instructions
Once compiled, to run the program you just have to provide the input file name as a Command Line Argument. To do so, type in the terminal \"your input file" for instance you could run \Cassidys.txt and it will read into, and allow you to write into the file called Cassidys.txt. Once you run this line, you can start changing/adding grades and then selecting grade calculations of your choice. First to add a grade type "1", then you will be prompted to enter what category you would like to add a grade. If you would like to add a new lab, type "Labs", if you would like to add a project type "Projects", etc. (Note that there is only one exam so if you would like to add it, just type "Exam" in the singular form not plural). Then you will be asked what the score is that you would like to add, enter this score out of a 100% grading sceheme. To Change a grade type "2", you will then be prompted to enter which category you would like to change a grade in. For instance,  if you would like to change Lab 1, type "Labs". Then you will be prompted to enter which specific grade you would like to change so you would just enter "1" to signify Lab 1. Then you will be asked what the score is that you would like to change it too, enter this score out of a 100% grading sceheme. If you are done adding and changing grades in the txt file, type "3". Once you have typed "3" you will be prompted to select what computations you would like to complete with the grades. To get just the name of an assignment and its grade type "1". Once you do so you will be prompted to select which assignment you would like to see the grade of; for instance if you would like to see what you got on the first lab type "Lab1", to see what you got on the second project type "Project2", etc. In order to see each grade in a chosen category along with its total, type "2". You will then be prompted to enter which category you would like to see this information for so to see each lab grade and your overall grade in lab, type "Labs", for exam type "Exam", etc. For the overall course grade option type "3", from here you will be prompted with three smaller sub-options. To see each grade in the category and the overall course grade, type "1", to see each overall category grade and then the course grade type "2", and to see just the course grade, type "3". After you get the individual, cateogry, or course grades you requested you will be presented with the same menu of options. At this point you can either choose to complete another functionality using the instructions above, or you can quit by typing "4". 


Command Line Arguments
runtime instructions

# Video Link for Presentation
https://youtu.be/hdTI5UHsdtA



sample input/output screenshots with brief explanations of the images used

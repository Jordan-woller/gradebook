#include "gradebook.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>

int main(int argc, char* argv[]){
    //opens file and sets to input
    std::ifstream infile;
    infile.open(argv[1]);
    int *sum;

    std::string input, change;
    //main vector to hold all grades
    std::vector<std::vector<int>> mainvec;
    //labs, assignemnts, projects, final
    while(std::getline(infile, input)){
    // if there are no grades in a category, add 0 for the category
        if(input == ""){input += "0";}
        std::vector<int> tempVec;
        std::istringstream myStr(input);
        int value;
        // goes number by number and adds to tempVec
        while(myStr >> value){
            tempVec.push_back(value);
        }
        // adds category to mainvec
        mainvec.push_back(tempVec);
    }
    // if there is no input
    while(mainvec.size() < 4){
        std::vector<int> tempVec = {0};
        // makes all empty categories = 0
        mainvec.push_back(tempVec);
    }

    bool keepGoing = true;
    // working with mainvec for this
    while(keepGoing){
        std::cout << "Would you like to add or change any grades?" << std::endl;
        std::cout <<"Type 1 for add, 2 for change, or 3 if you're done."<< std::endl;
        std::string choice;
        std::cin >> choice;

        //if statement to add grades
        if (choice == "1"){
            std::cout << "What category would you like to add a grade to? \n(Labs, Assignments, Projects, or Exam?)";
            std::string category;
            std::cin>>category;
            int newGrade;
            bool choice = false;

            //adds grade to labs if not already full
            if (category == "Labs"){
                if((mainvec[0]).size() == 12){
                    std::cout << "This category is full! \nFeel free to change any grades!" << std::endl;
                    continue;
                }
                std::cout << "What is the value of the new grade?" << std::endl;
                while(!choice){
                    std::cin >> newGrade;
                    if (newGrade <= 100){
                        (mainvec[0]).push_back(newGrade);
                        choice = true;
                    }
                    else{std::cout << "Invalid grade!\nWhat is the value of the new grade" << std::endl;}
                }
            }

            //adds grade to assignments if not already full
            else if (category == "Assignments"){
                if((mainvec[1]).size() == 4){
                    std::cout << "This category is full! \nFeel free to change any grades!" << std::endl;
                    continue;
                }
                std::cout << "What is the value of the new grade?" << std::endl;
                while(!choice){
                    std::cin >> newGrade;
                    if (newGrade <= 100){
                        (mainvec[1]).push_back(newGrade);
                        choice = true;
                    }
                    else{std::cout << "Invalid grade!\nWhat is the value of the new grade" << std::endl;}
                }
            }

            //adds grade to projects if not already full
            else if (category == "Projects"){
                if((mainvec[2]).size() == 2){
                    std::cout << "This category is full! \nFeel free to change any grades!" << std::endl;
                    continue;
                }
                std::cout << "What is the value of the new grade?" << std::endl;
                while(!choice){
                    std::cin >> newGrade;
                    if (newGrade <= 100){
                        (mainvec[2]).push_back(newGrade);
                        choice = true;
                    }
                    else{std::cout << "Invalid grade!\nWhat is the value of the new grade" << std::endl;}
                }
            }

            //adds grade to exam if not already full
            else if (category == "Exam"){
                if((mainvec[3]).size() == 1){
                    std::cout << "This category is full! \nFeel free to change any grades!" << std::endl;
                    continue;
                }
                std::cout << "What is the value of the new grade?" << std::endl;
                while(!choice){
                    std::cin >> newGrade;
                    if (newGrade <= 100){
                        (mainvec[2]).push_back(newGrade);
                        choice = true;
                    }
                    else{std::cout << "Invalid grade!\nWhat is the value of the new grade" << std::endl;}
                }
            }
            //error handling
            else{std::cout << "Not a valid category!" << std::endl;}
        }

        //if statement to change grades
        else if(choice == "2"){
            std::cout << "In what category would you like to change a grade?\n(Labs, Assignments, Projects, or Exam?)" << std::endl;
            std::string category;
            std::cin>>category;
            int num;
            int newgrade;
            bool choice = false;

            //changes grade in lab category
            
            if (category == "Labs"){
                std::cout << "Which lab would you like to change?" << std::endl;
                while (!choice){
                    std::cin >> num;
                    if (num <= (mainvec[0]).size() && num > 0){
                        choice = true;
                    }
                    else{
                        std::cout << "Invalid choice!\nWhich lab would you like to change?" << std::endl;
                    }
                }
                std::cout << "What is the new grade?" << std::endl;
                std::cin >> newgrade;
                mainvec[0][num-1] = newgrade;
                
            }
            else if (category == "Assignments"){
                if (mainvec[1].empty()){
                    std::cout << "This category is empty!" << std::endl;
                    continue;
                }
                std::cout << "Which assignment would you like to change?" << std::endl;
                while (!choice){
                    std::cin >> num;
                    if (num <= (mainvec[1]).size() && num > 0){choice = true; }
                    else{std::cout << "Invalid choice!\nWhich assignment would you like to change?" << std::endl;}
                }
                std::cout << "What is the new grade?" << std::endl;
                std::cin >> newgrade;
                mainvec[1][num-1] = newgrade;
            }
            else if (category == "Projects"){
                if (mainvec[2].empty()){
                    std::cout << "This category is empty!" << std::endl;
                    continue;
                }
                std::cout << "Which project would you like to change?" << std::endl;
                while (!choice){
                    std::cin >> num;
                    if (num <= (mainvec[2]).size() && num > 0){choice = true;}
                    else{std::cout << "Invalid choice!\nWhich project would you like to change?" << std::endl;}
                }
                std::cout << "What is the new grade?" << std::endl;
                std::cin >> newgrade;
                mainvec[2][num-1] = newgrade;
            }
            else if (category == "Exam"){
                if (mainvec[3].empty()){
                    std::cout << "This category is empty!" << std::endl;
                    continue;
                }
                std::cout << "What is the new grade?" << std::endl;
                std::cin >> newgrade;
                mainvec[3][num-1] = newgrade;
            }
            else{std::cout << "Not a valid category!" << std::endl;}

        }
        else if(choice == "3"){
            keepGoing = false;
        }
        else{
            std::cout << "Invalid Choice Silly!" << std::endl;
        }
    }

    // constructor using mainvec as a parameter
    Gradebook myGrades(mainvec);
    
    // close input file, open output file (in the same file)
    infile.close();
    std::ofstream outfile;
    outfile.open(argv[1], std::ofstream::out | std::ofstream::trunc);
    
    // outputs all current grades to the outfile by reference
    myGrades.outGrades(outfile);


    keepGoing = true;
    while(keepGoing){
        std::cout << "What would you like to do? \n(Type 1, 2, 3, or 4)" << std::endl;
        std::cout << "1. Individual" << std::endl;
        std::cout << "2. Category" << std::endl;
        std::cout << "3. Course" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::string choice;
        std::cin >> choice;

        if (choice == "1"){
            std::cout << "Enter name using the format: Lab1, Assignment1, Project1, FinalExam.\n";
            std::string name;
            std::cin>>name;
            std::cout << name << " " << myGrades.Individual(name) << std::endl;
        }

        else if (choice == "2"){
            std::cout<<"Enter category using the format: Labs, Assignments, Projects, Exam.\n";
            std::string category;
            std::vector<int> temp;
            int total, *sum = &total, outOf;
            bool choice = false;

            while(!choice){
                std::cin>>category;
                if(category == "Labs"){outOf = 200;
                    choice = true;
                }
                else if(category == "Assignments"){outOf = 200;
                    choice = true;
                }
                else if(category == "Projects"){outOf = 500;
                    choice = true;
                }
                else if(category == "Exam"){outOf = 100;
                    choice = true;
                }
                else{std::cout << "Invalid chioce!" << std::endl;}
            }
            
            myGrades.Category(category,sum);
            temp = myGrades.GetCategoryVec(category);
            for(int i = 0; i < temp.size(); i++){
                std::cout << temp[i] << " ";
            }
            std::cout << "\nTotal: " << *sum << " out of " << outOf << std::endl;
        }

        else if (choice == "3"){
            int choice2;
            std::cout << std::endl;
            std::cout<<"1. all grades within their respective categories and a course overall"<<'\n';
            std::cout<<"2. OR only category totals and course overall"<< '\n';
            std::cout<<"3. OR only the course overall"<< '\n';
            std::cin >> choice2;

            if(choice2==1){
                std::vector<int> temp;

                temp = myGrades.GetCategoryVec("Labs");
                std::cout << "Labs: ";
                for(int i=0; i<temp.size(); i++){
                    std::cout << temp[i] << " ";
                }
                std::cout << std::endl;
                temp=myGrades.GetCategoryVec("Assignments");
                std::cout << "Assignments: ";
                for(int i=0; i<temp.size(); i++){
                    std::cout << temp[i] << " ";
                }
                std::cout << std::endl;
                temp=myGrades.GetCategoryVec("Projects");
                std::cout << "Projects: ";
                for(int i=0; i<temp.size(); i++){
                    std::cout << temp[i] << " ";
                }
                std::cout << std::endl;
                temp=myGrades.GetCategoryVec("Exam");
                std::cout << "Exam: ";
                std::cout << temp[0] << " ";

                std::cout << std::endl;
                int courseTot = myGrades.Course();
                std::cout << "Total: " << courseTot << " out of 1000" << std::endl;

            }else if(choice2==2){
                int total, *sum = &total, outOf;
                std::vector<int> temp;
                outOf = 200;
                temp = myGrades.Category("Labs", sum);
                std::cout << "\nLabs: " << *sum << " out of " << outOf << std::endl;

                temp = myGrades.Category("Assignments", sum);
                std::cout << "Assignments: " << *sum << " out of " << outOf << std::endl;

                outOf = 500;
                temp = myGrades.Category("Projects", sum);
                std::cout << "Projects: " << *sum << " out of " << outOf << std::endl;

                outOf = 100;
                temp = myGrades.Category("Exam", sum);
                std::cout << "Exam: " << *sum << " out of " << outOf << std::endl;

                outOf = 1000;
                int courseTot = myGrades.Course();
                std::cout << "Total: " << courseTot << " out of " << outOf << std::endl;

            }else if(choice2==3){
                int courseTot;
                courseTot = myGrades.Course();
                std::cout << "\nTotal: " << courseTot << " out of 1000" << std::endl;

            }else{
                std::cout << "Invalid Choice Silly!" << std::endl;
            }

        }

        else if (choice == "4"){
            keepGoing = false;
        }

        else{
            std::cout << "Invalid Choice Silly!" << std::endl;
        }

    }

    outfile.close();
    return 0;
}

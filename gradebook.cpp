#include "gradebook.h"
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>

//default constructor
Gradebook::Gradebook(){
    std::vector<std::vector<int>> all_grades;
    this->all_grades = all_grades;
}

//constructor with one vector parameter
Gradebook::Gradebook(std::vector<std::vector<int>> &mainvec){
    this->all_grades = mainvec;
}

//returns individual deliverable name and grade
/*
uses the length of the inputted name of the category to determine which category
the user wants to see a grade from. The number at the end of the category name
is appended to the string 'value' and then turned into an integer to store which
lab, assignment, project, or exam the user wants to see, and the grade is accessed
from the category vector.
*/
int Gradebook::Individual(std::string name){
    //if statement returns grade of specified lab
    if(name.length() == 4 || name.length() == 5){ 
        std::vector<int> categoryVec;
        std::string value = "";
        if (name.size() == 4){ 
            value += name[3];
            }
        else{
            value += name[3];
            value += name[4];
        }
        int num = std::stoi(value);
        categoryVec = GetCategoryVec("Labs");
        int grade = categoryVec[num-1];
        return grade;
    }
    //if statement returns grade of specified assignment
    else if(name.length() == 11){
        std::vector<int> categoryVec;
        std::string value = "";
        value += name[10];
        int num = std::stoi(value);
        categoryVec = GetCategoryVec("Assignments");
        int grade = categoryVec[num-1];
        return grade;
    }
    //if statement returns grade of specified project
    else if(name.length() == 8){
        std::vector<int> categoryVec;
        std::string value = "";
        value += name[7];
        int num = std::stoi(value);
        categoryVec = GetCategoryVec("Projects");
        int grade = categoryVec[num-1];
        return grade;
    }
    //if statement returns grade of only exam
    else{
        std::vector<int> categoryVec;
        categoryVec = GetCategoryVec("Exam");
        int grade = categoryVec[0];
        return grade;
    }
}

// returns grade in the course
// calls all 4 categories in order to get access to each total
// adds together all totals and returns it
int Gradebook::Course(){
    int classTotal = 0, amount;
    int *sum = &amount;
    
    Category("Labs",sum);
    classTotal += *sum;
    
    Category("Assignments",sum);
    classTotal += *sum;
    
    Category("Projects",sum);
    classTotal += *sum;
    
    Category("Exam",sum);
    classTotal += *sum;
    
    return classTotal;
}

//GetCategoryVec takes in the name of the category the user chooses (Labs, Exam, etc.)
//And returns a vector containing all of the grades in that category
std::vector<int> Gradebook::GetCategoryVec(std::string category){
    std::vector<int> categoryVec;
    
    //If the user chooses labs,use the first vector within the 2D vector all_grades
    if (category == "Labs"){
        std::vector<int> categoryVec(all_grades[0]);
        
        //Loop through this vector and convert each score from scores out of 100 to scores out of 20
        for(int i=0; i < categoryVec.size(); i++){
            categoryVec[i]=((categoryVec[i]*20)/100);
        }
        return categoryVec;
        
     //If the user chooses Assignments,use the second vector within the 2D vector all_grades
    }else if (category == "Assignments"){
        std::vector<int> categoryVec(all_grades[1]);
        
        //Loop through this vector and convert each score from scores out of 100 to scores out of 50
        for(int i=0; i < categoryVec.size(); i++){
            categoryVec[i]=((categoryVec[i]*50)/100);
        }
        return categoryVec;
    }
    //If the user chooses Projects,use the third vector within the 2D vector all_grades
    else if (category == "Projects"){
        std::vector<int> categoryVec(all_grades[2]);

        //fills all empty project grades with 0
        while(categoryVec.size() != 2){
            categoryVec.push_back(0);
        }
        //convert the first Project from a score out of 100 to a score out of 150
        categoryVec[0]=((categoryVec[0]*150)/100);
        
        //convert the first Project from a score out of 350 to a score out of 350
        categoryVec[1]=((categoryVec[1]*350)/100);
        return categoryVec;
    }
    
    //If the user chooses Exams,use the fourth vector within the 2D vector all_grades
    else if (category == "Exam"){
        std::vector<int> categoryVec(all_grades[3]);
        return categoryVec;
    }
    
    //Error handling if valid category is not entered
    else{
        std::cout << "Not a valid category!" << std::endl;
    }
    return categoryVec;
}


//takes in category and returns all grades from category and the sum of the grades
std::vector<int> Gradebook::Category(std::string category, int *sum){
    std::vector<int> categoryVec;
    
    //If user selects "Labs" call GetCategoryVec to accordingly to get appropriate vector
    if (category == "Labs"){
        categoryVec = GetCategoryVec("Labs");
        int total = 0;
        
        //Call the DropLowest function twice to drop the two lowest labs 
        categoryVec = DropLowest(categoryVec);
        categoryVec = DropLowest(categoryVec);
        
        //Loop through the vector and add each grade to the sum
        for(int i=0; i < categoryVec.size(); i++){
            total += categoryVec[i];
        }
        *sum = total;
        return categoryVec;
        
    //If user selects "Assignments" call GetCategoryVec to accordingly to get appropriate vector
    }else if (category == "Assignments"){
        int total=0;
        categoryVec = GetCategoryVec("Assignments");
        
        //Loop through the vector and add each grade to the sum
        for(int i=0; i<categoryVec.size(); i++){
            total+=categoryVec[i];
        }
        *sum=total;
        return categoryVec;
    }
    //If user selects "Projects" call GetCategoryVec to accordingly to get appropriate vector
    else if (category == "Projects"){
        int total=0;
        categoryVec = GetCategoryVec("Projects");
        
        //Loop through the vector and add each grade to the sum
        for(int i=0; i < categoryVec.size(); i++){
            total += categoryVec[i];
        }
        *sum = total;
        return categoryVec;
    }
    
    //If user selects "Exam" call GetCategoryVec to accordingly to get appropriate vector
    else if(category == "Exam"){
        std::vector<int> categoryVec(all_grades[3]);
        
        //Sum is just the grade of the exam
        *sum = all_grades[3][0];
        return categoryVec;
    }
    return categoryVec;
}

//Takes in vector of labs and removes the lowest one from the vector
std::vector<int> Gradebook::DropLowest(std::vector<int>temp){
    int lowest = temp[0];
    int index = 0;
    for(int i = 1 ; i < temp.size() ; i++){
        if(temp[i] < lowest){
            lowest = temp[i];
            index = i;
        }
    }
    temp.erase(temp.begin() + index);
    return temp;
}

// takes in a reference for the outfile
// goes through 2d vector and adds each grade to the outfile
void Gradebook::outGrades(std::ofstream& outfile){
    std::string myStr;
    for(int i = 0; i < (this->all_grades).size(); i++){
        std::vector<int> temp((this->all_grades)[i]);
        for(int j = 0; j < temp.size(); j++){
            outfile << temp[j] << " ";
        }
        outfile << "\n";
    }
}

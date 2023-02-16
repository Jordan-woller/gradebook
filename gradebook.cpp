#include "gradebook.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <cstring>

//default constructor
Gradebook::Gradebook(){
    this->num_categories =  4;
    std::vector<std::vector<int>> all_grade;
    this->all_grades = all_grade;
}

//constructor with one argument
Gradebook::Gradebook(std::vector<std::vector<int>> &grades){
    this->num_categories = 4;
    this->all_grades = grades;
}

//returns individual deliverable name and grade
int Gradebook::Individual(std::string name){
    //find name, return index in grade
    int grade;
    for(int i = 0 ; i < all_grades_names.size() ; i++){
        for (int j = 0 ; j < all_grades_names.size() ; j++){
            // if (strcmp(all_grades_names, name) == 0){
                // grade = all_grades_names[i][j];
            }
        }
    }
    return grade;
}

//

//takes in category and returns all grades from category
std::vector<int> Gradebook::Category(std::string category, std::vector<int> &vec){
    std::vector<int> categoryVec;
    if (category == "Labs"){
        categoryVec = vec[0];
        return categoryVec;
    }
    else if (category == "Assignments"){
        return vec[1];
    }
    else if (category == "Projects"){
        return vec[2];
    }

    else if(category == "Exam"){
        return vec[3];
    }


}
//returns grade in the course
int Gradebook::Course(){
    return this->classTotal;
}

//gets total and sets classTotal to it
// void Gradebook::findTotal(){

// }

//Takes in vector of quizzes and drops the lowest
void Gradebook::DropLowest(std::vector<int>temp){
    int lowest = temp[0];
    int index = 0;
    for(int i = 1 ; i < temp.size() ; i++){
        if(temp[i] < lowest){
            lowest = temp[i];
            index = i;
        }
    }
    temp.erase(temp.begin() + index);
}


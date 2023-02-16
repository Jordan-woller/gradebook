#include "gradebook.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>

int main(int argc, char* argv[]){ 
    std::ifstream myfile; 
    myfile.open(argv[1]);
    
    std::string input;
    std::vector<std::vector<int>> vector;
    while(std::getline(myfile, input)){ //labs, assignemnts, projects, final
        std::vector<int> tempVec;
        std::istringstream myStr(input);
        int value;
        while(myStr >> value){
            tempVec.push_back(value);
        }
        vector.push_back(tempVec);
    };
    
    Gradebook myGrades(vector);
    
    int vectorptr;

    
    
    
    std::vector<int> labs;
    std::vector<int> assignments;
    std::vector<int> projects;
    std::vector<int> exams;
    
    
    
    return 0;
}
// g++ -std=c++11 main.cpp gradebook.cpp -o gradebook
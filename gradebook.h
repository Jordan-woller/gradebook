#pragma once
#include <iostream>
#include <vector>

class Gradebook{
    private:
        // 2D vector used to store all grades in the gradebook
        std::vector<std::vector<int>> all_grades;
        
    public:
        //default constructor
        Gradebook();

        //constructor with premade categories
        Gradebook(std::vector<std::vector<int>> &grades);

        //returns individual deliverable name and grade
        int Individual(std::string name);

        //returns full grade in the course
        int Course();
        
        // returns vector of a single category
        std::vector<int> GetCategoryVec(std::string category);

        // takes in category and returns all grades from category
        // using in parameter *sum to save the total of that category
        std::vector<int> Category(std::string category, int *sum);

        

        //Takes in vector of labs and removes the lowest one from the vector
        std::vector<int> DropLowest(std::vector<int>temp);
        
        // takes in a reference for the outfile
        // goes through 2d vector and adds each grade to the outfile
        void outGrades(std::ofstream& outfile);
};


#pragma once
#include <iostream>
#include <vector>

class Gradebook{
    private:
        std::vector<std::vector<int>> all_grades;
        std::vector<std::vector<std::string>> all_grades_names;
        std::vector<int> labs;
        std::vector<int> assignments;
        std::vector<int> projects;
        std::vector<int> exams;
        unsigned int classTotal;
        unsigned int num_categories;
        
    public:
        //default constructor
        Gradebook();
        
        //constructor with premade categories
        Gradebook(std::vector<std::vector<int>> &grades);
        
        //returns individual deliverable name and grade
        int Individual(std::string name);
        
        //
        std::vector<int> SplitVector(int *vectorptr);
        
        //takes in category and returns all grades from category
        std::vector<int> Category(std::string category, std::vector<int> &vec);
        
        //
        int Course();
        
        //
        // void Gradebook::findTotal();
        
        //
        void DropLowest(std::vector<int>temp);
};

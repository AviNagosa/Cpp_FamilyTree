#pragma once

#include <string>


namespace family
{

    class Tree
    {
        public:
        std::string root;
        Tree* father;
        Tree* mother;
        
        // Init an empty tree:
        Tree(){};

        // Init a tree with one person
        Tree(std::string name)
        {
            root = name;
            father = NULL;
            mother = NULL;
        }

        ~Tree()
        {

        }

        Tree addFather(std::string, std::string);
        Tree addMother(std::string, std::string);

        void display();
        std::string relation(std::string);
        std::string find(std::string);
        Tree remove(std::string);
    };


}
#pragma once

#include <string>
using namespace std;

namespace family
{
    struct person
    {
      string name="";
      person * father=NULL;
      person *mother=NULL;
      int index=1;
    };
    

    class Tree
    {
        public:
        person * child;
        person * pointer;
         
        // Init an empty tree:
        Tree();

        // Init a tree with one person
        Tree(std::string name);

        ~Tree()
        {

        }

        Tree& addFather(std::string, std::string);
        Tree addMother(std::string, std::string);

        void display();
        std::string relation(std::string);
        std::string find(std::string);
        Tree remove(std::string);

        void search(person &child ,string name,int i);
      
        int get_index(string person_name);
    };


}
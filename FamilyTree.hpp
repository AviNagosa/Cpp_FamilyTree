#pragma once
#include <iostream>

using namespace std;

namespace family
{
    struct person
    {
      string name="";
      person* father=NULL;
      person* mother=NULL;
      int index=1;
    };
    

    class Tree
    {
        public:
        person* child;
        person* pointer;
         
        Tree();
        Tree(string name);
        ~Tree();

        Tree& addFather(string, string);
        Tree addMother(string, string);

        string relation(string);
        string find(string);
        void remove(string);

        void search(person &child ,string name,int i);
        int get_index(string person_name);
		
        void display();
        void display(string,person&,bool);
    };


}
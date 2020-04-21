#pragma once
#include <string>

namespace family
{
    struct person
    {
        std::string name, rel = "";
        person* father;
        person* mother;
        int index = 1;

        //empty constructor
        person()
        {
            name = "";
            father = mother = NULL;
        }

        //constructor
        person(std::string n)
        {
            name = n;
            father = mother = NULL;
        }

        //constructor
        person(std::string n, int i)
        {
            name = n;
            index = i;
            father = mother = NULL;
        }
    };
    

    class Tree
    {
        public:
        person* child;
        person* pointer;
         
        Tree();
        Tree(std::string name);
        ~Tree();

        Tree& addFather(std::string, std::string);
        Tree& addMother(std::string, std::string);

        std::string relation(std::string);
        std::string find(std::string);
        void find(person&, std::string);
        void remove(std::string);
        void remove(int,person&);

        void destroyTree(person*);

        void search(person&, std::string, int);
        int get_index(std::string);
		
        void display();
        void display(std::string, person*, bool);
    };


}
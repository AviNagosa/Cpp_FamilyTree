#pragma once
#include <string>

namespace family
{
    struct person
    {
      std::string name="",rel="";
      person* father;
      person* mother;
      int index=1;

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
        void find(person & p,std:: string s);
        void remove(std::string);
    

      
        void destroyTree(person*);

        void search(person & child ,std::string name,int i);
        int get_index(std::string person_name);
		
        void display();
        void display(std::string, person &p, bool b);
        void pointer_by_index(int index);
        void pointer_by_index(int index,person &p);
    };


}
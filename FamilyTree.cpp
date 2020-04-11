#include <stdexcept>
#include <iostream>

#include "FamilyTree.hpp"

#include <string>
using namespace std;

namespace family
{
     Tree::Tree()
   {
       
   }
   
   Tree::Tree(string name)
   { 
       person *p=new person();
       p->name=name;
    
       this->child=p;
    
   }

    Tree& Tree::addFather(string s, string f)
    {
         
        search(*child,s);

   
        person *p=new person();
        p->name=f;

        pointer->father=p;
     
        return *this;
    }

    Tree Tree::addMother(string s, string m)
    {
       search(*child,s);

   
        person *p=new person();
        p->name=m;

        pointer->mother=p;
     
        return *this;
    }

    void Tree::display()
    {

    }

    string Tree::relation(string a)
    {

        return "aaa";
    }

    string Tree::find(string a)
    {
        
        return "aaa";
    }
    // void Tree::print(person & child)
    // {

    // }
    void Tree:: search(person & child ,string name)
    {
         
         cout<<child.name<<"---->";
        if(child.name=="")
        {
           
            return ;
        }
        if(child.name==name)
        {
     
            // person *p=new person();
            // p->name=name;
            this->pointer=&child;
            return;
        }
         if(child.father!=NULL)
         {
            search(*child.father,name);
   
         }
       
         if(child.mother!=NULL)
         {
              search(*child.mother,name);
                
         }
      
        cout<<endl;
       
        
        return ;
    }

    Tree Tree::remove(string a)
    {

        Tree b;
        return b;
    }

}
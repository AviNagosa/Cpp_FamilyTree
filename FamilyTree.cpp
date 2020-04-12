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
         
        search(*child,s,1);

   
        person *p=new person();
        p->name=f;

        pointer->father=p;
     
        return *this;
    }

    Tree Tree::addMother(string s, string m)
    {
       search(*child,s,1);

   
        person *p=new person();
        p->name=m;

        pointer->mother=p;
     
        return *this;
    }

    void Tree::display()
    {

    }

    /*                                        relation

       index=i,
       gf=grandfather,
       gm=grandmother,
       g=great ,
       g-gf=great-grandfather
       g-gm=great-grandmother
    
                                                       i=1
                                                      (me)
                                                   /       \  
                                                 /          \
                                               i=2          i=3
                                             (father)      (mother)
                                             /    \        /         \
                                           i=4    i=5    i=6          i=7
                                         (gf)    (gm)  (gf)          (gm)
                                       /          /       \              \
                                    i=8       i=10        13             i=15
                                (g-gf)      (g-gf)       (g-gm)          (g-gm)   

                                    
       */
   
    string Tree::relation(string a)
    {
        int index=get_index(a);
        if(index==-1)return "unrelated";
        if(index==1)  return "me";  
        if(index==2) return "father";
        if(index==3) return "mother";
       
         
         string relation="";
         if(index%2==0) relation="grandfather";
         else relation="grandmother";
       
         for(int i=8;i<=index;i=i*2)
         {
             relation="great-"+relation;
             
         }
      
        return relation;
    }
    
    int Tree ::get_index(string person_name)
    {
        pointer=NULL;//Updating that the pointer is not currently pointing to anything
        
        search(*child,person_name,1);

        if(!pointer)return -1;//if the person is not exsits in the tree
        return pointer->index;
    }
    string Tree::find(string a)
    {
        
        return "aaa";
    }
    /*
     The function gets name from the tree and updates that pointr will point it out
    For starters the function gets the root and name we want to find
    With the help of a recursive search (search preorder) 
    in the tree as soon as we find the person we will update the pointer to point it out
    */
    void Tree:: search(person & child ,string name,int i)
    {
         child.index=i;
        //  cout<<child.name<<"---->";
        if(child.name=="")
        {
          
            return ;
        }
        if(child.name==name)
        {
     
            this->pointer=&child;
            return;
        }
         if(child.father!=NULL)
         {
            search(*child.father,name,(i*2));
   
         }
       
         if(child.mother!=NULL)
         {
              search(*child.mother,name,(i*2)+1);
                
         }
  
         
        
        return ;
    }

    Tree Tree::remove(string a)
    {

        Tree b;
        return b;
    }

}
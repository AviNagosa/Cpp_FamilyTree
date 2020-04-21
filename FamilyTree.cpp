#include <stdexcept>
#include <iostream>
#include "FamilyTree.hpp"

using namespace std;

namespace family
{
    //empty constructor
    Tree::Tree(){}

    //constructor
    Tree::Tree(string name)
    { 
       child = new person(name);
       child->rel="me";
    }

    //destractor
    Tree::~Tree()
    {
        destroyTree(child);
    } 


    //destractor for every node
    void Tree::destroyTree(person* node)
    {
        if (node!=NULL)
        {
            if(node->father!=NULL)
            {
                destroyTree(node->father);
            }
            if(node->mother!=NULL)
            {
                destroyTree(node->mother);
            }

           /////////////////////////////////////////
            pointer_by_index((node->index/2));//point to the son
            if(node->index%2==0)// check if to delete the father or mother
            {
                pointer->father=NULL;
            }
            else
            {
                pointer->mother=NULL;
            }
       ///////////////////////////////////////////////////     
                 
            
            delete node;

         
           
        }
      
    }



    Tree& Tree::addFather(string s, string f)
    {
        search(*child,s,1);

        person *p = new person();
        p->name=f;
        p->index=this->pointer->index*2;
        pointer->father=p;
         
  
        string relation=""; 
        if(p->index==2) relation= "father";
        else if(p->index==3) relation= "mother";
        else
        {

           if(p->index%2==0) relation="grandfather";
           else relation="grandmother";
       
           for(int i=8;i<=p->index;i=i*2)
           {
            relation="great-"+relation;
             
            }
        } 
        p->rel=relation;
            pointer=NULL;
        return *this;
    }



    Tree& Tree::addMother(string s, string m)
    {
        search(*child,s,1);

        person *p = new person();
        p->name=m;
        p->index=this->pointer->index*2+1;
        pointer->mother=p;
         
        
        string relation="";
        if(p->index==2) relation= "father";
        else if(p->index==3) relation= "mother";
        else
        {
           if(p->index%2==0) relation="grandfather";
           else relation="grandmother";
       
           for(int i=8;i<=p->index;i=i*2)
           {
            relation="great-"+relation;
             
            }
        } 
        p->rel=relation;
       pointer=NULL;
        return *this;
    }

   

    string Tree::relation(string a)
    {
        this->pointer=NULL;
 
       search(*child,a,1);
      
      if(this->pointer==NULL)
      {    
         pointer=NULL;
        return "unrelated";
      }
  
       string s=pointer->rel;
       pointer=NULL;
        return s;
    }



    void Tree::pointer_by_index(int index)
    {
        this->pointer=NULL;
       pointer_by_index(index,*child);
    }
    void Tree::pointer_by_index(int index ,person &child)
    {
       if(child.index==index)
       {
          this->pointer=&child;
          return;
       }
       if(child.father!=NULL)
       {
           pointer_by_index(index,*child.father);
       }
       if(child.mother!=NULL)
       {
           pointer_by_index(index,*child.mother);
       }
    }



    string Tree::find(string a)
    {
        find(*this->child,a);
        if(this->pointer==NULL)
      {    
         pointer=NULL;
        return "need throw exception";
      }
  
        string s=pointer->name;
        pointer=NULL;
        return s;
    }

    void Tree::find(person &child,string rel)
    {
       
  
        if(child.rel=="")
        {
          
            return ;
        }
        if(child.rel==rel)
        {
            this->pointer=&child;
            return;
        }
        if(child.father!=NULL)
        {
            find(*child.father,rel);
        }
        if(child.mother!=NULL)
        {  
            find(*child.mother,rel);       
        } 
        
        
        return ;
    }
    
    /*
     The function gets name from the tree and updates that pointr will point it out
    For starters the function gets the root and name we want to find
    With the help of a recursive search (search preorder) 
    in the tree as soon as we find the person we will update the pointer to point it out
    */
    void Tree::search(person & child ,string name,int i)
    {
      
         if(i>0)
         {
                  child.index=i;
         }
        
  
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




    void Tree::remove(string a)
    {
       
        search(*child ,a ,-1);
        destroyTree(this->pointer);
      
    }
	
    

    //for the tree
    void Tree::display()
    {
        if(child->name != "")
        {
            display("", *child,false);
        }
        else cout<<"tree is empty"<<endl;
    }



    //for every node
    void Tree::display(string s, person& node,bool side)
    {
        if(node.name!="")
        {

            cout<<s;
            cout << (side ? "├──" : "└──" );

            // print the value of the node
            cout<<node.name<<endl;

            // enter the next tree level - left and right
            if(node.mother!=NULL)
            {
                display( s + (side ? "│   " : "    "),*node.mother,true);
            }
            if(node.father!=NULL)
            {
                display( s + (side ? "│   " : "    "),*node.father,false);
            } 
        }

    }



}
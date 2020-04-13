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
            //cout<<"remove node"<<endl;
            delete node;
        }
    }



    Tree& Tree::addFather(string s, string f)
    {
        search(*child,s,1);

        person *p = new person();
        p->name=f;

        pointer->father=p;
     
        return *this;
    }



    Tree& Tree::addMother(string s, string m)
    {
        search(*child,s,1);

        person *p = new person();
        p->name=m;

        pointer->mother=p;

        return *this;
    }

   

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



    int Tree::get_index(string person_name)
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
    void Tree::search(person & child ,string name,int i)
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




    void Tree::remove(string a)
    {

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
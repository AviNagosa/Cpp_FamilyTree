#include <stdexcept>
#include <iostream>
#include "FamilyTree.hpp"

using namespace std;


class MyException : public std::exception
{
    string s;
    public:
    MyException(){ s = "Exception!!! this person aleady have parent father/mother/notFound";}
    MyException(const string& name){ s = "The tree cannot handle the '"+name+"' relation";}
	const char * what () const throw (){ return s.c_str();} 
};

namespace family
{
    //empty constructor
    Tree::Tree(){}

    //constructor
    Tree::Tree(string name)
    { 
       child = new person(name);
       child->rel = "me";
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
            delete node;
        }
    }


    Tree& Tree::addFather(string s, string f)
    {
        //find child node 
        search(*child,s,1);

        //the person not in the tree
        if(pointer == NULL) throw MyException();
        //already have a father throw exception otherwise add the father
        if(pointer->father != NULL) throw MyException();
        else
        {
            pointer->father = new person(f, this->pointer->index*2);
        } 
        
        //add person relation
        string relation = ""; 
        if(pointer->father->index == 2) relation = "father";
        else if(pointer->father->index == 3) relation = "mother";
        else
        {
            if(pointer->father->index%2 == 0) relation="grandfather";
            else relation = "grandmother";
       
            for(int i=8;i<=pointer->father->index;i=i*2)
            {
                relation = "great-" + relation;
            }
        } 
        pointer->father->rel = relation;

        pointer = NULL;
        return *this;
    }




    Tree& Tree::addMother(string s, string m)
    {
        //find child node
        search(*child,s,1);

        //the person not in the tree
        if(pointer == NULL) throw MyException();
        //already have a mother throw exception otherwise add the mother
        if(pointer->mother != NULL || pointer == NULL) throw MyException();
        else
        {
            pointer->mother = new person(m, this->pointer->index*2+1);
        } 
       
       //add person relation
        string relation = "";
        if(pointer->mother->index == 2) relation = "father";
        else if(pointer->mother->index == 3) relation = "mother";
        else
        {
            if(pointer->mother->index%2 == 0) relation = "grandfather";
            else relation = "grandmother";
       
            for(int i=8;i<=pointer->mother->index;i=i*2)
            {
                relation = "great-" + relation;
            }
        } 
        pointer->mother->rel = relation;

        pointer = NULL;
        return *this;
    }



   
    string Tree::relation(string a)
    {
        this->pointer = NULL;
 
        search(*child,a,1);
      
        if(this->pointer == NULL)
        {   
            return "unrelated";
        }
  
        string s = pointer->rel;
        pointer = NULL;
        return s;
    }



    string Tree::find(string a)
    {
        find(*this->child, a);
        if(this->pointer == NULL)
        {   
            throw MyException(a);
        }
        string s = pointer->name;
        pointer = NULL;
        return s;
    }


    void Tree::find(person& child, string rel)
    {
        if(child.rel == "") return;
        if(child.rel == rel)
        {
            this->pointer = &child;
            return;
        }
        if(child.father != NULL)find(*child.father,rel);
        if(child.mother != NULL)find(*child.mother,rel);       
        return;
    }
    
    /*
     The function gets name from the tree and updates that pointr will point it out
    For starters the function gets the root and name we want to find
    With the help of a recursive search (search preorder) 
    in the tree as soon as we find the person we will update the pointer to point it out
    */
    void Tree::search(person& child, string name, int i)
    {
        if(i>0)child.index = i;
        if(child.name == "") return;
        if(child.name == name)
        {
            this->pointer = &child;
            return;
        }
        if(child.father != NULL) search(*child.father, name, (i*2));
        if(child.mother != NULL) search(*child.mother, name, (i*2)+1);       
        return;
    }



    void Tree::remove(string subtree)
    {
        //search for the root of the subtree
        search(*child ,subtree ,-1);

        if(pointer == NULL) throw string("Error!!! this node not in the tree");
        //contain the index of the root subtree and his son index 
        int indexSon =  (pointer->index)/2, indexCurr = pointer->index;

        //remove the subtree
        destroyTree(this->pointer); 

        //the son who point on the subtree root point to NULL
        remove(indexSon, *child);  
        if(indexCurr%2==0) pointer->father = NULL;  //check if to delete the father or mother
        else pointer->mother = NULL;
        pointer = NULL;
    }
    
    //get the son pointer to the parent. otherwise he will point to garbage
    void Tree::remove(int index, person& child)
    {
        if(child.index == index)
        {
            this->pointer = &child;
            return;
        }
        if(child.father!=NULL) remove(index,*child.father);
        if(child.mother!=NULL) remove(index,*child.mother);
    }




    //for the tree
    void Tree::display()
    {
        if(child->name != "") display("",child,false);
        else cout<<"tree is empty"<<endl;
    }

    //for every node
    void Tree::display(string s, person* node, bool side)
    {
        if(node != NULL)
        {
            cout << s;
            cout << (side ? "├──" : "└──" );
            
            // print the value of the node
            cout<<node->name<<endl;

            // enter the next tree level - left and right
            if(node->mother != NULL)
            {
                display( s + (side ? "│   " : "    "),node->mother, true);
            }
            if(node->father!=NULL)
            {
                display( s + (side ? "│   " : "    "),node->father, false);
            } 
        }
    }



}
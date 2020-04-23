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



    //add a father to exists person
    Tree& Tree::addFather(string s, string f)
    {
        //find the son
        search(*child,s,1);

        //son not exists or already have a father throw exception
        if(pointer == NULL) throw MyException();   
        if(pointer->father != NULL)     
        {
            pointer = NULL;
            throw MyException();
        }
        //create person
        else pointer->father = new person(f, this->pointer->index*2);     
         
        //create the relation from the root to the curr person
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



    //add a mother to exists person
    Tree& Tree::addMother(string s, string m)
    {
        //find the son
        search(*child,s,1);

        //son not exists or already have a mother throw exception
        if(pointer == NULL) throw MyException();
        if(pointer->mother != NULL)
        {
            pointer = NULL;
            throw MyException();
        }
        //create person
        else pointer->mother = new person(m, this->pointer->index*2+1);
        
       
        //create the relation from the root to the curr person
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



   //name and return his relation to the root 
    string Tree::relation(string a)
    {
        //find the person
        search(*child,a,1);
        //person not in the tree
        if(this->pointer == NULL) return "unrelated";
        //person exists
        string s = pointer->rel;     //save the relation
        pointer = NULL;      //for later use
        return s;
    }



    //get relation and return the person name with that relation
    string Tree::find(string a)
    {
        //search for the relation
        find(*this->child, a);
        //person with that relation is not exists
        if(this->pointer == NULL) throw MyException(a);
        //person exists
        string s = pointer->name;      //save his name
        pointer = NULL;              //for later use
        return s;
    }


    //helper method for recursion search on the tree
    void Tree::find(person& child, string rel)
    {
        if(child.rel == "") return;
        if(child.rel == rel)
        {
            this->pointer = &child;
            return;
        }
        if(child.father != NULL) find(*child.father,rel);
        if(child.mother != NULL) find(*child.mother,rel);       
        return;
    }



    //get name,root and number(for later use) and find by recursion person
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



    //get person name and remove his subtree including him
    void Tree::remove(string subtree)
    {
        //search for the root of the subtree
        search(*child ,subtree ,-1);

        //this person not in the tree
        if(pointer == NULL) throw string("Error!!! this node not in the tree");
        if(pointer->rel == "me")
        {
            pointer = NULL;
            throw string("Error!!! this node not in the tree");
        }
        //contain the index of the root subtree and his son index 
        int indexSon =  (pointer->index)/2, indexCurr = pointer->index;

        //remove the subtree
        destroyTree(this->pointer); 

        //the son who point on the subtree root point to null
        remove(indexSon, *child);  
        if(indexCurr%2 == 0) pointer->father = NULL;  //check if to delete the father or mother
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
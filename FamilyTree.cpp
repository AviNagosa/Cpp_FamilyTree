#include <stdexcept>
#include <iostream>
#include "FamilyTree.hpp"

using namespace std;

class MyException : public std::exception
{
    string s;
    public:

    MyException(const string& name)
    {
        s = "Error!!"+name+" already have a father";
    }

	const char * what () const throw ()
    {
    	return s.c_str();
    } 

};

namespace family
{
    //empty constructor
    Tree::Tree()
    {
        child = NULL;
        pointer = NULL;
    }


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
        if (node != NULL)
        {
            if(node->father != NULL)
            {
                destroyTree(node->father);
            }
            if(node->mother != NULL)
            {
                destroyTree(node->mother);
            }
            delete node;
        }
    }


    void Tree::remove(std::string n)
    {
        search(*child, n, 1);
        destroyTree(pointer);
        delete(pointer);
    }



    Tree& Tree::addFather(string s, string f)
    {
        search(*child,s,1);

        person *p = new person();
        p->name=f;
        if(pointer->father != NULL)
        {
            throw MyException(s);
        }
        else pointer->father=p;
        return *this;
    }



    Tree& Tree::addMother(string s, string m)
    {
        search(*child,s,1);

        person *p = new person();
        p->name=m;

        if(pointer->mother != NULL)
        {
            throw MyException(s);
        }
        else pointer->mother=p;

        return *this;
    }


   

    string Tree::relation(string a)
    {
        int index=get_index(a);
        if(index==-1)return "unrelated";
        if(index==1)return "me";  
        if(index==2)return "father";
        if(index==3)return "mother";
       
        string relation="";
        if(index%2==0)relation="grandfather";
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



    void Tree::search(person & child ,string name,int i)
    {
         child.index=i;
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


    void Tree::display()
    {
        if(child->name != "")
        {
            display("",child,false);
        }
        else cout<<"tree is empty"<<endl;
    }



    //for every node
    void Tree::display(string s, person* node,bool side)
    {
        if(node != NULL)
        {
            cout<<s;
            cout << (side ? "├──" : "└──" );

            // print the value of the node
            cout<<node->name<<endl;

            // enter the next tree level - left and right
            if(node->mother!=NULL)
            {
                display( s + (side ? "│   " : "    "),node->mother,true);
            }
            if(node->father!=NULL)
            {
                display( s + (side ? "│   " : "    "),node->father,false);
            } 
        }
    }


}


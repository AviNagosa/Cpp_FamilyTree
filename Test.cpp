#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;

#include <string>
using namespace std;


TEST_CASE("Test case 1 - addFather/Mother, Relation check Exceptions...")
 {
    Tree a("Yosef");
    CHECK_NOTHROW(a.addFather("Yosef", "Yaakov"));
    CHECK_NOTHROW(a.addMother("Yosef", "Rachel"));
    CHECK_NOTHROW(a.addFather("Yaakov", "Isaac"));
    CHECK_NOTHROW(a.addMother("Yaakov", "Rivka"));
    CHECK_NOTHROW(a.addFather("Isaac", "Avraham"));
    CHECK_NOTHROW(a.addFather("Avraham", "Terah"));
    CHECK_NOTHROW(a.addMother("Rivka", "Shir"));
    CHECK_NOTHROW(a.addFather("Rivka", "Noam"));
    CHECK_NOTHROW(a.addMother("Terah", "Limor"));
    CHECK_NOTHROW(a.addFather("Terah", "Alon"));
    CHECK_THROWS(a.addFather("abb", "Moshe"));   //abb not in the tree
    CHECK_THROWS(a.addFather("Isaac", "sss"));    //isaac already have a father
    CHECK_THROWS(a.addFather("abbbb", ""));     //abbbb not in the tree and the father are empty
    CHECK_THROWS(a.addFather("Rivka", ""));    //rivka already have and the father are empty
    CHECK(a.relation("Yosef") == string("me"));
    CHECK(a.relation("Yaakov") == string("father"));
    CHECK(a.relation("Rachel") == string("mother"));
    CHECK(a.relation("Isaac") == string("grandfather"));
    CHECK(a.relation("Rivka") == string("grandmother"));
    CHECK(a.relation("Shir") == string("great-grandmother"));
    CHECK(a.relation("Avraham") == string("great-grandfather"));
    CHECK(a.relation("Terah") == string("great-great-grandfather"));
    CHECK(a.relation("Noam") == string("great-grandfather"));
    CHECK(a.relation("Alon") == string("great-great-great-grandfather"));
    CHECK(a.relation("") == string("unrelated"));   ///empty check
    CHECK(a.relation("xyz") == string("unrelated"));  //not in the tree
    CHECK(a.relation("Rachel ") == string("unrelated"));   //insert with space 
    CHECK(a.relation(" Rachel") == string("unrelated"));  //insert with space 
}


TEST_CASE("Test case 2 - find, addFather/Mother") 
{
    Tree a("Yosef");
    CHECK_NOTHROW(a.addFather("Yosef", "Yaakov"));
    CHECK_NOTHROW(a.addMother("Yosef", "Rachel"));
    CHECK_NOTHROW(a.addFather("Yaakov", "Isaac"));
    CHECK_NOTHROW(a.addMother("Yaakov", "Rivka"));
    CHECK_NOTHROW(a.addFather("Isaac", "Avraham"));
    CHECK_NOTHROW(a.addMother("Isaac", "Sara"));
    CHECK_NOTHROW(a.addFather("Avraham", "Terah"));
    CHECK(a.find("me") == string("Yosef"));
    CHECK(a.find("father") == string("Yaakov"));
    CHECK(a.find("mother") == string("Rachel"));
    CHECK(a.find("grandfather") == string("Isaac"));
    CHECK(a.find("grandmother") == string("Rivka"));
    CHECK(a.find("great-grandfather") == string("Avraham"));
    CHECK(a.find("great-great-grandfather") == string("Terah"));
    CHECK_THROWS(a.find("great-great-great-grandmother"));  //not in the tree
    CHECK_THROWS(a.find("son"));   //this not declare 
    CHECK_THROWS(a.find(""));    //empty insert
}


TEST_CASE("Test case 3 - added the same name for all family check") 
{
    Tree a("Yosef");
    CHECK_NOTHROW(a.addFather("Yosef", "Yosef")); 
	CHECK_NOTHROW(a.addMother("Yosef", "Yosef"));
    CHECK_THROWS(a.addFather("Yosef", "Yosef"));  //already have a this father
    CHECK_THROWS(a.addFather("Yosef", "Yacov"));  //already have a father

    CHECK(a.find("me") == string("Yosef"));
    CHECK(a.find("father") == string("Yosef"));
    CHECK(a.find("mother") == string("Yosef"));
}


TEST_CASE("Test case 4 - fill the tree. add and search after remove") 
{
    Tree a("Yosef");
    CHECK_NOTHROW(
        a.addFather("Yosef", "Yaakov")
    .addMother("Yosef", "Rachel")
    .addFather("Yaakov", "Isaac")
    .addMother("Yaakov", "Rivka")
    .addFather("Isaac", "Avraham")
    .addFather("Avraham", "Terah")
    .addMother("Terah", "Shir")
    .addMother("Isaac", "Agam")
    .addFather("Terah", "Edan")
    .addMother("Avraham", "Shalom")  
    .addMother("Rivka", "Riri")
    .addFather("Rivka", "Shai")
    .addMother("Shai", "Riri")
    .addFather("Rachel", "Moshe")
    .addMother("Rachel", "Aviva")
    .addFather("Aviva", "Yaron"));

    CHECK(a.find("me") == string("Yosef"));
    CHECK(a.find("father") == string("Yaakov"));
    CHECK(a.find("great-great-great-grandfather") == string("Edan"));
    CHECK(a.find("great-great-great-grandmother") == string("Shir"));

    CHECK_THROWS(a.addFather("Aviva", "Nathan"));   //alreay have a father named Yaron
    CHECK_NOTHROW(a.remove("Yaron"));              //remove him
    CHECK(a.relation("Yaron") == string("unrelated"));    //he removed
    CHECK_NOTHROW(a.addFather("Aviva", "Nathan"));    //add again

    CHECK_THROWS(a.remove("Yoni"));          //not in the tree
    CHECK_THROWS(a.addFather("Rachel", "Yoni"));       //alreay have a father named Moshe
    CHECK(a.relation("Moshe") == string("grandfather"));
    CHECK_NOTHROW(a.remove("Moshe"));       ///remove
    CHECK(a.relation("Moshe") == string("unrelated"));
    CHECK_NOTHROW(a.addFather("Rachel", "Yoni"));    //add again 
    CHECK(a.relation("Yoni") == string("grandfather"));
    CHECK_THROWS(a.remove("Moshe"));    //check exception

    //before
    CHECK(a.relation("Rachel") == string("mother"));
    CHECK(a.relation("Aviva") == string("grandmother"));
    CHECK(a.relation("Yoni") == string("grandfather"));
    CHECK(a.relation("Nathan") == string("great-grandfather"));
    //remove
    CHECK_NOTHROW(a.remove("Rachel"));
    //after
    CHECK(a.relation("Rachel") == string("unrelated"));
    CHECK(a.relation("Aviva") == string("unrelated"));
    CHECK(a.relation("Yoni") == string("unrelated"));
    CHECK(a.relation("Nathan") == string("unrelated"));
    
    CHECK_THROWS(a.remove("Rachel"));
    CHECK_THROWS(a.remove("Aviva"));
    CHECK_THROWS(a.remove("Yoni"));
    CHECK_THROWS(a.remove("Nathan"));
}


TEST_CASE("Test case 5 - remove") 
{
    Tree a("Yosef");
    CHECK_NOTHROW(
        a.addFather("Yosef", "Yaakov")
    .addMother("Yosef", "Rachel")
    .addFather("Yaakov", "Isaac")
    .addMother("Yaakov", "Rivka")
    .addFather("Isaac", "Avraham")
    .addFather("Avraham", "Terah")
    .addMother("Terah", "Shir")
    .addMother("Isaac", "Agam")
    .addFather("Terah", "Edan")
    .addMother("Avraham", "Shalom")  
    .addMother("Rivka", "Riri")
    .addFather("Rivka", "Shai")
    .addMother("Shai", "Riri")
    .addFather("Rachel", "Moshe")
    .addMother("Rachel", "Aviva")
    .addFather("Aviva", "Yaron"));


    CHECK(a.relation("Yaron") == string("great-grandfather"));
    CHECK_NOTHROW(a.remove("Yaron"));
    CHECK(a.relation("Yaron") == string("unrelated"));
    CHECK_THROWS(a.remove("Yaron"));

    CHECK(a.relation("Moshe") == string("grandfather"));
    CHECK_NOTHROW(a.remove("Moshe"));
    CHECK(a.relation("Moshe") == string("unrelated"));
    CHECK_THROWS(a.remove("Moshe"));

    string grandmother;
    CHECK_NOTHROW(grandmother = a.find("grandmother"));
    CHECK((grandmother == "Aviva" || grandmother == "Rivka"));

    CHECK(a.relation("Aviva") == string("grandmother"));
    CHECK_NOTHROW(a.remove("Aviva"));
    CHECK(a.relation("Aviva") == string("unrelated"));
    CHECK_THROWS(a.remove("Aviva"));
    
    CHECK(a.relation("Rivka") == string("grandmother"));
    CHECK_NOTHROW(a.remove("Rivka"));
    CHECK(a.relation("Rivka") == string("unrelated"));
    CHECK_THROWS(a.remove("Rivka"));

    CHECK_THROWS(a.find("grandmother"));

    CHECK(a.relation("Rachel") == string("mother"));
    CHECK_NOTHROW(a.remove("Rachel"));
    CHECK(a.relation("Rachel") == string("unrelated"));
    CHECK_THROWS(a.remove("Rachel"));
    CHECK_THROWS(a.find("mother"));
}

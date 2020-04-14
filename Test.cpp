#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;

#include <string>
using namespace std;

TEST_CASE("Test replacement of p and b") {
    string text = "aaa";
    Tree a("Yosef");

    a.addFather("Yosef", "Yaakov") 
	 .addMother("Yosef", "Rachel")   
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");

    //CHECK(a.relation("Yaakov") == string("father"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));

}
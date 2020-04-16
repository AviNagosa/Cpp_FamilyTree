#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;

#include <string>
using namespace std;


TEST_CASE("Test case 1") {
    Tree a("Yosef");
    CHECK_NOTHROW(a.addFather("Yosef", "Yaakov"));
    CHECK_NOTHROW(a.addMother("Yosef", "Rachel"));
    CHECK_NOTHROW(a.addFather("Yaakov", "Isaac"));
    CHECK_NOTHROW(a.addMother("Yaakov", "Rivka"));
    CHECK_NOTHROW(a.addFather("Isaac", "Avraham"));
    CHECK_NOTHROW(a.addFather("Avraham", "Terah"));

    CHECK(a.relation("Yaakov") == string("father"));
    CHECK(a.relation("Rachel") == string("mother"));
    CHECK(a.relation("Yosef") == string("me"));
    CHECK(a.relation("Isaac") == string("grandfather"));
    CHECK(a.relation("Rivka") == string("grandmother"));
    CHECK(a.relation("Avraham") == string("great-grandfather"));
    CHECK(a.relation("Terah") == string("great-great-grandfather"));
    CHECK(a.relation("") == string("unrelated"));
    CHECK(a.relation("xyz") == string("unrelated"));
    CHECK(a.relation("Rachel ") == string("unrelated"));
    CHECK(a.relation(" Rachel") == string("unrelated"));
}

TEST_CASE("Test case 2") {
    Tree a("Yosef");
    CHECK_NOTHROW(a.addFather("Yosef", "Yaakov"));
    CHECK_NOTHROW(a.addMother("Yosef", "Rachel"));
    CHECK_NOTHROW(a.addFather("Yaakov", "Isaac"));
    CHECK_NOTHROW(a.addMother("Yaakov", "Rivka"));
    CHECK_NOTHROW(a.addFather("Isaac", "Avraham"));
    CHECK_NOTHROW(a.addMother("Isaac", "Sara"));
    CHECK_NOTHROW(a.addFather("Avraham", "Terah"));

    CHECK(a.find("me") == string("Yosef"));
    CHECK(a.find("father") == string("father"));
    CHECK(a.find("mother") == string("Rachel"));
    CHECK(a.find("grandfather") == string("Isaac"));
    CHECK(a.find("grandmother") == string("Rivka"));
    CHECK(a.find("great-grandfather") == string("Avraham"));
    CHECK(a.find("great-great-grandfather") == string("Terah"));
    CHECK_THROWS(a.find("great-grandmother"));
    CHECK_THROWS(a.find("great-great-grandmother"));
}

TEST_CASE("Test case 3") {
    Tree a("Yosef");
    CHECK_NOTHROW(a.addFather("Yosef", "Yosef")); 
	CHECK_NOTHROW(a.addMother("Yosef", "Yosef"));
    CHECK_NOTHROW(a.addFather("Yosef", "Yosef"));

    CHECK(a.find("me") == string("Yosef"));
    CHECK(a.find("father") == string("Yosef"));
    CHECK(a.find("mother") == string("Yosef"));

    CHECK_THROWS(a.addFather("Yosef", "aaa")); 
    CHECK_THROWS(a.addMother("Yosef", "aaa")); 

}

TEST_CASE("Test case 4") {
    Tree a("Yosef");
    CHECK_NOTHROW(a.addFather("Yosef", "Yaakov")
    .addMother("Yosef", "Rachel")
    .addFather("Yaakov", "Isaac")
    .addMother("Yaakov", "Rivka")
    .addFather("Isaac", "Avraham")
    .addFather("Avraham", "Terah")
    .addMother("Terah", "cc")
    .addFather("cc", "dd")
    .addMother("dd", "ww")
    .addFather("ww", "ee")  
    .addMother("ee", "rr")
     .addFather("rr", "qq")
    .addMother("qq", "uu")
    .addFather("uu", "ii")
    .addMother("ii", "oo")
    .addFather("oo", "xx"));

}


TEST_CASE("Test case 4") {
    Tree a("Yosef");
    CHECK_NOTHROW(a.addFather("Yosef", "Yaakov"));
    CHECK_NOTHROW(a.addMother("Yosef", "Rachel"));
    CHECK_NOTHROW(a.addFather("Yaakov", "Isaac"));
    CHECK_NOTHROW(a.addMother("Yaakov", "Rivka"));
    CHECK_NOTHROW(a.addFather("Isaac", "Avraham"));
    CHECK_NOTHROW(a.addFather("Avraham", "Terah"));
    CHECK_NOTHROW(a.addFather("Terah", "a"));
    CHECK_NOTHROW(a.addMother("a", "b"));
    CHECK_NOTHROW(a.addFather("b", "c"));
    CHECK_NOTHROW(a.addMother("c", "d"));
    CHECK_NOTHROW(a.addFather("d", "e"));
    CHECK_NOTHROW(a.addMother("e", "c"));
    CHECK_NOTHROW(a.addFather("c", "l"));
    CHECK_NOTHROW(a.addFather("l", "zzz"));
    CHECK_NOTHROW(a.addMother("zzz", "aa"));
    CHECK_NOTHROW(a.addFather("aa", "bb"));
    CHECK_NOTHROW(a.addMother("bb", "cc"));
    CHECK_NOTHROW(a.addFather("cc", "dd"));
    CHECK_NOTHROW(a.addMother("dd", "ww"));
    CHECK_NOTHROW(a.addFather("ww", "ee"));   
    CHECK_NOTHROW(a.addMother("ee", "rr"));
    CHECK_NOTHROW(a.addFather("rr", "qq"));
    CHECK_NOTHROW(a.addMother("qq", "uu"));
    CHECK_NOTHROW(a.addFather("uu", "ii"));
    CHECK_NOTHROW(a.addMother("ii", "oo"));
    CHECK_NOTHROW(a.addFather("oo", "xx"));
}




TEST_CASE("Test case 4") {
    Tree a("Yosef");
    CHECK_NOTHROW(a.addFather("c", "l"));
    CHECK_NOTHROW(a.addFather("l", "zzz"));
    CHECK_NOTHROW(a.addMother("zzz", "aa"));
    CHECK_NOTHROW(a.addFather("aa", "bb"));
    CHECK_NOTHROW(a.addMother("bb", "cc"));
    CHECK_NOTHROW(a.addFather("cc", "dd"));
    CHECK_NOTHROW(a.addMother("dd", "ww"));
    CHECK_NOTHROW(a.addFather("ww", "ee"));   
    CHECK_NOTHROW(a.addMother("ee", "rr"));
    CHECK_NOTHROW(a.addFather("rr", "qq"));
    CHECK_NOTHROW(a.addMother("qq", "uu"));
    CHECK_NOTHROW(a.addFather("uu", "ii"));
    CHECK_NOTHROW(a.addMother("ii", "oo"));
    CHECK_NOTHROW(a.addFather("oo", "xx"));
}

TEST_CASE("Test case 5") {
    Tree a("Yosef");
    CHECK_NOTHROW(a.addFather("Yosef", "Yaakov"));
    CHECK_NOTHROW(a.addMother("Yosef", "Rachel"));
    CHECK_NOTHROW(a.addFather("Yaakov", "Isaac"));
    CHECK_NOTHROW(a.addMother("Yaakov", "Rivka"));
    CHECK_NOTHROW(a.addFather("Isaac", "Avraham"));
    CHECK_NOTHROW(a.addFather("Avraham", "Terah"));

    CHECK(a.relation("Yaakov") == string("father"));
    CHECK(a.relation("Rachel") == string("mother"));
    CHECK(a.relation("Yosef") == string("me"));
    CHECK(a.relation("Isaac") == string("grandfather"));
    CHECK(a.relation("Rivka") == string("grandmother"));
    CHECK(a.relation("Avraham") == string("great-grandfather"));
    CHECK(a.relation("Terah") == string("great-great-grandfather"));
    CHECK(a.relation("") == string("unrelated"));
    CHECK(a.relation("xyz") == string("unrelated"));
    CHECK(a.relation("Rachel ") == string("unrelated"));
    CHECK(a.relation(" Rachel") == string("unrelated"));
}

TEST_CASE("Test case 6") {
    Tree a("Yosef");
    CHECK_NOTHROW(a.addFather("Yosef", "Yaakov"));
    CHECK_NOTHROW(a.addMother("Yosef", "Rachel"));
    CHECK_NOTHROW(a.addFather("Yaakov", "Isaac"));
    CHECK_NOTHROW(a.addMother("Yaakov", "Rivka"));
    CHECK_NOTHROW(a.addFather("Isaac", "Avraham"));
    CHECK_NOTHROW(a.addFather("Avraham", "Terah"));

    CHECK(a.relation("Yaakov") == string("father"));
    CHECK(a.relation("Rachel") == string("mother"));
    CHECK(a.relation("Yosef") == string("me"));
    CHECK(a.relation("Isaac") == string("grandfather"));
    CHECK(a.relation("Rivka") == string("grandmother"));
    CHECK(a.relation("Avraham") == string("great-grandfather"));
    CHECK(a.relation("Terah") == string("great-great-grandfather"));
    CHECK(a.relation("") == string("unrelated"));
    CHECK(a.relation("xyz") == string("unrelated"));
    CHECK(a.relation("Rachel ") == string("unrelated"));
    CHECK(a.relation(" Rachel") == string("unrelated"));
}
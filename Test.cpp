#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;

#include <string>
using namespace std;


TEST_CASE("Test replacement of p and b") {
    string text = "aaa";
    Tree a;
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
    CHECK(a.find(text) == string("aaa"));
}
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

#include "HashSetStr.hpp"

TEST_CASE("constructor")
{
    HashSetStr s;

    REQUIRE(s.size() == 0);
}

TEST_CASE("insert")
{
    HashSetStr s;

    REQUIRE(s.insert("C++"));
    REQUIRE(s.size() == 1);
    REQUIRE_FALSE(s.insert("C++"));

    REQUIRE(s.insert("C"));
    REQUIRE(s.size() == 2);
    REQUIRE_FALSE(s.insert("C"));

    REQUIRE(s.insert("Java"));
    REQUIRE(s.size() == 3);
    REQUIRE_FALSE(s.insert("Java"));

    REQUIRE(s.insert("Kotlin"));
    REQUIRE(s.size() == 4);
    REQUIRE_FALSE(s.insert("Kotlin"));

    REQUIRE(s.insert("GoLang"));
    REQUIRE(s.size() == 5);
    REQUIRE_FALSE(s.insert("GoLang"));

    REQUIRE(s.insert("JS"));
    REQUIRE(s.size() == 6);
    REQUIRE_FALSE(s.insert("JS"));

    REQUIRE(s.insert("Python"));
    REQUIRE(s.size() == 7);
    REQUIRE_FALSE(s.insert("Python"));

    s.print();
}

TEST_CASE("find")
{
    HashSetStr s;

    s.insert("C++");
    s.insert("C#");
    s.insert("C");
    s.insert("Go");
    s.insert("Java");

    REQUIRE(s.find("C++"));
    REQUIRE(s.find("C#"));
    REQUIRE(s.find("C"));
    REQUIRE(s.find("Go"));
    REQUIRE(s.find("Java"));

    REQUIRE_FALSE(s.find("Kotlin"));
}

TEST_CASE("erase")
{
    HashSetStr s;

    s.insert("C++");
    s.insert("C#");
    s.insert("C");
    s.insert("Go");
    s.insert("Java");

    REQUIRE(s.erase("C++"));
    REQUIRE(s.erase("C#"));
    REQUIRE(s.erase("C"));
    REQUIRE(s.erase("Go"));

    REQUIRE_FALSE(s.erase("Kotlin"));

    s.print();
}

TEST_CASE("clear")
{
    HashSetStr s;

    s.insert("C++");
    s.insert("C#");
    s.insert("C");
    s.insert("Go");
    s.insert("Java");

    s.clear();

    REQUIRE(s.size() == 0);
}

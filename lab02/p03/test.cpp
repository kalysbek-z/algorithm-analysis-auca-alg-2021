#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

#include "BSTreeInt.hpp"
#include <sstream>

TEST_CASE("default constructor")
{
    BSTreeInt t;

    REQUIRE(t.size() == 0);
}

TEST_CASE("clear")
{
    BSTreeInt t;

    t.insert(5);
    t.insert(3);
    t.insert(7);
    t.insert(1);
    t.insert(4);
    t.insert(6);
    t.insert(9);

    t.clear();

    REQUIRE(t.debug == "{1, 4, 3, 6, 9, 7, 5}");
    REQUIRE(t.size() == 0);
}

TEST_CASE("insert")
{
    BSTreeInt t;

    REQUIRE(t.insert(6));
    REQUIRE(t.debug == "");
    REQUIRE(t.size() == 1);

    REQUIRE(t.insert(3));
    REQUIRE(t.debug == "L");
    REQUIRE(t.size() == 2);

    REQUIRE(t.insert(9));
    REQUIRE(t.debug == "R");
    REQUIRE(t.size() == 3);

    REQUIRE(t.insert(1));
    REQUIRE(t.debug == "LL");
    REQUIRE(t.size() == 4);

    REQUIRE(t.insert(4));
    REQUIRE(t.debug == "LR");
    REQUIRE(t.size() == 5);

    REQUIRE(t.insert(7));
    REQUIRE(t.debug == "RL");
    REQUIRE(t.size() == 6);

    REQUIRE(t.insert(10));
    REQUIRE(t.debug == "RR");
    REQUIRE(t.size() == 7);

    REQUIRE_FALSE(t.insert(6));
    REQUIRE_FALSE(t.insert(3));
    REQUIRE_FALSE(t.insert(9));
    REQUIRE_FALSE(t.insert(1));
    REQUIRE_FALSE(t.insert(4));
    REQUIRE_FALSE(t.insert(7));
    REQUIRE_FALSE(t.insert(10));
}

TEST_CASE("find")
{
    BSTreeInt t;

    t.insert(6);
    t.insert(3);
    t.insert(9);
    t.insert(1);
    t.insert(4);
    t.insert(7);
    t.insert(10);

    REQUIRE(t.find(6));
    REQUIRE(t.find(3));
    REQUIRE(t.find(9));
    REQUIRE(t.find(1));
    REQUIRE(t.find(4));
    REQUIRE(t.find(7));
    REQUIRE(t.find(10));

    REQUIRE_FALSE(t.find(-1));
    REQUIRE_FALSE(t.find(15));
    REQUIRE_FALSE(t.find(5));
    REQUIRE_FALSE(t.find(26));
}

TEST_CASE("print")
{
    std::ostringstream out;

    BSTreeInt t;
    t.print(out);
    REQUIRE(out.str() == "{}");

    t.insert(6);
    t.insert(3);
    t.insert(9);
    t.insert(1);
    t.insert(4);
    t.insert(7);
    t.insert(10);

    out.str("");
    out.clear();
    t.print(out);
    REQUIRE(out.str() == "{1, 3, 4, 6, 7, 9, 10}");

    t.insert(2);

    out.str("");
    out.clear();
    t.print(out);
    REQUIRE(out.str() == "{1, 2, 3, 4, 6, 7, 9, 10}");
}

TEST_CASE("erase: (erase leaf)")
{
    std::ostringstream out;

    BSTreeInt t;

    SUBCASE("case: only one node")
    {
        t.insert(6);
        t.print(out);
        REQUIRE(out.str() == "{6}");

        REQUIRE(t.erase(6));
        REQUIRE(t.size() == 0);
        out.str("");
        out.clear();
        t.print(out);
        REQUIRE(out.str() == "{}");
    }

    SUBCASE("regular case: many nodes")
    {
        t.insert(6);
        t.insert(3);
        t.insert(9);
        t.insert(1);
        t.insert(4);
        t.insert(7);
        t.insert(10);

        REQUIRE(t.erase(4));
        REQUIRE(t.size() == 6);
        t.print(out);
        REQUIRE(out.str() == "{1, 3, 6, 7, 9, 10}");

        REQUIRE(t.erase(1));
        REQUIRE(t.size() == 5);
        out.str("");
        out.clear();
        t.print(out);
        REQUIRE(out.str() == "{3, 6, 7, 9, 10}");
    }
}

TEST_CASE("erase: node with one child")
{
    std::ostringstream out;

    BSTreeInt t;

    SUBCASE("special case: erase root")
    {
        SUBCASE("Test 1")
        {
            t.insert(6);
            t.insert(3);

            REQUIRE(t.erase(6));
            REQUIRE(t.size() == 1);
            t.print(out);
            REQUIRE(out.str() == "{3}");
        }

        SUBCASE("Test 2")
        {
            t.insert(6);
            t.insert(10);

            REQUIRE(t.erase(6));
            REQUIRE(t.size() == 1);
            t.print(out);
            REQUIRE(out.str() == "{10}");
        }
    }

    SUBCASE("regular case: many nodes")
    {
        t.insert(6);
        t.insert(3);
        t.insert(9);
        t.insert(1);
        t.insert(4);
        t.insert(7);
        t.insert(10);
        t.insert(12);
        t.insert(11);

        REQUIRE(t.erase(10));
        REQUIRE(t.size() == 8);
        t.print(out);
        REQUIRE(out.str() == "{1, 3, 4, 6, 7, 9, 11, 12}");

        t.insert(2);
        REQUIRE(t.erase(1));
        REQUIRE(t.size() == 8);
        out.str("");
        out.clear();
        t.print(out);
        REQUIRE(out.str() == "{2, 3, 4, 6, 7, 9, 11, 12}");
    }
}

TEST_CASE("erase: node with two children")
{
    BSTreeInt t;
    std::ostringstream out;

    SUBCASE("Test 1")
    {
        t.insert(6);
        t.insert(3);
        t.insert(7);

        REQUIRE(t.erase(6));
        REQUIRE(t.size() == 2);
        t.print(out);
        REQUIRE(out.str() == "{3, 7}");
    }

    SUBCASE("Test 2")
    {
        t.insert(6);
        t.insert(2);
        t.insert(1);
        t.insert(0);
        t.insert(7);

        REQUIRE(t.erase(6));
        REQUIRE(t.size() == 4);
        t.print(out);
        REQUIRE(out.str() == "{0, 1, 2, 7}");
    }

    SUBCASE("Test 3")
    {
        t.insert(50);
        t.insert(25);
        t.insert(10);
        t.insert(40);
        t.insert(39);
        t.insert(47);
        t.insert(60);

        REQUIRE(t.erase(50));
        REQUIRE(t.size() == 6);
        t.print(out);
        REQUIRE(out.str() == "{10, 25, 39, 40, 47, 60}");
    }

    SUBCASE("Test 4")
    {
        t.insert(50);
        t.insert(25);
        t.insert(10);
        t.insert(40);
        t.insert(39);
        t.insert(47);
        t.insert(60);

        REQUIRE(t.erase(25));
        REQUIRE(t.size() == 6);
        t.print(out);
        REQUIRE(out.str() == "{10, 39, 40, 47, 50, 60}");
    }
}
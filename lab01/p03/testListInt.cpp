#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"

#include "ListInt.hpp"

TEST_CASE("constructor")
{
    ListInt v;

    REQUIRE(v.size() == 0);
}
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include <utility>

#include "algo.h"

using namespace std;

TEST_CASE("binary search")
{
    vector<int> arr = {2, 9, 23, 53, 54, 54, 60, 70, 128, 182};

    REQUIRE(arr.size() == 10);
    REQUIRE(binarySearch(arr, arr.size() - 1, 70) != -1);
    REQUIRE(binarySearch(arr, arr.size() - 1, 5) == -1);
    REQUIRE(binarySearch(arr, arr.size() - 1, 54) != -1);
}

TEST_CASE("binary search recursive")
{
    vector<int> arr = {2, 9, 23, 53, 54, 54, 60, 70, 128, 182};

    REQUIRE(arr.size() == 10);
    REQUIRE(binarySearchRecursive(arr, 0, arr.size() - 1, 70) != -1);
    REQUIRE(binarySearchRecursive(arr, 0, arr.size() - 1, 5) == -1);
    REQUIRE(binarySearchRecursive(arr, 0, arr.size() - 1, 54) != -1);
}

TEST_CASE("insertion sort")
{
    vector<int> arr = {5, 53, 2, 0, 24, -2, 123, 532, 1, 1, 22};

    REQUIRE(arr.size() == 11);

    insertionSort(arr);

    REQUIRE(arr[0] == -2);
    REQUIRE(arr[1] == 0);
    REQUIRE(arr[2] == 1);
    REQUIRE(arr[3] == 1);
    REQUIRE(arr[4] == 2);
    REQUIRE(arr[5] == 5);
    REQUIRE(arr[6] == 22);
    REQUIRE(arr[7] == 24);
    REQUIRE(arr[8] == 53);
    REQUIRE(arr[9] == 123);
    REQUIRE(arr[10] == 532);
}
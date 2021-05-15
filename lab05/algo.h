#pragma once

#include <bits/stdc++.h>

// O(logN) running time
template <typename T>
int binarySearch(std::vector<T> &arr, int n, int x)
{
    int p = 1;
    int r = n;

    while (p <= r)
    {
        int q = (p + r) / 2;
        if (arr[q] == x)
        {
            return q;
        }
        else if (arr[q] > x)
        {
            r = q - 1;
        }
        else
        {
            p = q + 1;
        }
    }
    return -1;
}

// O(logN) running time
template <typename T>
int binarySearchRecursive(std::vector<T> &arr, int p, int r, int x)
{
    if (p > r)
    {
        return -1;
    }
    else
    {
        int q = (p + r) / 2;
        if (arr[q] == x)
        {
            return q;
        }
        else if (arr[q] > x)
        {
            return binarySearchRecursive(arr, p, q - 1, x);
        }
        else
        {
            return binarySearchRecursive(arr, q + 1, r, x);
        }
    }
}

// O(n) but in some cases O(n^2)
template <typename T>
void insertionSort(std::vector<T> &arr)
{
    for (int i = 1; i < int(arr.size()); i++)
    {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
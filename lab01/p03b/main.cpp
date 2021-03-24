#include <iostream>
#include "List.hpp"

using namespace std;

void printInDirectOrder(List<int> &v)
{
    for (auto p = v.begin(); p != v.end(); p++)
    {
        cout << " " << *p;
    }
    cout << "\n";
}

void printInReversedOrder(List<int> &v)
{
    for (auto p = v.rbegin(); p != v.rend(); p++)
    {
        cout << " " << *p;
    }
    cout << "\n";
}

int main()
{
    List<int> v;

    for (int i; cin >> i;)
    {
        v.pushBack(i);
    }

    printInDirectOrder(v);
    printInReversedOrder(v);

    for (auto p = v.begin(); p != v.end(); p++)
    {
        if (*p % 2 == 0)
        {
            v.insert(p, 0);
        }
    }
    printInDirectOrder(v);
    printInReversedOrder(v);

    for (auto p = v.begin(); p != v.end();)
    {
        if (*p % 2 == 0)
        {
            p = v.erase(p);
        }
        else
        {
            p++;
        }
    }

    printInDirectOrder(v);
    printInReversedOrder(v);
}
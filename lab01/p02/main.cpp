#include <iostream>
#include <list>

using namespace std;

void printInDirectOrder(const list<int> &v)
{
    for (auto p = v.begin(); p != v.end(); p++)
    {
        cout << " " << *p;
    }
    cout << "\n";
}

void printInReversedOrder(const list<int> &v)
{
    for (auto p = v.rbegin(); p != v.rend(); p++)
    {
        cout << " " << *p;
    }
    cout << "\n";
}

int main()
{
    list<int> v;

    for (int i; cin >> i;)
    {
        v.push_back(i);
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
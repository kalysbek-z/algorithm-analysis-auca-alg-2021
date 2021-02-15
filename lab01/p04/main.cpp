#include <iostream>
#include <random>
#include <limits>
#include <chrono>
#include <vector>
#include <list>

using namespace std;

template <typename Container>
void expWith(const string &msg, int n)
{
    mt19937 rndGen;
    uniform_int_distribution<int> numDist(0, numeric_limits<int>::max());

    auto t1 = chrono::high_resolution_clock::now();

    Container lst;
    for (int i = 0; i < n; ++i)
    {
        int x = numDist(rndGen);
        auto p = begin(lst);
        while (p != end(lst) && *p < x)
        {
            ++p;
        }
        lst.insert(p, x);
    }

    auto t2 = chrono::high_resolution_clock::now();

    cout << msg << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << "\n";
}

int main()
{
    const int n = 10000;

    expWith<vector<int>>("vector: ", n);
    expWith<list<int>>("list: ", n);
}
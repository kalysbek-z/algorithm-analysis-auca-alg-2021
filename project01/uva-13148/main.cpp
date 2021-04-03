#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_set<int> special_numbers;
    special_numbers.insert(1);
    special_numbers.insert(64);
    special_numbers.insert(729);
    special_numbers.insert(4096);
    special_numbers.insert(15625);
    special_numbers.insert(46656);
    special_numbers.insert(117649);
    special_numbers.insert(262144);
    special_numbers.insert(531441);
    special_numbers.insert(1000000);
    special_numbers.insert(1771561);
    special_numbers.insert(2985984);
    special_numbers.insert(4826809);
    special_numbers.insert(7529536);
    special_numbers.insert(11390625);
    special_numbers.insert(16777216);
    special_numbers.insert(24137569);
    special_numbers.insert(34012224);
    special_numbers.insert(47045881);
    special_numbers.insert(64000000);
    special_numbers.insert(85766121);

    int n;
    while (cin >> n && n != 0)
    {
        if (special_numbers.find(n) != special_numbers.end())
        {
            cout << "Special\n";
        }
        else
        {
            cout << "Ordinary\n";
        }
    }
}
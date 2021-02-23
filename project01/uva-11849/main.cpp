#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m && n != 0 && m != 0)
    {
        unordered_set<int> cd1;
        unordered_set<int> cd2;
        int c = 0;
        int cdn;
        int cdm;
        while (n--)
        {
            cin >> cdn;
            cd1.insert(cdn);
        }
        while (m--)
        {
            cin >> cdm;
            cd2.insert(cdm);
        }
        if (cd1.size() < cd2.size())
        {
            for (auto p = cd1.begin(); p != cd1.end(); p++)
            {
                if (cd2.find(*p) != cd2.end())
                {
                    c++;
                }
            }
        }
        else
        {
            for (auto p = cd2.begin(); p != cd2.end(); p++)
            {
                if (cd1.find(*p) != cd1.end())
                {
                    c++;
                }
            }
        }
        cout << c << "\n";
    }
}
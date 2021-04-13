#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<int, int> seq;
    vector<int> order;

    int n;
    while (cin >> n)
    {
        auto iter = seq.find(n);
        if (iter != seq.end())
        {
            iter->second++;
        }
        else
        {
            seq[n] = 1;
            order.push_back(n);
        }
    }

    for (int i = 0; i < order.size(); i++)
    {
        cout << order[i] << " " << seq[order[i]] << "\n";
    }
}
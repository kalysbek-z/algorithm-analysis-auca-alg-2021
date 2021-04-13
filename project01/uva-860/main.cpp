#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    string s;

    cin >> t;

    cin.ignore();
    getline(cin, s);

    int c = 0;
    while (t--)
    {
        if (c > 0)
        {
            printf("\n");
        }
        vector<string> frag;
        map<string, int> mem;

        while (getline(cin, s) && !s.empty())
        {
            frag.push_back(s);
        }

        for (int i = 0; i < frag.size(); i++)
        {
            for (int j = 0; j < frag.size(); j++)
            {
                mem[frag[i] + frag[j]]++;
                mem[frag[j] + frag[i]]++;
            }
        }

        int num = 0;
        string res;

        for (auto it = mem.begin(); it != mem.end(); it++)
        {
            if (it->second > num)
            {
                num = it->second;
                res = it->first;
            }
        }

        cout << res << "\n";

        c++;
    }
}
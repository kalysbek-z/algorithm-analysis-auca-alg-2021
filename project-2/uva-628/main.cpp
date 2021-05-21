#include <bits/stdc++.h>

using namespace std;

vector<string> words;
char passwords[256];
string law;
int id;

void solve(int ind)
{
    if (ind == law.size())
    {
        for (int i = 0; i < law.size(); i++)
        {
            if (passwords[i] == '#')
            {
                cout << words[id];
            }
            else
            {
                cout << passwords[i];
            }
        }
        cout << "\n";
    }
    else if (law[ind] == '#')
    {
        passwords[ind] = '#';
        solve(ind + 1);
    }
    else
    {
        for (int i = 0; i <= 9; i++)
        {
            passwords[ind] = i + '0';
            solve(ind + 1);
        }
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        string s;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            words.push_back(s);
        }
        // for (auto &e : words)
        // {
        //     cout << e << " ";
        // }
        cout << "--\n";
        int r;
        cin >> r;
        for (int i = 0; i < r; i++)
        {
            cin >> law;
            for (int j = 0; j < n; j++)
            {
                id = j;
                solve(0);
            }
        }
    }
}
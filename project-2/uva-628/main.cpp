#include <bits/stdc++.h>

using namespace std;

vector<string> words;
string passwords[500];
string law;
char nums[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void solve(int ind)
{
    if (ind == law.size())
    {
        for (int i = 0; i < ind; i++)
        {
            cout << passwords[i];
        }
        cout << "\n";
    }
    else if (law[ind] == '#')
    {
        for (int i = 0; i < words.size(); i++)
        {
            passwords[ind] = words[i];
            solve(ind + 1);
        }
    }
    else
    {
        for (int i = 0; i <= 9; i++)
        {
            passwords[ind] = nums[i];
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
        words.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            words[i] = s;
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
            solve(0);
        }
    }
}
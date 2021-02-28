#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    int cases = 1;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        vector<string> al;
        vector<string> bl;
        string s;
        getline(cin, s);
        for (int i = 0; i < a; i++)
        {
            getline(cin, s);
            al.push_back(s);
        }
        for (int i = 0; i < b; i++)
        {
            getline(cin, s);
            bl.push_back(s);
        }
        unordered_set<string> cl;
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                string s = "";
                s = al[i] + bl[j];
                cl.insert(s);
            }
        }
        cout << "Case " << cases << ": " << cl.size() << "\n";
        cases++;
    }
}
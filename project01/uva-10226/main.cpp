#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map<string, int> species;
    string s;
    string blank = "";

    cin.ignore();
    cin.ignore();
    while (n--)
    {
        int total = 0;
        species.clear();

        while (getline(cin, s) && s != "")
        {
            auto it = species.find(s);
            if (it == species.end())
            {
                it = species.insert(make_pair(s, 0)).first;
            }

            it->second++;
            total++;
        }

        cout << blank;
        blank = "\n";

        for (auto i = species.begin(); i != species.end(); i++)
        {
            printf("%s %.4f\n", i->first.c_str(), i->second * 100.0 / total);
        }
    }
}
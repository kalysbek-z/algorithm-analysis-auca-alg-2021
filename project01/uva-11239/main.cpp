#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string, set<int>> sheet;
    vector<pair<string, int>> counter;

    string s1;

    while (getline(cin, s1))
    {
        if (s1 == "0")
        {
            break;
        }
        if (s1 == "1")
        {
            for (auto it = sheet.begin(); it != sheet.end(); it++)
            {
                if (it->second.size() == 1)
                {
                    counter[*it->second.begin()].second++;
                }
            }

            sort(counter.begin(), counter.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
                if (a.second != b.second)
                {
                    return a.second > b.second;
                }
                return a.first < b.first;
            });

            for (auto e : counter)
            {
                cout << e.first << " " << e.second << "\n";
            }

            sheet.clear();
            counter.clear();
        }
        else if (s1[0] >= 'a' && s1[0] <= 'z')
        {
            sheet[s1].insert(counter.size() - 1);
        }
        else
        {
            counter.push_back(make_pair(s1, 0));
        }
    }
}
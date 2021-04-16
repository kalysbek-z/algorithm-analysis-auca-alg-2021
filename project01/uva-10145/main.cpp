#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int c = 0;

    while (t--)
    {
        if (c > 0)
        {
            printf("\n");
        }
        char m;
        int trid, item;

        unordered_map<int, int> x;
        unordered_map<int, set<int>> s;
        set<int> ignored;
        while (cin >> m && m != '#')
        {
            cin >> trid >> item;

            auto itIg = ignored.find(item);
            auto itX = x.find(item);
            auto itS = s.find(item);

            if (ignored.count(trid))
            {
                printf("IGNORED\n");
            }
            else if (m == 'S')
            {
                if (itX != x.end() && x[item] != trid)
                {
                    printf("DENIED\n");
                    ignored.insert(trid);
                }
                else
                {
                    s[item].insert(trid);
                    printf("GRANTED\n");
                }
            }
            else
            {
                if (itX != x.end() && x[item] != trid)
                {
                    printf("DENIED\n");
                    ignored.insert(trid);
                }
                else if (s[item].count(trid) != s[item].size())
                {
                    printf("DENIED\n");
                    ignored.insert(trid);
                }
                else
                {
                    x[item] = trid;
                    printf("GRANTED\n");
                }
            }
        }
        c++;
    }
}
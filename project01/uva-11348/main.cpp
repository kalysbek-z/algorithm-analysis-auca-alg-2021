#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int c = 1; c <= t; c++)
    {
        int n;
        scanf("%d", &n);
        unordered_map<int, set<int>> stamps;
        for (int i = 0; i < n; i++)
        {
            int m;
            scanf("%d", &m);

            while (m--)
            {
                int stamp;
                scanf("%d", &stamp);

                auto res = stamps.insert(make_pair(stamp, set<int>()));
                res.first->second.insert(i);
            }
        }
        int counter = 0;
        vector<int> uniq(n, 0);

        for (auto i = stamps.begin(); i != stamps.end(); i++)
        {
            if (i->second.size() == 1)
            {
                counter++;
                uniq[*i->second.begin()]++;
            }
        }

        printf("Case %d:", c);

        if (counter)
        {
            for (int i = 0; i < n; i++)
            {
                printf(" %.6f%%", (double)uniq[i] * 100.0 / (double)counter);
            }
            printf("\n");
        }
    }
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;

        scanf("%d", &n);

        int m = 0;
        int repeatedpack = 0;
        int l;
        unordered_map<int, int> sf;

        for (int i = 1; i <= n; i++)
        {
            int s;
            scanf("%d", &s);

            int rep = sf[s];

            if (s)
            {
                repeatedpack = max(repeatedpack, rep);
                l = i - repeatedpack - 1;
            }

            l++;
            sf[s] = i;
            m = max(m, l);
        }

        printf("%d\n", m);
    }
}

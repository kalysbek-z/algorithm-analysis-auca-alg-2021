#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<string, int> coms;

    int n;
    while (cin >> n && n != 0)
    {
        coms.clear();
        // vector<string> inp(5);
        string inp[5];

        for (int i = 0; i < n; i++)
        {
            // scanf("%s %s %s %s %s", &inp[0], &inp[1], &inp[2], &inp[3], &inp[4]);
            cin >> inp[0] >> inp[1] >> inp[2] >> inp[3] >> inp[4];
            sort(inp, inp + 5);

            string com = "";
            for (auto e : inp)
            {
                com += e;
            }
            // cout << com << "\n";

            coms[com]++;
        }

        int m = 0;

        for (auto e : coms)
        {
            if (e.second > m)
            {
                m = e.second;
            }
        }

        int res = 0;

        for (auto e : coms)
        {
            if (e.second == m)
            {
                res += e.second;
            }
        }

        printf("%d\n", res);
    }
}
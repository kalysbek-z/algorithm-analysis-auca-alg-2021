#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    unordered_map<string, int> prices;

    while (m--)
    {
        string s;
        int num;
        cin >> s >> num;
        prices[s] = num;
    }

    while (n--)
    {
        int points = 0;

        for (string w; cin >> w && w != ".";)
        {
            if (prices.find(w) != prices.end())
            {
                points += prices[w];
            }
        }

        printf("%d\n", points);
    }
}
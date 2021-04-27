#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int c = 1; c <= t; c++)
    {
        int subj;
        unordered_map<string, int> homework;
        scanf("%d", &subj);

        for (int i = 0; i < subj; i++)
        {
            string s;
            int d;

            cin >> s >> d;
            homework[s] = d;
        }
        int D;
        scanf("%d", &D);

        string s;
        cin >> s;

        if (homework.find(s) != homework.end() && homework[s] <= D)
        {
            printf("Case %d: Yesss\n", c);
        }
        else if (homework.find(s) != homework.end() && homework[s] > D && homework[s] <= D + 5)
        {
            printf("Case %d: Late\n", c);
        }
        else
        {
            printf("Case %d: Do your own homework!\n", c);
        }
    }
}
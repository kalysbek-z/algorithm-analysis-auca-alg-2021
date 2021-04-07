#include <bits/stdc++.h>

using namespace std;

//initialize chocolates in sets
void initChocolates(set<int> &s, int &num)
{
    for (int i = 0; i < num; i++)
    {
        int c;
        cin >> c;
        s.insert(c);
    }
}

void countChocolates(const set<int> &s1, const set<int> &s2, const set<int> &s3, int &posS1, int &notPosS2, int &notPosS3)
{
    for (auto e : s1)
    {
        if (s2.find(e) == s2.end() && s3.find(e) == s3.end())
        {
            posS1++;
        }
        else if (s2.find(e) == s2.end() && s3.find(e) != s3.end())
        {
            notPosS2++;
        }
        else if (s2.find(e) != s2.end() && s3.find(e) == s3.end())
        {
            notPosS3++;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    int cases = 1;
    while (t--)
    {
        int l, r, s;
        // sets for every boy with their chocolates
        set<int> lc;
        set<int> rc;
        set<int> sc;

        cin >> l >> r >> s;

        initChocolates(lc, l);
        initChocolates(rc, r);
        initChocolates(sc, s);

        // for (auto e : lc)
        // {
        //     cout << e << " ";
        // }

        //1 for exclusive chocolates 2 for chocolates which are boy dont have
        //1 for possessed by respective boy 2 for not possesed
        int l1 = 0, l2 = 0;
        int r1 = 0, r2 = 0;
        int s1 = 0, s2 = 0;

        countChocolates(lc, rc, sc, l1, r2, s2);
        countChocolates(rc, lc, sc, r1, l2, s2);
        countChocolates(sc, lc, rc, s1, l2, r2);

        printf("Case #%d:\n", cases);
        printf("%d %d\n%d %d\n%d %d\n", l1, l2 / 2, r1, r2 / 2, s1, s2 / 2);
        cases++;
    }
}
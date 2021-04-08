#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int bf, sg, sb;
        cin >> bf >> sg >> sb;

        multiset<int> greenArmy;
        multiset<int> blueArmy;

        for (int i = 0; i < sg; i++)
        {
            int g;
            cin >> g;
            greenArmy.insert(g);
        }

        for (int i = 0; i < sb; i++)
        {
            int b;
            cin >> b;
            blueArmy.insert(b);
        }

        while (!greenArmy.empty() && !blueArmy.empty())
        {
            int minOfArmies = min(greenArmy.size(), blueArmy.size());
            int numOfFights = min(bf, minOfArmies);

            while (numOfFights--)
            {
                auto g = --greenArmy.end();
                auto b = --blueArmy.end();

                int gv = *g;
                int bv = *b;

                greenArmy.erase(g);
                blueArmy.erase(b);

                if (gv > bv)
                {
                    greenArmy.insert(gv - bv);
                }
                else if (bv > gv)
                {
                    blueArmy.insert(bv - gv);
                }
            }
        }

        if (!greenArmy.empty() && blueArmy.empty())
        {
            printf("green wins\n");

            for (auto i = greenArmy.rbegin(); i != greenArmy.rend(); i++)
            {
                printf("%d\n", *i);
            }
        }
        else if (greenArmy.empty() && !blueArmy.empty())
        {
            printf("blue wins\n");

            for (auto i = blueArmy.rbegin(); i != blueArmy.rend(); i++)
            {
                printf("%d\n", *i);
            }
        }
        else
        {
            printf("green and blue died\n");
        }
        printf("\n");
    }
}
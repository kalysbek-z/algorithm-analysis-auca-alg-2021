#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p, g;
    scanf("%d %d", &p, &g);

    unordered_map<string, int> elec;
    while (p--)
    {
        string s;
        double per;
        cin >> s >> per;

        elec[s] = per;
    }

    string s;
    for (int i = 1; i <= g; i++)
    {
        getline(cin, s);
        stringstream ss(s);

        int sum = 0;
        string name, sign;
        ss >> name >> sign;
        while (sign == "+")
        {
            sum += elec[name];
            ss >> name >> sign;
        }

        int vrag;
        ss >> vrag;

        if (sum == vrag)
        {
            if (sign.find("=") != string::npos)
            {
                printf("Guess #%d was correct.\n", i);
            }
            else
            {
                printf("Guess #%d was incorrect.\n", i);
            }
        }
        else if (sum > vrag)
        {
            if (sign.find(">") != string::npos)
            {
                printf("Guess #%d was correct.\n", i);
            }
            else
            {
                printf("Guess #%d was incorrect.\n", i);
            }
        }
        else if (sum < vrag)
        {
            if (sign.find("<") != string::npos)
            {
                printf("Guess #%d was correct.\n", i);
            }
            else
            {
                printf("Guess #%d was incorrect.\n", i);
            }
        }
    }
}
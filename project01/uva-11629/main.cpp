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
        int fir, sec;
        char ch;
        cin >> s >> fir >> ch >> sec;

        elec[s] = fir * 10 + sec;
    }
    cin.ignore();
    string s;
    for (int i = 1; i <= g; i++)
    {
        getline(cin, s);
        stringstream ss(s);

        int sum = 0;
        string name, sign;
        do
        {
            ss >> name >> sign;
            sum += elec[name];
        } while (sign == "+");

        int vrag;
        ss >> vrag;
        vrag *= 10;
        if (sum == vrag)
        {
            if (sign.find("=") != string::npos)
            {
                printf("Guess #%d was correct.\n", i);
                // cout << sum << " " << vrag << "\n";
            }
            else
            {
                printf("Guess #%d was incorrect.\n", i);
                // cout << sum << " " << vrag << "\n";
            }
        }
        else if (sum > vrag)
        {
            if (sign.find(">") != string::npos)
            {
                printf("Guess #%d was correct.\n", i);
                // cout << sum << " " << vrag << "\n";
            }
            else
            {
                printf("Guess #%d was incorrect.\n", i);
                // cout << sum << " " << vrag << "\n";
            }
        }
        else if (sum < vrag)
        {
            if (sign.find("<") != string::npos)
            {
                printf("Guess #%d was correct.\n", i);
                // cout << sum << " " << vrag << "\n";
            }
            else
            {
                printf("Guess #%d was incorrect.\n", i);
                // cout << sum << " " << vrag << "\n";
            }
        }
    }
}
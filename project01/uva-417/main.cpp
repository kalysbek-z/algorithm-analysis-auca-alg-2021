#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<string, int> dic;

    int index = 1;
    string res, s1, s2, s3, s4, s5;
    string alph = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 26; i++)
    {
        res = alph[i];
        dic[res] = index++;
    }

    for (int i = 0; i < 26; i++)
    {
        s1 = alph[i];
        for (int j = i + 1; j < 26; j++)
        {
            s2 = alph[j];
            res = s1 + s2;
            dic[res] = index++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        s1 = alph[i];
        for (int j = i + 1; j < 26; j++)
        {
            s2 = alph[j];
            for (int k = j + 1; k < 26; k++)
            {
                s3 = alph[k];
                res = s1 + s2 + s3;
                dic[res] = index++;
            }
        }
    }

    for (int i = 0; i < 26; i++)
    {
        s1 = alph[i];
        for (int j = i + 1; j < 26; j++)
        {
            s2 = alph[j];
            for (int k = j + 1; k < 26; k++)
            {
                s3 = alph[k];
                for (int l = k + 1; l < 26; l++)
                {
                    s4 = alph[l];
                    res = s1 + s2 + s3 + s4;
                    dic[res] = index++;
                }
            }
        }
    }

    for (int i = 0; i < 26; i++)
    {
        s1 = alph[i];
        for (int j = i + 1; j < 26; j++)
        {
            s2 = alph[j];
            for (int k = j + 1; k < 26; k++)
            {
                s3 = alph[k];
                for (int l = k + 1; l < 26; l++)
                {
                    s4 = alph[l];
                    for (int m = l + 1; m < 26; m++)
                    {
                        s5 = alph[m];
                        res = s1 + s2 + s3 + s4 + s5;
                        dic[res] = index++;
                    }
                }
            }
        }
    }

    string s;
    while (cin >> s)
    {
        printf("%d\n", dic[s]);
        // cout << dic[s] << "\n";
    }
}
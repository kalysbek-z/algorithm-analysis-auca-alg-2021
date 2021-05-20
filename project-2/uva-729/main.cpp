#include <bits/stdc++.h>

using namespace std;

void hammingDistance(int n, int h, string s)
{
    if (n == s.size())
    {
        if (h == 0)
        {
            cout << s << "\n";
        }
        return;
    }
    hammingDistance(n, h, s + '0');
    hammingDistance(n, h - 1, s + '1');
}

int main()
{
    int d;
    cin >> d;
    // cin.ignore();
    // cin.ignore();
    int n, h;
    while (d--)
    {
        cin >> n >> h;
        string s = "";

        hammingDistance(n, h, s);
        if (d > 0)
        {
            cout << "\n";
        }
    }
}
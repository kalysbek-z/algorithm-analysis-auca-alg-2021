#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<string, string> slogans;
    string part1, part2;
    cin.ignore();
    while (n--)
    {
        getline(cin, part1);
        getline(cin, part2);

        slogans[part1] = part2;
    }

    int n1;
    cin >> n1;
    cin.ignore();
    while (n1--)
    {
        string sl;
        getline(cin, sl);

        cout << slogans[sl] << "\n";
    }
}
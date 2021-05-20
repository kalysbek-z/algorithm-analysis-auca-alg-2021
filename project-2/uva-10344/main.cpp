#include <bits/stdc++.h>

using namespace std;

bool solve(int n, int i, int (&arr)[5])
{
    if (i == 5)
    {
        return n == 23;
    }

    int num = arr[i];

    return solve(n + num, i + 1, arr) || solve(n - num, i + 1, arr) || solve(n * num, i + 1, arr);
}

int main()
{
    // int n1, n2, n3, n4, n5;
    int n[5];
    while (cin >> n[0] >> n[1] >> n[2] >> n[3] >> n[4] && (n[0] != 0 && n[1] != 0 && n[2] != 0 && n[3] != 0 && n[4] != 0))
    {
        sort(n, n + 5);
        bool p = false;
        while (next_permutation(n, n + 5))
        {
            p = solve(n[0], 1, n);
            if (p)
            {
                break;
            }
        }
        if (p)
        {
            cout << "Possible\n";
        }
        else
        {
            cout << "Impossible\n";
        }
    }
}
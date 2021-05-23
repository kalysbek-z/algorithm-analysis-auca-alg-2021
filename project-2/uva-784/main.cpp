#include <bits/stdc++.h>

using namespace std;

void dfs(int r, int c, vector<string> &vec)
{
    if (vec[r][c] == 'X' || vec[r][c] == '#')
    {
        return;
    }
    vec[r][c] = '#';

    dfs(r + 1, c, vec);
    dfs(r - 1, c, vec);
    dfs(r, c + 1, vec);
    dfs(r, c - 1, vec);
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        vector<string> map(30);
        int r = 0;
        while (getline(cin, map[r]))
        {
            if (map[r][0] == '_')
            {
                break;
            }
            // cout << map[r];
            r++;
        }
        // cout << r;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < map[i].size(); j++)
            {
                if (map[i][j] == '*')
                {
                    dfs(i, j, map);
                }
            }
        }

        for (int i = 0; i <= r; i++)
        {
            if (!map[i].empty())
            {
                cout << map[i] << "\n";
            }
        }
    }
}

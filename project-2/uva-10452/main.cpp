#include <bits/stdc++.h>

using namespace std;

vector<string> grid;
int l, w;

bool solve(int x, int y, int pos)
{
    string path = "IEHOVA#";
    vector<string> commands = {"left", "forth", "right"};
    vector<string> res;
    res.resize(7);

    vector<int> dx = {-1, 0, 1};
    vector<int> dy = {0, -1, 0};

    if (grid[y][x] == '#')
    {
        // for (int i = 0; i < pos; i++)
        // {
        //     if (i == 0)
        //     {
        //         cout << res[i];
        //     }
        //     else
        //     {
        //         cout << " " << res[i];
        //     }
        // }
        cout << "\n";
        return true;
    }
    else if (pos == path.size())
    {
        return false;
    }

    for (int i = 0; i < 3; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < w && ny >= 0 && ny < l && grid[ny][nx] == path[pos])
        {
            res[pos] = commands[i];
            if (pos == 0)
            {
                cout << res[pos];
            }
            else
            {
                cout << " " << res[pos];
            }
            if (solve(nx, ny, pos + 1))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        cin >> l >> w;

        int x, y;
        grid.resize(9);

        for (int i = 0; i < l; i++)
        {
            cin >> grid[i];

            for (int j = 0; j < w; j++)
            {
                if (grid[i][j] == '@')
                {
                    x = j;
                    y = i;
                }
            }
        }

        solve(x, y, 0);
    }
}
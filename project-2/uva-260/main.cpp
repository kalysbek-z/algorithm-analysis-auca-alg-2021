#include <bits/stdc++.h>

using namespace std;

bool dfs(char ch, int size, int r, int c, vector<string> &graph)
{
    vector<vector<int>> d = {{-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}};
    if (r < 0 || r >= size || c < 0 || c >= size)
    {
        return false;
    }
    else if (graph[r][c] != ch)
    {
        return false;
    }
    else if (ch == 'w' && c == size - 1)
    {
        return true;
    }
    else if (ch == 'b' && r == size - 1)
    {
        return true;
    }
    graph[r][c] = ' ';

    for (auto &e : d)
    {
        int nr = r + e[0];
        int nc = c + e[1];

        if (dfs(ch, size, nr, nc, graph))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    int c = 1;
    while (cin >> n && n != 0)
    {
        vector<string> graph;

        string s;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            graph.push_back(s);
        }

        bool black = false;

        for (int i = 0; i < n && !black; i++)
        {
            black = dfs('b', n, 0, i, graph);
        }
        cout << c++ << " ";

        if (black)
        {
            cout << "B";
        }
        else
        {
            cout << "W";
        }

        cout << "\n";
    }
}
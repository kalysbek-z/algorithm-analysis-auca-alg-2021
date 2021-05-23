#include <bits/stdc++.h>

using namespace std;

int total;

enum class Status
{
    notVisited,
    inProgress,
    visited
};

void dfs(int vertice, vector<vector<int>> &graph, vector<Status> &vertices)
{
    total++;
    vertices[vertice] = Status::inProgress;
    for (auto &e : graph[vertice])
    {
        if (vertices[e] == Status::notVisited)
        {
            dfs(e, graph, vertices);
        }
    }

    vertices[vertice] = Status::visited;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, l;
        cin >> n >> m >> l;

        vector<vector<int>> graph(10001);
        vector<Status> states(10001, Status::notVisited);
        total = 0;

        while (m--)
        {
            int u, v;
            cin >> u >> v;

            graph[u].push_back(v);
        }
        while (l--)
        {
            int h;
            cin >> h;
            if (states[h] == Status::notVisited)
            {
                dfs(h, graph, states);
            }
        }

        cout << total << "\n";
    }
}
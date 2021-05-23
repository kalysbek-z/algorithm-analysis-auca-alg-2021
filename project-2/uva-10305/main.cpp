#include <bits/stdc++.h>

using namespace std;

enum class Status
{
    notVisited,
    visited
};

void dfs(int vertice, vector<vector<int>> &graph, vector<Status> &vertices, vector<int> &order)
{
    vertices[vertice] = Status::visited;

    for (auto &e : graph[vertice])
    {
        if (vertices[e] == Status::notVisited)
        {
            dfs(e, graph, vertices, order);
        }
    }
    order.push_back(vertice);
}

int main()
{
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0))
    {
        vector<vector<int>> graph(n);

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;

            graph[u - 1].push_back(v - 1);
        }

        // for (int i = 0; i < graph.size(); i++)
        // {
        //     cout << i << ": ";
        //     for (auto &e : graph[i])
        //     {
        //         cout << e << " ";
        //     }
        //     cout << "\n";
        // }

        vector<Status> states(n, Status::notVisited);
        vector<int> order;

        for (int i = 0; i < n; i++)
        {
            if (states[i] == Status::notVisited)
            {
                dfs(i, graph, states, order);
            }
        }

        reverse(order.begin(), order.end());

        for (int i = 0; i < order.size(); i++)
        {
            if (i == 0)
            {
                cout << order[i] + 1;
            }
            else
            {
                cout << " " << order[i] + 1;
            }
        }
        cout << "\n";
    }
}

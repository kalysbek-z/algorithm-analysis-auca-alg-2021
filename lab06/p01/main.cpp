#include <bits/stdc++.h>

using namespace std;

enum class Status
{
    notVisited,
    inProgress,
    visited
};

void dfs(int vertice, vector<vector<int>> &graph, vector<Status> &vertices, vector<int> &component)
{
    vertices[vertice] = Status::inProgress;

    component.push_back(vertice);

    for (auto &e : graph[vertice])
    {
        if (vertices[e] == Status::notVisited)
        {
            dfs(e, graph, vertices, component);
        }
    }

    vertices[vertice] = Status::visited;
}

int main()
{
    int nVertices;
    cin >> nVertices;

    vector<vector<int>> graph(nVertices);

    for (int r = 0; r < nVertices; r++)
    {
        for (int c = 0; c < nVertices; c++)
        {
            char ch;
            cin >> ch;
            if (ch == '1')
            {
                graph[r].push_back(c);
            }
        }
    }

    // for (size_t i = 0; i < graph.size(); i++)
    // {
    //     cout << i << ":";
    //     for (auto v : graph[i])
    //     {
    //         cout << " " << v;
    //     }
    //     cout << "\n";
    // }

    vector<Status> colors(nVertices, Status::notVisited);

    int nComponent = 0;
    for (size_t i = 0; i < nVertices; i++)
    {
        if (colors[i] == Status::notVisited)
        {
            nComponent++;
            vector<int> curComponent;
            dfs(i, graph, colors, curComponent);

            cout << nComponent << ":";
            for (auto e : curComponent)
            {
                cout << " " << e;
            }
            cout << "\n";
        }
    }
}
#include <bits/stdc++.h>

using namespace std;

enum class Status
{
    notVisited,
    inProgress,
    visited
};

void dfs(int vertice, vector<vector<int>> &graph, vector<Status> &vertices, vector<int> &order)
{
    vertices[vertice] = Status::inProgress;

    for (auto &e : graph[vertice])
    {
        if (vertices[e] == Status::inProgress)
        {
            throw runtime_error("Not directed acyclic graph " + to_string(e + 1));
        }
        if (vertices[e] == Status::notVisited)
        {
            dfs(e, graph, vertices, order);
        }
    }
    order.push_back(vertice);

    vertices[vertice] = Status::visited;
}

int main()
try
{
    string line;
    getline(cin, line);
    int nVertices = stoi(line);

    vector<vector<int>> graph(nVertices);
    for (int i = 0; i < nVertices; i++)
    {
        getline(cin, line);
        if (line != "-")
        {
            istringstream sinp(line);
            for (int v; sinp >> v;)
            {
                graph[i].push_back(v - 1);
            }
        }
    }

    vector<Status> colors(nVertices, Status::notVisited);
    vector<int> order;

    for (size_t i = 0; i < nVertices; i++)
    {
        if (colors[i] == Status::notVisited)
        {
            dfs(i, graph, colors, order);
        }
    }

    reverse(order.begin(), order.end());

    for (auto e : order)
    {
        cout << " " << e + 1;
    }
    cout << "\n";
}
catch (runtime_error &e)
{
    cerr << e.what();
}
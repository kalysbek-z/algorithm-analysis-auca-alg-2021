#include <bits/stdc++.h>

using namespace std;

const string kNil = "null";

enum class Status
{
    notVisited,
    inProgress,
    visited
};

int main()
{
    int nEdges;
    cin >> nEdges;

    map<string, vector<string>> graph;
    // s: w, r
    // r: s, w ...
    for (int i = 0; i < nEdges; i++)
    {
        string v1, v2;
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    string source, destination;
    cin >> source;
    cin >> destination;

    map<string, int> distances;
    map<string, string> preds;
    map<string, Status> states;

    for (const auto &e : graph)
    {
        states[e.first] = Status::notVisited;
        preds[e.first] = kNil;
    }

    queue<string> q;
    q.push(source);

    distances[source] = 0;
    states[source] = Status::inProgress;
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        states[u] = Status::visited;
        for (const auto e : graph[u])
        {
            if (states[e] == Status::notVisited)
            {
                states[e] = Status::inProgress;
                q.push(e);
                distances[e] = distances[u] + 1;
                preds[e] = u;
            }
        }
    }

    for (const auto &e : distances)
    {
        cout << e.first << ": " << e.second << "\n";
    }

    vector<string> path;
    string curVertex = destination;

    while (preds[curVertex] != kNil)
    {
        path.push_back(curVertex);
        curVertex = preds[curVertex];
    }
    path.push_back(source);

    reverse(path.begin(), path.end());
    for (const auto &e : path)
    {
        cout << e << " ";
    }
    cout << "\n";
}
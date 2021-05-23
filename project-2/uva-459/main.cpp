#include <bits/stdc++.h>

using namespace std;

enum class Status
{
    notVisited,
    inProgress,
    visited
};

void dfs(int vertice, vector<vector<int>> &graph, vector<Status> &vertices)
{
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
    int n;
    cin >> n;

    while (n--)
    {
        vector<vector<int>> graph(26);
        vector<Status> vertices(26, Status::notVisited);
        char s;
        cin >> s;
        int mainNode = s - 'A';
        cin.ignore();

        string ss;

        while (getline(cin, ss) && ss != "")
        {
            int v = ss[0] - 'A';
            int u = ss[1] - 'A';

            graph[v].push_back(u);
            graph[u].push_back(v);
        }
        int c = 0;

        for (int i = 0; i <= mainNode; ++i)
        {
            if (vertices[i] == Status::notVisited)
            {
                c++;
                dfs(i, graph, vertices);
            }
        }
        cout << c << "\n";

        if (n)
        {
            cout << "\n";
        }
    }
}
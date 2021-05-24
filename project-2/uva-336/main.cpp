#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int c = 1;

    while (cin >> n && n != 0)
    {
        map<int, vector<int>> graph;
        for (int i = 0; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int start, ttl;
        while (cin >> start >> ttl && (start != 0 || ttl != 0))
        {
            map<int, int> dist;
            queue<int> q;
            q.push(start);

            dist[start] = 0;

            while (!q.empty())
            {
                int t = q.front();
                q.pop();

                for (int i = 0; i < graph[t].size(); i++)
                {
                    int val = graph[t][i];

                    if (!dist.count(val))
                    {
                        dist[val] = dist[t] + 1;
                        q.push(val);
                    }
                }
            }
            int res = 0;
            for (auto it = dist.begin(); it != dist.end(); it++)
            {
                if (it->second > ttl)
                {
                    res++;
                }
            }
            res += graph.size() - dist.size();

            cout << "Case " << c++ << ": " << res << " nodes not reachable from node " << start << " with TTL = " << ttl << ".\n";
        }
    }
}
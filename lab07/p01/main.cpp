#include <bits/stdc++.h>

using namespace std;

enum class State
{
    notDefined,
    onBorder,
    inTree
};

const int kDistanceNotDefined = -1;

int main()
{
    int nVertices;
    cin >> nVertices;

    vector<vector<pair<int, int>>> graph(nVertices);

    char c1, c2;
    int weight;

    while (cin >> c1 >> c2 >> weight)
    {
        int v1 = c1 - 'a'; // convert char vertices into integer number
        int v2 = c2 - 'a';

        graph[v1].emplace_back(v2, weight);
        graph[v2].emplace_back(v1, weight);
    }

    vector<State> states(nVertices, State::notDefined);
    vector<int> distances(nVertices, kDistanceNotDefined);
    vector<int> preds(nVertices, kDistanceNotDefined);

    int totalWeight = 0;

    states[0] = State::inTree;

    for (auto v : graph[0])
    {
        states[v.first] = State::onBorder;
        distances[v.first] = v.second;
        preds[v.first] = 0;
    }

    // O(N*N)
    for (int i = 1; i < nVertices; i++)
    {
        int indexOfMin = -1;
        for (int j = 0; j < nVertices; j++)
        {
            if (states[j] == State::onBorder && (indexOfMin == -1 || distances[j] < distances[indexOfMin]))
            {
                indexOfMin = j;
            }
        }

        int u = preds[indexOfMin];
        int v = indexOfMin;
        int w = distances[v];

        cout << char(u + 'a') << " " << char(v + 'a') << " " << w << "\n";

        totalWeight += w;

        states[v] = State::inTree;
        for (auto e : graph[v])
        {
            if (states[e.first] == State::notDefined)
            {
                states[e.first] = State::onBorder;
                distances[e.first] = e.second;
                preds[e.first] = v;
            }
            else if (states[e.first] == State::onBorder && e.second < distances[e.first])
            {
                distances[e.first] = e.second;
                preds[e.first] = v;
            }
        }
    }

    cout << "Total weight: " << totalWeight << "\n";
}
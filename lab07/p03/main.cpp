#include <bits/stdc++.h>

using namespace std;

enum class State
{
    notDefined,
    onBorder,
    inTree
};

const int kUndefinedWeight = -1;

int main()
{
    int nVertices;
    cin >> nVertices;

    string source, dest;
    cin >> source >> dest;

    map<string, vector<pair<string, int>>> graph;

    { //input
        string v1, v2;
        int w;

        while (cin >> v1 >> v2 >> w)
        {
            graph[v1].emplace_back(v2, w);
        }
    }

    map<string, State> states;
    map<string, int> weights;
    map<string, string> preds;

    for (const auto &e : graph)
    {
        states[e.first] = State::notDefined;
        weights[e.first] = kUndefinedWeight;
    }

    set<pair<int, string>> border;

    states[source] = State::onBorder;
    weights[source] = 0;
    border.emplace(0, source);

    while (!border.empty())
    {
        auto p = *border.begin();
        border.erase(border.begin());

        string u = p.second;
        states[u] = State::inTree;

        for (const auto &v : graph[u])
        {
            State state = states[v.first];
            if (state == State::notDefined)
            {
                states[v.first] = State::onBorder;
                preds[v.first] = u;
                int w = weights[u] + v.second;
                weights[v.first] = w;
                border.emplace(w, v.first);
            }
            else if (state == State::onBorder)
            {
                int w1 = weights[v.first];
                int w2 = weights[u] + v.second;
                if (w1 > w2)
                {
                    border.erase({w1, v.first});
                    border.emplace(w2, v.first);
                    weights[v.first] = w2;
                    preds[v.first] = u;
                }
            }
        }
    }

    for (const auto &e : weights)
    {
        cout << e.first << " " << e.second << "\n";
    }

    if (weights[dest] == kUndefinedWeight)
    {
        cout << "Unreachable\n";
    }
    else
    {
        vector<string> path = {dest};
        while (path.back() != source)
        {
            path.push_back(preds[path.back()]);
        }

        reverse(path.begin(), path.end());

        for (const auto e : path)
        {
            cout << e << " ";
        }
        cout << "\n";

        cout << "Total weight: " << weights[dest] << "\n";
    }
}

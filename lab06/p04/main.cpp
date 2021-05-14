#include <bits/stdc++.h>

using namespace std;

enum class Status
{
    notVisited,
    inProgress,
    visited
};

const int kNoPred = -1;

bool inside(const vector<string> &maze, int r, int c)
{
    int h = maze.size();
    int w = maze[0].size();

    return 0 <= r && r < h && 0 <= c && c < w;
}

int main()
{
    int size; // size of maze
    cin >> size;

    vector<string> maze(size);
    int start;
    int dest;
    for (int r = 0; r < size; r++)
    {
        cin >> maze[r];
        int cStart = maze[r].find('S');
        if (cStart != int(string::npos))
        {
            start = r * size + cStart;
        }

        int cDest = maze[r].find('D');
        if (cDest != int(string::npos))
        {
            dest = r * size + cDest;
        }
    }

    vector<int> distances(size * size);
    vector<int> preds(size * size, kNoPred);
    vector<Status> states(size * size, Status::notVisited);

    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    queue<int> q;
    q.push(start);
    states[start] = Status::inProgress;
    distances[start] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        states[cur] = Status::visited;

        int r = cur / size;
        int c = cur % size;
        for (int i = 0; i < int(dr.size()); i++)
        {
            int tr = r + dr[i];
            int tc = c + dc[i];
            int t = tr * size + tc;
            if (inside(maze, tr, tc) && maze[tr][tc] != '#' && states[t] == Status::notVisited)
            {
                q.push(t);
                states[t] = Status::inProgress;
                preds[t] = cur;
                distances[t] = distances[cur] + 1;
                if (t == dest)
                {
                    goto breakForWhile;
                }
            }
        }
    }

breakForWhile:
    if (preds[dest] == kNoPred)
    {
        cout << "Unreachable\n";
    }
    else
    {
        cout << distances[dest] << "\n";
        int cur = dest;

        while (cur != start)
        {
            maze[cur / size][cur % size] = '*';
            cur = preds[cur];
        }
        for (const auto &e : maze)
        {
            cout << e << "\n";
        }
    }
}
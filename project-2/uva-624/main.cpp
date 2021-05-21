#include <bits/stdc++.h>

using namespace std;

int d, n;
int maxSum = 0;
vector<int> vec;

void solve(int cur, int sum, const vector<int> &v, vector<int> &t)
{
    if ((int)v.size() == cur)
    {
        if (sum > maxSum && sum <= d)
        {
            maxSum = sum;
            vec = t;
        }
    }
    else
    {
        t[cur] = 0;
        solve(cur + 1, sum, v, t);
        t[cur] = 1;
        solve(cur + 1, sum + v[cur], v, t);
    }
}

int main()
{
    for (; cin >> d >> n;)
    {
        vector<int> tracks(n);
        vector<int> list(n);

        for (auto &e : tracks)
        {
            cin >> e;
        }

        solve(0, 0, tracks, list);

        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == 1)
            {
                cout << tracks[i] << " ";
            }
        }
        cout << "sum:" << maxSum << "\n";
    }
}
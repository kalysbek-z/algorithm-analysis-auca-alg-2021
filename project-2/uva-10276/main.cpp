#include <bits/stdc++.h>

using namespace std;

class Solver
{
    int res = 0;
    vector<int> vec;
    int mPegs;

public:
    Solver(int pegs) : mPegs(pegs)
    {
        vec.resize(50);
    }

    void solve(int num, int pos)
    {
        if (pos == mPegs)
        {
            print();
            return;
        }
        else if (vec[pos] == 0)
        {
            vec[pos] = num;
            res++;
            return solve(num + 1, pos);
        }

        for (int i = 0; i <= pos; i++)
        {
            int root = sqrt(vec[i] + num);

            if ((root * root) == vec[i] + num)
            {
                vec[i] = num;
                res++;
                return solve(num + 1, pos);
            }
        }

        solve(num, pos + 1);
    }

    void print()
    {
        cout << res << "\n";
    }

    void run()
    {
        solve(1, 0);
    }
};

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int pegs;
        cin >> pegs;
        Solver(pegs).run();
    }
}
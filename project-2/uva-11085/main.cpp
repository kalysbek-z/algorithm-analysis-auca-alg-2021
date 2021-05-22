#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

vector<int> vec;

class Solver
{
    int mN = 8;
    vector<bool> rows;
    vector<bool> diag1;
    vector<bool> diag2;
    vector<int> mSolution;
    int minMoves = 10000;

public:
    Solver()
    {
        rows.resize(8, false);
        diag1.resize(15);
        diag2.resize(15);
        mSolution.resize(8);
    }

    void solve(int col, int m)
    {
        if (col == vec.size())
        {
            if (m < minMoves)
            {
                minMoves = m;
            }
            return;
        }
        if (m > minMoves)
        {
            return;
        }

        for (int row = 0; row < mN; row++)
        {
            if (canPutQueen(row, col))
            {
                putQueen(row, col);
                if (vec[col] == row)
                {
                    solve(col + 1, m);
                }
                else
                {
                    solve(col + 1, m + 1);
                }
                takeQueen(row, col);
            }
        }
    }

    bool canPutQueen(int row, int col)
    {
        return !rows[row] && !diag1[row + col] && !diag2[col - row + mN];
    }

    void putQueen(int row, int col)
    {
        rows[row] = diag1[row + col] = diag2[col - row + mN] = true;
        // mSolution[col] = row;
    }

    void takeQueen(int row, int col)
    {
        rows[row] = diag1[row + col] = diag2[col - row + mN] = false;
    }

    void print()
    {
        cout << minMoves << "\n";
    }
};

int main()
{
    int c = 1;
    vec.resize(8);
    while (cin >> vec[0] >> vec[1] >> vec[2] >> vec[3] >> vec[4] >> vec[5] >> vec[6] >> vec[7])
    {
        for (int i = 0; i < 8; i++)
        {
            vec[i]--;
        }

        Solver sol;
        sol.solve(0, 0);

        cout << "Case " << c++ << ": ";
        sol.print();
    }
}
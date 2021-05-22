#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

int r, c;

class Solver
{
    int mN = 8;
    int counter = 0;
    vector<bool> rows;
    vector<bool> diag1;
    vector<bool> diag2;
    vector<int> mSolution;

public:
    Solver()
    {
        rows.resize(8, false);
        diag1.resize(15);
        diag2.resize(15);
        mSolution.resize(8);
    }

    void solve(int col)
    {
        if (col == mN && mSolution[c] == r)
        {
            print();
        }
        else
        {
            for (int row = 0; row < mN; row++)
            {
                if (canPutQueen(row, col))
                {
                    putQueen(row, col);
                    solve(col + 1);
                    takeQueen(row, col);
                }
            }
        }
    }

    bool canPutQueen(int row, int col)
    {
        return !rows[row] && !diag1[row + col] && !diag2[col - row + mN - 1];
    }

    void putQueen(int row, int col)
    {
        rows[row] = diag1[row + col] = diag2[col - row + mN - 1] = true;
        mSolution[col] = row;
    }

    void takeQueen(int row, int col)
    {
        rows[row] = diag1[row + col] = diag2[col - row + mN - 1] = false;
    }

    void print()
    {
        counter++;
        if (counter < 10)
        {
            cout << " " << counter << "      ";
        }
        else
        {
            cout << counter << "      ";
        }

        for (int i = 0; i < mN; i++)
        {
            if (i != 0)
            {
                cout << " ";
            }
            if (mSolution[i] + 1)
                cout << mSolution[i] + 1;
        }
        cout << "\n";
        // for (auto e : mSolution)
        // {
        //     cout << " " << e;
        // }
        // cout << "\n";
    }

    void run()
    {
        solve(0);
    }
};

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> r >> c;
        r--;
        c--;

        if (i != 0)
        {
            cout << "\n";
        }
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        Solver().run();
    }
}
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class Solver
{
    struct Frame
    {
        int mRow;
        int mCol;
        Frame(int row, int col)
            : mRow(row), mCol(col)
        {
        }
    };
    int mN;
    vector<bool> rows;
    vector<bool> diag1;
    vector<bool> diag2;
    vector<int> mSolution;

public:
    Solver(int n) : mN(n)
    {
        if (n < 1)
        {
            throw runtime_error("Incorrect size");
        }
        rows.resize(n, false);
        diag1.resize(2 * n - 1);
        diag2.resize(2 * n - 1);
        mSolution.resize(n);
    }

    void solve(int col)
    {
        if (col == mN)
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
        for (auto e : mSolution)
        {
            cout << " " << e;
        }
        cout << "\n";
    }

    void run()
    {
        // solve(0);
        vector<Frame> stack;
        stack.emplace_back(0, 0);
        while (!stack.empty())
        {
            if (stack.back().mCol == mN)
            {
                print();
                stack.pop_back();
                takeQueen(stack.back().mRow, stack.back().mCol);
                stack.back().mRow++;
            }
            else if (stack.back().mRow == mN)
            {
                stack.pop_back();
                if (!stack.empty())
                {
                    takeQueen(stack.back().mRow, stack.back().mCol);
                    stack.back().mRow++;
                }
            }
            else if (canPutQueen(stack.back().mRow, stack.back().mCol))
            {
                putQueen(stack.back().mRow, stack.back().mCol);
                stack.emplace_back(0, stack.back().mCol + 1);
            }
            else
            {
                stack.back().mRow++;
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    Solver(n).run();
}
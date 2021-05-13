#include <iostream>

using namespace std;

void solve(int n, int source, int temp, int des)
{
    if (n > 1)
    {
        solve(n - 1, source, des, temp);
        cout << source << " -> " << des << "\n";
        solve(n - 1, temp, source, des);
    }
    else if (n == 1)
    {
        cout << source << " -> " << des << "\n";
    }
}

int main()
{
    int n;
    cin >> n;
    solve(n, 1, 2, 3);
}
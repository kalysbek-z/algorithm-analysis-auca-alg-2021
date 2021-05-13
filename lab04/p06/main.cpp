#include <iostream>
#include <cstdint>

using namespace std;

int fib(int64_t n)
{
    if (n <= 1)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int64_t fibIter(int64_t n)
{
    if (n <= 1)
    {
        return 1;
    }
    int64_t prev1 = 1;
    int64_t prev2 = 1;
    for (int i = 2; i <= n; i++)
    {
        int64_t t = prev1 + prev2;
        prev2 = prev1;
        prev1 = t;
    }
    return prev1;
}

int main()
{
    for (int n; cin >> n;)
    {
        // cout << "fib(" << n << ") = " << fib(n) << "\n";
        cout << "fib(" << n << ") = " << fibIter(n) << "\n";
    }
}
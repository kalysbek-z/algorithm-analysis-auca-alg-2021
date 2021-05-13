#include <iostream>

using namespace std;

int64_t factorial(int n)
{
    return n == 0 ? 1 : n * factorial(n - 1);
}

int main()
{
    for (int n; cin >> n;)
    {
        cout << n << "! = " << factorial(n) << "\n";
    }
}

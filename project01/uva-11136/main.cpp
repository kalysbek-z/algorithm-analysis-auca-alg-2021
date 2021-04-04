#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        multiset<int> bills;
        long sum = 0;
        while (n--)
        {
            int m;
            cin >> m;

            while (m--)
            {
                int k;
                cin >> k;
                bills.insert(k);
            }

            auto max = --bills.end();
            auto min = bills.begin();

            sum += *max - *min;

            bills.erase(min);
            bills.erase(max);
        }

        // cout << *max << "," << *min << "\n";
        cout << sum << "\n";
    }
}

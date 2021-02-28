#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l1, l2;
        cin >> l1 >> l2;
        unordered_multiset<int> list1;
        unordered_multiset<int> list2;
        unordered_multiset<int>::iterator it;
        int c = 0;
        while (l1--)
        {
            int n;
            cin >> n;
            list1.insert(n);
        }
        while (l2--)
        {
            int n;
            cin >> n;
            list2.insert(n);
            it = list1.find(n);
            if (it != list1.end())
            {
                list1.erase(it);
            }
            else
            {
                c++;
                // cout << "counter: " << c << "\n";
            }
        }
        cout << list1.size() + c << "\n";
        // cout << list1.size() << " " << c << "\n";
    }
}
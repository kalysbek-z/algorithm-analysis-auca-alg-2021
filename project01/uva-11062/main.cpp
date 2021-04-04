#include <cctype>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    set<string> res;
    string w;
    char c[500000];
    while (gets(c))
    {
        if (c[0] == 0)
            continue;
        for (int i = 0; c[i] != 0; i++)
        {
            if (isalpha(c[i]) || c[i] == '-')
            {
                w += tolower(c[i]);
            }
            else if (!isalpha(c[i]) && c[i] != '-')
            {
                res.insert(w);
                w.clear();
            }
        }
        if (!w.empty())
        {
            if (w[w.size() - 1] != '-')
            {
                res.insert(w);
                w.clear();
            }
            else
            {
                w.erase(w.end() - 1);
            }
        }
    }
    auto it = res.begin();
    it++;

    for (; it != res.end(); it++)
    {
        cout << *it << "\n";
    }
}

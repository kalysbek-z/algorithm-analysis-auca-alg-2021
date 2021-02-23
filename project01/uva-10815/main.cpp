#include <cctype>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    set<string> res;
    string w;
    for (char c; cin.get(c);)
    {
        if (isalpha(c))
        {
            w += tolower(c);
        }
        else if (!w.empty())
        {
            res.insert(w);
            w.clear();
        }
    }
    if (!w.empty())
    {
        res.insert(w);
    }

    for (auto &e : res)
    {
        cout << e << "\n";
    }
}

#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
    map<string, set<int>> d;

    int nLine = 0;
    for (string l; getline(cin, l);)
    {
        nLine++;
        istringstream sinp(l);
        for (string w; sinp >> w;)
        {
            d[w].insert(nLine);
        }
    }

    for (const auto &p : d)
    {
        cout << p.first << ":";
        for (const auto &e : p.second)
        {
            cout << " " << e;
        }
        cout << "\n";
    }
}
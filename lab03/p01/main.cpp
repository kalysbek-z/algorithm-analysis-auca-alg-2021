#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, int> d;
    for (string w; cin >> w;)
    {
        ++d[w];
    }
    for (const auto &p : d)
    {
        cout << p.first << " " << p.second << "\n";
    }
}
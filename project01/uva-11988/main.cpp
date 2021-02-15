#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
    for (string in; getline(cin, in);)
    {
        list<char> res;
        auto pos = res.end();
        for (auto c : in)
        {
            if (c == '[')
            {
                pos = res.begin();
            }
            else if (c == ']')
            {
                pos = res.end();
            }
            else
            {
                res.insert(pos, c);
            }
        }
        cout << string(res.begin(), res.end()) << endl;
    }
}
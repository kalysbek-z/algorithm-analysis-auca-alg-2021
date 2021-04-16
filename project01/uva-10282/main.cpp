#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    unordered_map<string, string> dic; //word .. foreign word
    stringstream ss;
    while (getline(cin, line) && line != "")
    {
        stringstream ss(line);
        string w, fw;

        ss >> w >> fw;

        dic[fw] = w;
    }
    while (cin >> line)
    {
        auto it = dic.find(line);
        if (it != dic.end())
        {
            // cout << dic[line] << "\n";
            printf("%s\n", dic[line].c_str());
        }
        else
        {
            printf("eh\n");
        }
    }
}
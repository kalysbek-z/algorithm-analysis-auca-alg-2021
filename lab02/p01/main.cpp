#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
    unordered_set<string> setOfWords;
    auto hash = setOfWords.hash_function();

    for (string line; getline(cin, line);)
    {
        istringstream sinp(line);

        cout << "bucket count: " << setOfWords.bucket_count() << "\n";
        string cmd;
        sinp >> cmd;

        if (cmd == "+")
        {
            string w;
            sinp >> w;
            cout << "hash val: " << hash(w) << "\n";
            cout << "bucket's index: " << hash(w) % setOfWords.bucket_count() << "\n";
            auto p = setOfWords.insert(w);
            cout << (p.second ? "yes" : "no") << "\n";
        }
        else if (cmd == "?")
        {
            string w;
            sinp >> w;
            cout << "hash val: " << hash(w) << "\n";
            cout << "bucket's index: " << hash(w) % setOfWords.bucket_count() << "\n";
            auto it = setOfWords.find(w);
            cout << (it != setOfWords.end() ? "yes" : "no") << "\n";
        }
        else if (cmd == "-")
        {
            string w;
            sinp >> w;
            cout << "hash val: " << hash(w) << "\n";
            cout << "bucket's index: " << hash(w) % setOfWords.bucket_count() << "\n";
            cout << (setOfWords.erase(w) ? "yes" : "no") << "\n";
        }
        else if (cmd == "#")
        {
            for (size_t i = 0; i < setOfWords.bucket_count(); i++)
            {
                cout << setw(4) << i << ":";
                for (auto p = setOfWords.begin(i); p != setOfWords.end(i); p++)
                {
                    cout << " " << *p;
                }
            }
            cout << "\n";
        }
    }
}
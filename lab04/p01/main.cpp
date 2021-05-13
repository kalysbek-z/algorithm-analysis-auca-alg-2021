#include <iostream>

using namespace std;

void readAndPrintInReversedOrder()
{
    int x;
    if (cin >> x)
    {
        readAndPrintInReversedOrder();
        cout << " " << x;
    }
}

int main()
{
    readAndPrintInReversedOrder();
    cout << "\n";
}
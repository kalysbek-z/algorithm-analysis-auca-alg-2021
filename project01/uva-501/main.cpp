#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    scanf("%d", &k);
    int cc = 0;
    while (k--)
    {
        if (cc > 0)
        {
            printf("\n");
        }
        int m, n;
        scanf("%d %d", &m, &n);
        vector<int> addElem;
        vector<int> queueOfElem;

        multiset<int> elem;

        // initializing elements
        for (int i = 0; i < m; i++)
        {
            int num;
            scanf("%d", &num);
            addElem.push_back(num);
        }
        //initializing queue of adding
        for (int i = 0; i < n; i++)
        {
            int num;
            scanf("%d", &num);
            queueOfElem.push_back(num);
        }

        elem.insert(addElem[0]);
        auto iter = elem.begin(); //current elem[index] number (answer)

        int index = 0;

        for (int i = 1; i <= m; i++)
        {
            while (index < n && queueOfElem[index] == i)
            {
                printf("%d\n", *iter);
                index++;
                iter++;
            }

            elem.insert(addElem[i]);

            if (addElem[i] < *iter || iter == elem.end())
            {
                iter--;
            }
        }
        cc++;
    }
}
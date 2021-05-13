#include "MapStrInt.hpp"

#include <bits/stdc++.h>

using namespace std;

int &MapStrInt::operator[](const string &k)
{
    Node *pred = nullptr;
    Node *curr = mRoot;
    bool isLeft = false;
    while (curr != nullptr)
    {
        pred = curr;
        if (k < curr->mData.first)
        {
            isLeft = true;
            curr = curr->mLeft;
        }
        else if (curr->mData.first < k)
        {
            isLeft = false;
            curr = curr->mRight;
        }
        else
        {
            return curr->mData.second;
        }
    }

    Node *p = new Node(k, 0, nullptr, nullptr);

    ++mSize;

    if (mRoot == nullptr)
    {
        mRoot = p;
    }
    else if (isLeft)
    {
        pred->mLeft = p;
    }
    else
    {
        pred->mRight = p;
    }

    return p->mData.second;
}

void MapStrInt::printInOrder(std::ostream &out, Node *root) const
{
    if (root != nullptr)
    {
        printInOrder(out, root->mLeft);
        out << root->mData.first << ": " << root->mData.second << "\n";
        printInOrder(out, root->mRight);
    }
}
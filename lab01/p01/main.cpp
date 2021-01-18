#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int mData;

    Node *mPrev;
    Node *mNext;

    Node(int data, Node *prev, Node *next)
        : mData(data), mPrev(prev), mNext(next)
    {
    }
};

void printInDirectOrder(Node *head)
{
    for (Node *p = head; p; p = p->mNext)
    {
        cout << " " << p->mData;
    }
    cout << "\n";
}

void printInReversedOrder(Node *tail)
{
    for (Node *p = tail; p; p = p->mPrev)
    {
        cout << " " << p->mData;
    }
    cout << "\n";
}

void pushBack(Node *&head, Node *&tail, int elem)
{
    if (!head)
    {
        head = tail = new Node(elem, nullptr, nullptr);
    }
    else
    {
        tail->mNext = new Node(elem, tail, nullptr);
        tail = tail->mNext;
    }
}

void clear(Node *&head, Node *&tail)
{
    Node *current = head;

    while (current != nullptr)
    {
        Node *t = current->mNext;
        delete current;
        current = t;
    }

    head = tail = nullptr;
}

void insertBefore(Node *&head, Node *curr, int data)
{
    if (head == curr)
    {
        curr->mPrev = new Node(data, nullptr, curr);
        head = curr->mPrev;
    }
    else
    {
        Node *t = new Node(data, curr->mPrev, curr);
        t->mPrev->mNext = t;
        t->mNext->mPrev = t;
    }
}
Node *erase(Node *&head, Node *&tail, Node *curr)
{
    if (curr == head && curr == tail)
    {
        delete head;
        head = tail = nullptr;
        return nullptr;
    }
    else if (curr == head)
    {
        head = head->mNext;
        head->mPrev = nullptr;
        delete curr;
        return head;
    }
    else if (curr == tail)
    {
        tail = tail->mPrev;
        tail->mNext = nullptr;
        delete curr;
        return nullptr;
    }

    Node *t = curr->mNext;
    curr->mPrev->mNext = curr->mNext;
    curr->mNext->mPrev = curr->mPrev;
    delete curr;
    return t;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    for (int i; cin >> i;)
    {
        pushBack(head, tail, i);
    }

    printInDirectOrder(head);
    printInReversedOrder(tail);

    for (Node *p = head; p != nullptr; p = p->mNext)
    {
        if (p->mData % 2 == 0)
        {
            insertBefore(head, p, 0);
        }
    }

    printInDirectOrder(head);
    printInReversedOrder(tail);

    for (Node *p = head; p != nullptr;)
    {
        if (p->mData % 2 == 0)
        {
            p = erase(head, tail, p);
        }
        else
        {
            p = p->mNext;
        }
    }

    printInDirectOrder(head);
    printInReversedOrder(tail);

    clear(head, tail);
}
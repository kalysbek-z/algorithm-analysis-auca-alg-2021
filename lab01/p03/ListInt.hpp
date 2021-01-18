#pragma once
#include <cstddef>

class ListInt
{
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

    Node *mHead;
    Node *mTail;
    std::size_t mSize;

public:
    ListInt()
        : mHead(nullptr), mTail(nullptr), mSize(0)
    {
    }

    std::size_t size() const
    {
        return mSize;
    }
};
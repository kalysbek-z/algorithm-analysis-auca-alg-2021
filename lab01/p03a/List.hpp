#pragma once

#include <cstddef>
#include <string>
#include <sstream>

template <typename T>
class List
{
    struct Node
    {
        T mData;

        Node *mPrev;
        Node *mNext;

        Node(const T &data, Node *prev, Node *next)
            : mData(data), mPrev(prev), mNext(next)
        {
        }
    };

    Node *mHead;
    Node *mTail;
    std::size_t mSize;

public:
    List()
        : mHead(new Node(T(), nullptr, nullptr)),
          mTail(new Node(T(), nullptr, nullptr)),
          mSize(0)
    {
        mHead->mNext = mTail;
        mTail->mPrev = mHead;
    }

    //copy contructor
    List(const List &other)
        : mHead(new Node(T(), nullptr, nullptr)),
          mTail(new Node(T(), nullptr, nullptr)),
          mSize(0)
    {
        mHead->mNext = mTail;
        mTail->mPrev = mHead;

        for (auto p = other.begin(); p != other.end(); p++)
        {
            pushBack(*p);
        }
    }

    //move contructor
    List(List &&other)
        : mHead(new Node(T(), nullptr, nullptr)),
          mTail(new Node(T(), nullptr, nullptr)),
          mSize(0)
    {
        mHead = other.mHead;
        other.mHead = nullptr;

        mTail = other.mTail;
        other.mTail = nullptr;

        mSize = other.mSize;
        other.mSize = 0;
    }

    ~List()
    {
        clear();

        delete mHead;
        delete mTail;
    }

    void clear()
    {
        while (begin() != end())
        {
            erase(begin());
        }
    }

    std::size_t size() const
    {
        return mSize;
    }

    std::string toStr() const
    {
        std::ostringstream out;

        out << "{";
        Node *p = mHead->mNext;
        for (std::size_t i = 0; i < mSize; i++)
        {
            if (i != 0)
            {
                out << ", ";
            }
            out << p->mData;
            p = p->mNext;
        }
        out << "}";

        return out.str();
    }

    std::string toReverseStr() const
    {
        std::ostringstream out;

        out << "{";
        Node *p = mTail->mPrev;
        for (std::size_t i = 0; i < mSize; i++)
        {
            if (i != 0)
            {
                out << ", ";
            }
            out << p->mData;
            p = p->mPrev;
        }
        out << "}";

        return out.str();
    }

    void pushBack(const T &x)
    {
        Node *t = new Node(x, mTail->mPrev, mTail);
        mTail->mPrev->mNext = t;
        mTail->mPrev = t;
        mSize++;
    }

    void popBack()
    {
        if (mHead != mTail)
        {
            Node *t = mTail->mPrev;
            mTail->mPrev->mPrev->mNext = mTail;
            mTail->mPrev = mTail->mPrev->mPrev;

            delete t;
            mSize--;
        }
    }

    void pushFront(const T &x)
    {
        Node *t = new Node(x, mHead, mHead->mNext);
        mHead->mNext->mPrev = t;
        mHead->mNext = t;
        mSize++;
    }

    void popFront()
    {
        if (mHead != mTail)
        {
            Node *t = mHead->mNext;
            mHead->mNext->mNext->mPrev = mHead;
            mHead->mNext = mHead->mNext->mNext;

            delete t;
            mSize--;
        }
    }

    class Iter;

    Iter begin() const
    {
        Iter r;
        r.mPtr = mHead->mNext;
        return r;
    }

    Iter end() const
    {
        Iter r;
        r.mPtr = mTail;
        return r;
    }

    class RIter;

    RIter rbegin()
    {
        RIter r;
        r.mPtr = mTail->mPrev;
        return r;
    }

    RIter rend()
    {
        RIter r;
        r.mPtr = mHead;
        return r;
    }

    Iter insert(Iter p, const T &x)
    {
        Iter t;
        t.mPtr = new Node(x, p.mPtr->mPrev, p.mPtr);
        p.mPtr->mPrev = t.mPtr;
        t.mPtr->mPrev->mNext = t.mPtr;
        ++mSize;

        return t;
    }

    Iter erase(Iter p)
    {
        Iter r = p;
        ++r;

        p.mPtr->mPrev->mNext = p.mPtr->mNext;
        p.mPtr->mNext->mPrev = p.mPtr->mPrev;
        delete p.mPtr;
        mSize--;

        return r;
    }
};

template <typename T>
class List<T>::Iter
{
    friend class List<T>;
    Node *mPtr;

public:
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;

    Iter()
        : mPtr(nullptr)
    {
    }

    T &operator*() const
    {
        return mPtr->mData;
    }

    T *operator->() const
    {
        return &(mPtr->mData);
    }

    Iter &operator++()
    {
        mPtr = mPtr->mNext;
        return *this;
    }

    Iter operator++(int)
    {
        Iter r = *this;
        mPtr = mPtr->mNext;
        return r;
    }

    Iter &operator--()
    {
        mPtr = mPtr->mPrev;
        return *this;
    }

    Iter operator--(int)
    {
        Iter r = *this;
        mPtr = mPtr->mPrev;
        return r;
    }

    bool operator==(const Iter &other) const
    {
        return mPtr == other.mPtr;
    }

    bool operator!=(const Iter &other) const
    {
        return !(*this == other);
    }

    // Iter &operator=(Iter &&other)
    // {
    //     if (this != &other)
    //     {
    //         clear();

    //         mPtr->mHead = other.mPtr->mHead;
    //         other.mPtr->mHead = nullptr;

    //         mPtr->mTail = other.mPtr->mTail;
    //         other.mPtr->mTail = nullptr;
    //     }
    //     return *this;
    // }
};

template <typename T>
class List<T>::RIter
{
    friend class List<T>;
    Node *mPtr;

public:
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;

    RIter()
        : mPtr(nullptr)
    {
    }

    T &operator*() const
    {
        return mPtr->mData;
    }

    T *operator->() const
    {
        return &(mPtr->mData);
    }

    RIter &operator++()
    {
        mPtr = mPtr->mPrev;
        return *this;
    }

    RIter operator++(int)
    {
        RIter r = *this;
        mPtr = mPtr->mPrev;
        return r;
    }

    RIter &operator--()
    {
        mPtr = mPtr->mNext;
        return *this;
    }

    RIter operator--(int)
    {
        RIter r = *this;
        mPtr = mPtr->mNext;
        return r;
    }

    bool operator==(const RIter &other) const
    {
        return mPtr == other.mPtr;
    }

    bool operator!=(const RIter &other) const
    {
        return !(*this == other);
    }
};
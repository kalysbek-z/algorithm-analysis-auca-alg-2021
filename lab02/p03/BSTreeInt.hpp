#pragma once

#include <cstddef>
#include <ostream>

#define AUCA_DEBUG
#ifdef AUCA_DEBUG
#include <string>
#endif

class BSTreeInt
{
    struct Node
    {
        int mData;
        Node *mLeft;
        Node *mRight;
        Node(int data, Node *left, Node *right)
            : mData(data), mLeft(left), mRight(right)
        {
        }
    };

    Node *root;
    std::size_t sz;

    void eraseLeaf(Node *curr, Node *prev, bool isLeft);
    void eraseNodeWithOneChild(Node *curr, Node *prev, bool isLeft);
    void eraseNodeWithTwoChildren(Node *curr);

public:
#ifdef AUCA_DEBUG
    mutable std::string debug;
#endif

    BSTreeInt()
        : root(nullptr), sz(0)
    {
    }

    ~BSTreeInt()
    {
        clear();
    }

    BSTreeInt(const BSTreeInt &) = delete;
    BSTreeInt &operator=(const BSTreeInt &) = delete;

    std::size_t size() const
    {
        return sz;
    }

    bool insert(int x);
    bool find(int x) const;
    void print(std::ostream &out) const;
    void clear();
    bool erase(int x);
};
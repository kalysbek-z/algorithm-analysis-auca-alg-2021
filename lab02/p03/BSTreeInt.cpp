#include "BSTreeInt.hpp"

#include <utility>
#include <vector>

#ifdef AUCA_DEBUG
#include <sstream>
#endif

bool BSTreeInt::insert(int x)
{
#ifdef AUCA_DEBUG
    debug.clear();
#endif

    if (sz == 0)
    {
        root = new Node(x, nullptr, nullptr);
        ++sz;
        return true;
    }

    bool isLeft = false;
    Node *prev = nullptr;
    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->mData == x)
        {
            return false;
        }
        else if (curr->mData < x)
        {
#ifdef AUCA_DEBUG
            debug += "R";
#endif
            isLeft = false;
            prev = curr;
            curr = curr->mRight;
        }
        else
        {
#ifdef AUCA_DEBUG
            debug += "L";
#endif
            isLeft = true;
            prev = curr;
            curr = curr->mLeft;
        }
    }

    if (isLeft)
    {
        prev->mLeft = new Node(x, nullptr, nullptr);
    }
    else
    {
        prev->mRight = new Node(x, nullptr, nullptr);
    }

    ++sz;

    return true;
}

bool BSTreeInt::find(int x) const
{
    Node *curr = root;
    while (curr != nullptr)
    {
        if (x == curr->mData)
        {
            return true;
        }
        if (curr->mData < x)
        {
            curr = curr->mRight;
        }
        else
        {
            curr = curr->mLeft;
        }
    }
    return false;
}

void BSTreeInt::clear()
{
    enum class Operation
    {
        goLeft,
        goRight,
        eraseNode,
        remove
    };

    std::vector<std::pair<Node *, Operation>> stack;
    stack.emplace_back(root, Operation::goLeft);

#ifdef AUCA_DEBUG
    std::ostringstream out;
    bool isFirst = true;
    out << "{";
#endif

    while (!stack.empty())
    {
        auto &back = stack.back();
        if (back.first == nullptr || back.second == Operation::remove)
        {
            stack.pop_back();
        }
        else if (back.second == Operation::goLeft)
        {
            back.second = Operation::goRight;
            stack.emplace_back(back.first->mLeft, Operation::goLeft);
        }
        else if (back.second == Operation::goRight)
        {
            back.second = Operation::eraseNode;
            stack.emplace_back(back.first->mRight, Operation::goLeft);
        }
        else if (back.second == Operation::eraseNode)
        {
#ifdef AUCA_DEBUG
            if (!isFirst)
            {
                out << ", ";
            }
            isFirst = false;
            out << back.first->mData;
#endif
            delete back.first;
            --sz;
            back.second = Operation::remove;
        }
    }
#ifdef AUCA_DEBUG
    out << "}";
    debug = out.str();
#endif

    root = nullptr;
}

void BSTreeInt::print(std::ostream &out) const
{
    enum class Operation
    {
        goLeft,
        print,
        goRight,
        remove
    };

    std::vector<std::pair<Node *, Operation>> stack;

    stack.emplace_back(root, Operation::goLeft);

    bool isFirst = true;
    out << "{";
    while (!stack.empty())
    {
        auto &back = stack.back();
        if (back.first == nullptr || back.second == Operation::remove)
        {
            stack.pop_back();
        }
        else if (back.second == Operation::goLeft)
        {
            back.second = Operation::print;
            stack.emplace_back(back.first->mLeft, Operation::goLeft);
        }
        else if (back.second == Operation::print)
        {
            if (!isFirst)
            {
                out << ", ";
            }
            isFirst = false;
            back.second = Operation::goRight;
            out << back.first->mData;
        }
        else if (back.second == Operation::goRight)
        {
            back.second = Operation::remove;
            stack.emplace_back(back.first->mRight, Operation::goLeft);
        }
    }
    out << "}";
}

bool BSTreeInt::erase(int x)
{
    bool isLeft = true;
    Node *prev = nullptr;
    Node *curr = root;
    while (curr != nullptr)
    {
        if (x == curr->mData)
        {
            break;
        }
        else if (curr->mData < x)
        {
            isLeft = false;
            prev = curr;
            curr = curr->mRight;
        }
        else
        {
            isLeft = true;
            prev = curr;
            curr = curr->mLeft;
        }
    }

    if (curr == nullptr)
    {
        return false;
    }

    if (curr->mLeft == nullptr && curr->mRight == nullptr)
    {
        eraseLeaf(curr, prev, isLeft);
        return true;
    }
    else if (curr->mLeft != nullptr ^ curr->mRight != nullptr) // exclusive or
    {
        eraseNodeWithOneChild(curr, prev, isLeft);
        return true;
    }
    else
    {
        eraseNodeWithTwoChildren(curr);
        return true;
    }

    return false;
}

void BSTreeInt::eraseLeaf(Node *curr, Node *prev, bool isLeft)
{
    if (prev == nullptr)
    {
        root = nullptr;
    }
    else if (isLeft)
    {
        prev->mLeft = nullptr;
    }
    else
    {
        prev->mRight = nullptr;
    }
    --sz;
    delete curr;
}

void BSTreeInt::eraseNodeWithOneChild(Node *curr, Node *prev, bool isLeft)
{
    // bug (monday): I forgot about the special case when curr == root
    if (curr == root)
    {
        root = root->mLeft != nullptr ? root->mLeft : root->mRight;
    }
    else
    {
        Node *p = curr->mLeft != nullptr ? curr->mLeft : curr->mRight;

        if (isLeft)
        {
            prev->mLeft = p;
        }
        else
        {
            prev->mRight = p;
        }
    }

    --sz;
    delete curr;
}

void BSTreeInt::eraseNodeWithTwoChildren(Node *curr)
{
    bool isLeft = true;
    Node *prev = curr;
    Node *newCurr = curr->mLeft;
    while (newCurr->mRight != nullptr)
    {
        isLeft = false;
        prev = newCurr;
        newCurr = newCurr->mRight;
    }

    curr->mData = newCurr->mData;

    if (newCurr->mLeft == nullptr && newCurr->mRight == nullptr)
    {
        eraseLeaf(newCurr, prev, isLeft);
    }
    else
    {
        eraseNodeWithOneChild(newCurr, prev, isLeft);
    }
}
/**
 * => P1384 高级打字机
 * 
 * -> https://www.luogu.com.cn/problem/P1383
 * 
 * @b Persistent--Segment-tree
*/

#include <bits/stdc++.h>

using llong  = long long int;
using ullong = unsigned long long int;

template<typename _ValueType>
class SegmentTree
{
public:
    using value_type = _ValueType;

    explicit SegmentTree(std::size_t __n)
        : n(__n), root(1), tree(__n * 20) { }

    inline void push_up(int p)
    {
        tree[p].size = tree[tree[p].ls].size + tree[tree[p].rs].size;
    }

    void insert(value_type value)
    {
        std::function<void(int, int&, int, int)> insert_func = [&](int prev, int& ct, int l, int r) -> void
        {
            ct = ++pos;
            tree[ct] = tree[prev];
            
            if (l == r)
            {
                tree[ct].size = 1;
                tree[ct].value = value;
                return;
            }

            int mid = l + r >> 1;
            if (tree[tree[ct].ls].size == mid - l + 1)
                insert_func(tree[prev].rs, tree[ct].rs, mid + 1, r);
            else
                insert_func(tree[prev].ls, tree[ct].ls, l, mid);
            
            push_up(ct);
        };
        root.push_back(0);
        return insert_func(root[root.size() - 2], root[root.size() - 1], 1, n);
    }

    void undo(std::size_t i)
    {
        root.push_back(root[root.size() - i - 1]);
    }

    value_type at(std::size_t x) const noexcept
    {
        std::function<value_type(int, int, int, int)> at_func = [&](int p, int l, int r, int i) -> value_type
        {
            if (l == r) return tree[p].value;

            int mid = l + r >> 1;

            if (i <= tree[tree[p].ls].size)
                return at_func(tree[p].ls, l, mid, i);
            else
                return at_func(tree[p].rs, mid + 1, r, i - tree[tree[p].ls].size);
        };
        return at_func(root.back(), 1, n, x);
    }
private:
    struct node
    {
        int ls, rs;
        value_type value;

        std::size_t size;
    };

    std::size_t n;
    std::vector<int> root;
    std::vector<node> tree;

    std::size_t pos = 0;
};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    SegmentTree<char> tree(n);

    while (n--)
    {
        char opt, c;
        int x;
        std::cin >> opt;
        switch (opt)
        {
            case 'T':
            {
                std::cin >> c;
                tree.insert(c);
                break;
            }

            case 'U':
            {
                std::cin >> x;
                tree.undo(x);
                break;
            }

            case 'Q':
            {
                std::cin >> x;
                std::cout << tree.at(x) << '\n';
                break;
            }
        }
    }

    return 0;
}
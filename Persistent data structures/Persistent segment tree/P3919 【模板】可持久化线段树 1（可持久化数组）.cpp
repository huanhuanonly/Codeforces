/**
 * => P3919 【模板】可持久化线段树 1（可持久化数组） ( @c 提高+/省选− )
 * 
 * -> https://www.luogu.com.cn/problem/P3919
 * 
 * Submissions ~> https://www.luogu.com.cn/record/143512449 By huanhuanonly
 * 
 * @b Persistent-segment-tree
 * 
 * ----January 20, 2024 [14h:47m:39s]----
*/

#include <bits/stdc++.h>

using uint    = unsigned int;
using llong   = long long int;
using ullong  = unsigned long long int;
using ldouble = long double;

class SegmentTree 
{
public:
    std::vector<int> root;

    struct node
    {
        int ls, rs;
        int pos;
        int value;
    };

    std::vector<node> tree;
    std::vector<int>  init;

    explicit SegmentTree(int n)
        : root(1), tree(1), init(n + 1)
    {
        tree.reserve(n + 1);
    }

    int push_node()
    {
        tree.push_back(node());
        return tree.size() - 1;
    }

    void build(int& p, int l, int r)
    {
        if (l == r) return;

        p = push_node();

        int mid = l + r >> 1;

        tree[p].pos = mid;
        tree[p].value = init[mid];
        
        build(tree[p].ls, l, mid);
        build(tree[p].rs, mid + 1, r);

        return;
    }

    void change(int last, int& cur, int pos, int value)
    {
        cur = push_node();
        tree[cur] = tree[last];

        if (tree[cur].pos == pos)
        {
            tree[cur].value = value;
            return;
        }

        if (pos <= tree[cur].pos)
            change(tree[last].ls, tree[cur].ls, pos, value);
        else
            change(tree[last].rs, tree[cur].rs, pos, value);
    }

    int query(int cur, int pos)
    {
        if (tree[cur].pos == pos)
            return tree[cur].value;

        if (pos <= tree[cur].pos)
            return query(tree[cur].ls, pos);
        else
            return query(tree[cur].rs, pos);
    }
};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    SegmentTree tree(n);
    for (int i = 1; i <= n; ++i) std::cin >> tree.init[i];

    tree.build(tree.root.back(), 1, n + 1);

    tree.tree.reserve(static_cast<std::size_t>(7e7));

    int ver, opt, loc, value;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> ver >> opt >> loc;

        if (opt == 1)
        {
            std::cin >> value;

            tree.root.push_back(0);

            // if (int size = tree.tree.size() + std::log2(n) + 1; size > tree.tree.capacity())
            //     tree.tree.reserve(size);
                
            tree.change(tree.root[ver], tree.root.back(), loc, value);
        }
        else
        {
            tree.root.push_back(tree.root[ver]);
            std::cout << tree.query(tree.root.back(), loc) << '\n';
        }
    }

    return 0;
}
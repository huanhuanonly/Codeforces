/**
 * => P1801 黑匣子
 * 
 * -> https://www.luogu.com.cn/problem/P1801
 * 
 * @b FHQ-Treap
 * 
 * @from: https://www.luogu.com.cn/training/147262#problems
*/

#include <bits/stdc++.h>

using uint    = unsigned int;
using llong   = long long int;
using ullong  = unsigned long long int;
using ldouble = long double;

class Treap
{
public:

    using value_type = int;

    struct node
    {
        int ls, rs;
        value_type key, value;

        int size;
    };

    std::vector<node> tree;

    // Random number generator
    std::mt19937 rng;

    int root = 0;

    Treap() : tree(1) { }

    int push_node(value_type value)
    {
        tree.push_back({});
        
        tree.back().key = rng();
        tree.back().value = value;
        tree.back().size = 1;

        return tree.size() - 1;
    }

    void push_up(int u)
    {
        tree[u].size = tree[tree[u].ls].size + tree[tree[u].rs].size + 1;
    }

    void split(int u, value_type value, int& rx, int& ry)
    {
        if (u == 0)
        {
            rx = ry = 0;
            return;
        }

        if (tree[u].value > value)
        {
            ry = u;
            split(tree[u].ls, value, rx, tree[u].ls);
        }
        else
        {
            rx = u;
            split(tree[u].rs, value, tree[u].rs, ry);
        }

        push_up(u);
    }

    int merge(int u, int v)
    {
        if (u == 0 or v == 0)
            return u + v;
        
        if (tree[u].key > tree[v].key)
        {
            tree[u].rs = merge(tree[u].rs, v);
            push_up(u);
            return u;
        }
        else
        {
            tree[v].ls = merge(u, tree[v].ls);
            push_up(v);
            return v;
        }
    }

    int size() const
    {
        return tree[root].size;
    }

    void insert(value_type value)
    {
        int x, y;
        split(root, value, x, y);

        x = merge(x, push_node(value));
        root = merge(x, y);
    }

    void erase(value_type value)
    {
        int x, y, z;
        split(root, value, x, y);
        split(x, value - 1, x, z);

        root = merge(merge(x, merge(tree[z].ls, tree[z].rs)), y);
    }

    int rank_of(value_type value)
    {
        int x, y;
        split(root, value - 1, x, y);

        int res = tree[x].size + 1;
        root = merge(x, y);

        return res;
    }

    std::optional<value_type> at(int x)
    {
        std::function<std::optional<value_type>(int, int)> dfs = [&](int u, int k) -> std::optional<value_type>
        {
            if (u == 0)
                return std::nullopt;

            if (k <= tree[tree[u].ls].size)
                return dfs(tree[u].ls, k);
            else if (k == tree[tree[u].ls].size + 1)
                return tree[u].value;
            else
                return dfs(tree[u].rs, k - tree[tree[u].ls].size - 1);
        };

        return dfs(root, x);
    }

    std::optional<value_type> prev(value_type value)
    {
        int x, y;
        split(root, value - 1, x, y);

        int size = tree[x].size;
        root = merge(x, y);

        return at(size);
    }

    std::optional<value_type> next(value_type value)
    {
        int x, y;
        split(root, value, x, y);

        int size = tree[x].size + 1;
        root = merge(x, y);

        return at(size);
    }

    bool exist(value_type value)
    {
        int x, y;
        split(root, value, x, y);
        
        bool res = false;

        for (int u = x; u; u = tree[u].rs)
            if (tree[u].value == value)
                res = true;

        root = merge(x, y);

        return res;
    }
};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
    ::freopen("Input.txt", "r", stdin);
    ::freopen("Output.txt", "w", stdout);
#endif

    Treap tree;

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m + 1, INT_MAX);

    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    for (int i = 0; i < m; ++i)
        std::cin >> b[i];

    int pos = 0;
    int bi  = 0;

    for (int i = 0; i < n; ++i)
    {
        tree.insert(a[i]);

        while (b[bi] == i + 1)
        {
            std::cout << *tree.at(++pos) << '\n';
            ++bi;
        }
    }

    return 0;
}
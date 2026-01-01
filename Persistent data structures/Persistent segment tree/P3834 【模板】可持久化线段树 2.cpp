/**
 * => P3834 【模板】可持久化线段树 2 ( @c 提高+/省选− )
 * 
 * -> https://www.luogu.com.cn/problem/P3834
 * 
 * Submissions ~> https://www.luogu.com.cn/record/145095462 By huanhuanonly
 * 
 * @b Persistent-segment-tree
 * 
 * ----January 29, 2024 [22h:50m:37s]----
*/

#include <bits/stdc++.h>

using uint = unsigned int;
using llong = long long int;
using ullong = unsigned long long int;
using ldouble = long double;

template<typename _ValueType>
class PersistentSegmentTree
{
public:

    using value_type = _ValueType;

    struct node
    {
        int ls, rs;
        int size;
        value_type value;
    };

    std::vector<node> tree;
    std::vector<int> root;

    explicit PersistentSegmentTree(std::size_t n)
        : tree(1), root(1) { tree.reserve(n << 5); }

    int push_node()
    {
        tree.push_back(node());
        return tree.size() - 1;
    }

    int& push_root()
    {
        root.push_back(root.back());
        return root.back();
    }

    void insert(int last, int& ct, int l, int r, int pos, value_type value)
    {
        ct = push_node();

        tree[ct] = tree[last];

        ++tree[ct].size;

        if (l == r)
        {
            tree[ct].value = value;
            return;
        }

        int mid = l + r >> 1;
        if (pos <= mid)
            insert(tree[last].ls, tree[ct].ls, l, mid, pos, value);
        else
            insert(tree[last].rs, tree[ct].rs, mid + 1, r, pos, value);

        return;
    }

    value_type query(int last, int& ct, int l, int r, int k)
    {
        if (l == r) return tree[ct].value;

        int mid = l + r >> 1;
        if (k <= tree[tree[ct].ls].size - tree[tree[last].ls].size)
            return query(tree[last].ls, tree[ct].ls, l, mid, k);
        else
            return query(tree[last].rs, tree[ct].rs, mid + 1, r, k - (tree[tree[ct].ls].size - tree[tree[last].ls].size));
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

    int n, m;
    std::cin >> n >> m;

    std::vector<int> v(n + 1);
    std::map<int, int> mp;

    for (int i = 1; i <= n; ++i) std::cin >> v[i], mp[v[i]] = 0;
    
    { int i = 1; for (auto it = mp.begin(); it != mp.end(); ++it, ++i) it->second = i; }

    PersistentSegmentTree<int> tree(n);
    for (int i = 1; i <= n; ++i)
        tree.insert(tree.root.back(), tree.push_root(), 1, mp.size(), mp[v[i]], v[i]);

    while (m--)
    {
        int l, r, k;
        std::cin >> l >> r >> k;

        std::cout << tree.query(tree.root[l - 1], tree.root[r], 1, mp.size(), k) << '\n';
    }

    return 0;
}
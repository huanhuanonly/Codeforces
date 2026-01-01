/**
 * AIM Tech Round 3 (Div. 1)
 * 
 * => C. Centroids ( @c 2300 )
 * 
 * -> https://codeforces.com/contest/708/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/708/submission/344948624 By huanhuanonly
 * 
 * @b Dfs to find @a Tree-centroid
 * 
 * ----October 21, 2025 [08h:51m:11s]----
*/

#include <bits/stdc++.h>

using int8 = signed char;
using int16 = short;
using int32 = int;
using int64 = long long;

using uint8 = unsigned char;
using uint16 = unsigned short;
using uint32 = unsigned int;
using uint64 = unsigned long long;

#ifdef __GNUC__
using int128 = __int128;
using uint128 = unsigned __int128;
#endif

using real32 = float;
using real64 = double;
using real128 = long double;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    int root = 0;

    auto find_centroid = [&](const auto& self, int u, int fa) -> int
    {
        int size = 1;
        int weight = 0;

        for (int i : e[u] | std::views::filter([fa](int i) -> bool { return i != fa; }))
        {
            const int res = self(self, i, u);

            size += res;
            weight = std::max(weight, res);
        }

        weight = std::max(weight, n - size);

        if (weight <= n / 2)
        {
            root = u;
        }

        return size;
    };

    find_centroid(find_centroid, 1, 0);

    struct node
    {
        int parent;
        int size;
    };

    std::vector<node> tree(n + 1);
    std::multiset<int> set;

    auto build_tree = [&](const auto& self, int u) -> void
    {
        tree[u].size = 1;

        for (int i : e[u] | std::views::filter([&](int i) -> bool { return i != tree[u].parent; }))
        {
            tree[i].parent = u;

            self(self, i);

            tree[u].size += tree[i].size;
        }

        set.insert(tree[u].size);
    };

    build_tree(build_tree, root);

    std::stack<std::multiset<int>::node_type> temp;

    auto remove_subtree = [&](const auto& self, int u) -> void
    {
        temp.push(set.extract(tree[u].size));

        for (int i : e[u] | std::views::filter([&](int i) -> bool { return i != tree[u].parent; }))
        {
            self(self, i);
        }
    };

    std::vector<bool> ans(n + 1);
    ans[root] = true;

    auto dfs = [&](const auto& self, int u) -> void
    {
        const int s = n - tree[u].size;

        set.insert(s);

        ans[u] = *set.lower_bound(s - n / 2) <= n / 2;

        for (int i : e[u] | std::views::filter([&](int i) -> bool { return i != tree[u].parent; }))
        {
            self(self, i);
        }

        set.extract(s);
    };

    for (int u : e[root])
    {
        remove_subtree(remove_subtree, u);

        dfs(dfs, u);

        for (; not temp.empty(); set.insert(std::move(temp.top())), temp.pop());
    }

    for (int i = 1; i <= n; ++i)
    {
        std::cout << ans[i] << ' ';
    }

    return 0;
}
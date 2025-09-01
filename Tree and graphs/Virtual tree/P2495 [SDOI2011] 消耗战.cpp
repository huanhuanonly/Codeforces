/**
 * => P2495 [SDOI2011] 消耗战 ( @c 省选/NOI- )
 * 
 * -> https://www.luogu.com.cn/problem/P2495
 * 
 * Submissions ~> https://www.luogu.com.cn/record/232405524 By huanhuanonly
 * 
 * @b Virtual-tree ( @a secondary-sorting )
 * @b Lowest-common-ancestor ( @a binary-lifting )
 * @b DP on @a Trees
 * 
 * ----August 21, 2025 [20h:09m:37s]----
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

    struct edge
    {
        uint64 to, w;
    };

    std::vector<std::vector<edge>> e(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        uint64 u, v, w;
        std::cin >> u >> v >> w;

        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    struct node
    {
        int depth;
        std::array<int, 20> up;
        uint64 min;
    };

    std::vector<node> tree(n + 1);
    std::vector<int> dfn(n + 1);

    auto compare = [&dfn](int lv, int rv) -> bool
    {
        return dfn[lv] < dfn[rv];
    };

    auto build = [&, cnt = 0](auto& self, int u, int fa, int depth, uint64 min) mutable -> void
    {
        tree[u].depth = depth;
        tree[u].up[0] = fa;
        tree[u].min = min;

        dfn[u] = ++cnt;

        for (const auto& [i, w] : e[u] | std::views::filter([fa](const auto& i) -> bool { return i.to != fa; }))
        {
            self(self, i, u, depth + 1, std::min(min, w));
        }
    };

    build(build, 1, 0, 1, std::numeric_limits<uint64>::max());

    for (int lay = 1; lay < 20; ++lay)
    {
        for (int i = 1; i <= n; ++i)
        {
            tree[i].up[lay] = tree[tree[i].up[lay - 1]].up[lay - 1];
        }
    }

    auto lca = [&](int u, int v) -> int
    {
        if (tree[u].depth < tree[v].depth)
        {
            std::swap(u, v);
        }

        for (int x = tree[u].depth - tree[v].depth, i = 20 - 1; i >= 0; --i)
        {
            if (x & (1 << i))
            {
                u = tree[u].up[i];
            }
        }

        if (u == v)
        {
            return u;
        }

        for (int i = 20 - 1; i >= 0; --i)
        {
            if (tree[u].up[i] != tree[v].up[i])
            {
                u = tree[u].up[i];
                v = tree[v].up[i];
            }
        }

        return tree[u].up[0];
    };

    std::vector<std::vector<int>> ve(n + 1);

    int q;
    std::cin >> q;

    while (q--)
    {
        int m;
        std::cin >> m;

        std::vector<int> set(m + 1, 1);
        std::vector<bool> contains(n + 1);

        for (int i = 1; i <= m; ++i)
        {
            std::cin >> set[i];
            contains[set[i]] = true;
        }

        std::ranges::sort(set, compare);

        for (int i = 1; i <= m; ++i)
        {
            set.push_back(lca(set[i - 1], set[i]));
        }

        std::ranges::sort(set, compare);
        set.erase(std::ranges::unique(set).begin(), set.end());

        for (int i = 1; i < set.size(); ++i)
        {
            ve[lca(set[i - 1], set[i])].push_back(set[i]);
        }

        auto dfs = [&](const auto& self, int u) -> uint64
        {
            if (ve[u].empty() or contains[u])
            {
                return tree[u].min;
            }

            uint64 sum = 0;

            for (int i : ve[u])
            {
                sum += self(self, i);
            }

            return std::min(tree[u].min, sum);
        };

        std::cout << dfs(dfs, 1) << '\n';

        for (int i : set)
        {
            ve[i].clear();
        }
    }

    return 0;
}
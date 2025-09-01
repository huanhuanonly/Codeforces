/**
 * Atto Round 1 (Codeforces Round 1041, Div. 1 + Div. 2)
 * 
 * => E. Ancient Tree ( @c 2100 )
 * 
 * -> https://codeforces.com/contest/2127/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2127/submission/334995247 By huanhuanonly
 * 
 * @b Virtual-tree ( @a secondary-sorting )
 * @b Lowest-common-ancestor ( @a binary-lifting )
 * @b Classification-discussion
 * 
 * ----August 22, 2025 [15h:18m:08s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, k;
        std::cin >> n >> k;

        struct node
        {
            int depth;
            std::array<int, 20> up;

            int w;
            int color;
        };

        std::vector<node> tree(n + 1);
        std::vector<int> dfn(n + 1);

        std::vector<std::vector<int>> sets(k + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> tree[i].w;
        }

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> tree[i].color;
            sets[tree[i].color].push_back(i);
        }

        std::vector<std::vector<int>> e(n + 1);

        for (int i =  0; i < n - 1; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            e[u].push_back(v);
            e[v].push_back(u);
        }

        auto build = [&, cnt = 0](auto& self, int u, int fa, int depth) mutable -> void
        {
            tree[u].depth = depth;
            tree[u].up[0] = fa;

            dfn[u] = ++cnt;

            for (int i : e[u] | std::views::filter([fa](int i) -> bool { return i != fa; }))
            {
                self(self, i, u, depth + 1);
            }
        };

        build(build, 1, 0, 1);

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

            for (int i = 20 - 1, x = tree[u].depth - tree[v].depth; i >= 0; --i)
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

        std::vector<int> cnt(n + 1), last(n + 1);

        for (auto& set : sets | std::views::drop(1))
        {
            std::ranges::sort(set, [&](int lv, int rv) -> bool {
                return dfn[lv] < dfn[rv];
            });
            
            for (int i = 1, size = set.size(); i < size; ++i)
            {
                set.push_back(lca(set[i - 1], set[i]));
            }

            std::ranges::sort(set, [&](int lv, int rv) -> bool {
                return dfn[lv] < dfn[rv];
            });

            set.erase(std::ranges::unique(set).begin(), set.end());

            ++last[0];

            for (int i : set)
            {
                ++cnt[i];
                last[i] = last[0];
            }
        }

        uint64 sum = 0;

        tree[0].color = 1;

        auto dfs = [&](const auto& self, int u) -> void
        {
            if (cnt[u] == 0)
            {
                tree[u].color = tree[tree[u].up[0]].color;
            }
            else if (cnt[u] == 1)
            {
                if (tree[u].color == 0)
                {
                    tree[u].color = last[u];
                }
            }
            else
            {
                sum += tree[u].w;
                
                if (tree[u].color == 0)
                {
                    tree[u].color = tree[tree[u].up[0]].color;
                }
            }

            for (int i : e[u])
            {
                if (i != tree[u].up[0])
                {
                    self(self, i);
                }
            }
        };

        dfs(dfs, 1);

        std::cout << sum << '\n';

        for (int i = 1; i <= n; ++i)
        {
            std::cout << tree[i].color << " \n"[i == n];
        }
    }

    return 0;
}
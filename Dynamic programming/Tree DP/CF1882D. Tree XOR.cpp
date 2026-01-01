/**
 * Codeforces Round 899 (Div. 2)
 * 
 * => D. Tree XOR ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/1882/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/1882/submission/347819651 By huanhuanonly
 * 
 * @b Tree-DP and @b Bitwise-XOR
 * 
 * ----November 07, 2025 [11h:36m:03s]----
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
        int n;
        std::cin >> n;

        struct node
        {
            uint64 value;
            uint64 size;

            uint64 sum;
        };

        std::vector<node> tree(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> tree[i].value;
        }

        tree[0].value = tree[1].value;

        std::vector<std::vector<int>> e(n + 1);

        for (int i = 1; i <= n - 1; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            e[u].push_back(v);
            e[v].push_back(u);
        }

        auto build = [&](const auto& self, int u, int fa) -> void
        {
            tree[u].size = 1;

            for (int i : e[u] | std::views::filter([fa](int i) -> bool { return i != fa; }))
            {
                self(self, i, u);

                tree[u].size += tree[i].size;
                tree[u].sum += tree[i].sum;
            }

            tree[u].sum += (tree[fa].value ^ tree[u].value) * tree[u].size;
        };

        build(build, 1, 0);

        std::vector<uint64> ans(n + 1);

        auto dfs = [&](const auto& self, int u, int fa, uint64 last_sum) -> void
        {
            last_sum += (tree[fa].value ^ tree[u].value) * (n - tree[u].size);
            
            ans[u] = last_sum + tree[u].sum - (tree[fa].value ^ tree[u].value) * tree[u].size;

            last_sum += tree[u].sum - (tree[fa].value ^ tree[u].value) * tree[u].size;

            for (int i : e[u] | std::views::filter([fa](int i) -> bool { return i != fa; }))
            {
                self(self, i, u, last_sum - tree[i].sum);
            }
        };
        
        dfs(dfs, 1, 0, 0);

        for (int i = 1; i <= n; ++i)
        {
            std::cout << ans[i] << " \n"[i == n];
        }
    }

    return 0;
}
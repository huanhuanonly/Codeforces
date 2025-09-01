/**
 * Codeforces Round 1037 (Div. 3)
 * 
 * => F. 1-1-1, Free Tree! ( @c 2000 )
 * 
 * -> https://codeforces.com/contest/2126/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/2126/submission/329486721 By huanhuanonly
 * 
 * @b Dfs
 * 
 * ----July 18, 2025 [00h:10m:33s]----
*/

/// @brief This is an @c interesting problem!

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
        int n, q;
        std::cin >> n >> q;

        struct node
        {
            int fa, faw, c;
            std::map<int, uint64> sums;
        };

        std::vector<node> tree(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> tree[i].c;
        }

        struct edge
        {
            int point, w;
        };

        std::vector<std::vector<edge>> e(n + 1);

        for (int i = 0; i < n - 1; ++i)
        {
            int u, v, w;
            std::cin >> u >> v >> w;

            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }

        uint64 sum = 0;

        auto dfs = [&](const auto& self, int u, int fa) -> void
        {
            for (const auto& [i, w] : e[u])
            {
                if (i == fa)
                {
                    continue;
                }

                if (tree[u].c != tree[i].c)
                {
                    sum += w;
                }
                
                tree[i].fa  = u;
                tree[i].faw = w;

                tree[u].sums[tree[i].c] += w;
                self(self, i, u);
            }
        };

        dfs(dfs, 1, 0);

        while (q--)
        {
            int u, x;
            std::cin >> u >> x;

            sum = sum - tree[u].sums[x] + tree[u].sums[tree[u].c];
            
            if (u != 1 and tree[u].c != tree[tree[u].fa].c)
            {
                sum -= tree[u].faw;
            }

            if (u != 1)
            {
                tree[tree[u].fa].sums[tree[u].c] -= tree[u].faw;
            }
            
            tree[u].c = x;
            
            if (u != 1 and tree[u].c != tree[tree[u].fa].c)
            {
                sum += tree[u].faw;
            }
            
            if (u != 1)
            {
                tree[tree[u].fa].sums[tree[u].c] += tree[u].faw;
            }

            std::cout << sum << '\n';
        }
    }

    return 0;
}
/**
 * Codeforces Round 1062 (Div. 4)
 * 
 * => F. Tree, TREE!!! ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/2167/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/2167/submission/346326513 By huanhuanonly
 * 
 * @b Tree-DP
 * 
 * ----October 29, 2025 [00h:49m:21s]----
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
        int64 n, k;
        std::cin >> n >> k;

        std::vector<std::vector<int>> e(n + 1);

        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            e[u].push_back(v);
            e[v].push_back(u);
        }

        std::vector<int64> sizes(n + 1);
        std::vector<int64> count(n + 1);

        auto build = [&](const auto& self, int u, int fa) -> void
        {
            sizes[u] = 1;

            for (int i : e[u])
            {
                if (i == fa)
                {
                    continue;
                }

                self(self, i, u);

                sizes[u] += sizes[i];
                count[u] += count[i];
            }

            if (sizes[u] >= k)
            {
                ++count[u];
            }
        };

        build(build, 1, 0);

        int64 ans = 0;

        auto dfs = [&](const auto& self, int u, int fa, int64 d) -> void
        {
            ans += count[u] + d + (sizes[u] < k);

            for (int i : e[u])
            {
                if (i == fa)
                {
                    continue;
                }

                int64 add = 0;

                if (sizes[u] >= k)
                {
                    add -= (n - sizes[i] < k);
                }
                else
                {
                    add += (n - sizes[i] >= k);
                }

                self(self, i, u, d + count[u] - count[i] + add);
            }
        };

        dfs(dfs, 1, 0, 0);

        std::cout << ans << '\n';
    }

    return 0;
}
/**
 * Codeforces Round 1047 (Div. 3)
 * 
 * => G. Cry Me a River ( @c 2200 )
 * 
 * -> https://codeforces.com/contest/2137/problem/G
 * 
 * Submissions ~> https://codeforces.com/contest/2137/submission/338045415 By huanhuanonly
 * 
 * @b DP on @a The-reversed-DAG
 * 
 * ----September 11, 2025 [16h:24m:24s]----
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
        int n, m, q;
        std::cin >> n >> m >> q;

        std::vector<std::vector<int>> e(n + 1);

        std::vector<int> d(n + 1);

        for (int i = 0; i < m; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            e[v].push_back(u);
            ++d[u];
        }

        std::vector dp(n + 1, std::pair{1, false});

        for (int i = 1; i <= n; ++i)
        {
            dp[i].first = std::max(d[i], 1);
        }

        auto dfs_first = [&](const auto& df, const auto& ds, int u) -> void
        {
            for (int i : e[u])
            {
                if (not dp[i].second)
                {
                    dp[i].second = true;
                    ds(df, ds, i);
                }
            }
        };

        auto dfs_second = [&](const auto& df, const auto& ds, int u) -> void
        {
            for (int i : e[u])
            {
                if (--dp[i].first == 0)
                {
                    df(df, ds, i);
                }
            }
        };

        while (q--)
        {
            int opt, u;
            std::cin >> opt >> u;

            if (opt == 1)
            {
                dp[u].first = 0;
                dfs_first(dfs_first, dfs_second, u);

                if (not dp[u].second)
                {
                    dp[u].second = true;
                    dfs_second(dfs_first, dfs_second, u);
                }
            }
            else
            {
                if (dp[u].first > 0)
                {
                    std::cout << "YES\n";
                }
                else
                {
                    std::cout << "NO\n";
                }
            }
        }
    }

    return 0;
}
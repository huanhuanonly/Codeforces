/**
 * The 2025 ICPC Asia East Continent Online Contest (I)
 * 
 * => M. Teleporter
 * 
 * -> https://qoj.ac/contest/2513/problem/14313
 * 
 * Submissions ~> https://qoj.ac/submission/2292181 By huanhuanonly
 * 
 * @b Tree-DP
 * 
 * ----April 28, 2026 [09h:47m:06s]----
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

#if defined(__SIZEOF_INT128__)
using int128 = __int128;
using uint128 = unsigned __int128;
#endif

using real32 = float;
using real64 = double;

#if defined(__SIZEOF_FLOAT80__)
using real80 = __float80;
#endif

#if defined(__SIZEOF_FLOAT128__)
using real128 = __float128;
#endif

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> e(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, w;
        std::cin >> u >> v >> w;

        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }

    std::vector<std::pair<int, int>> qe(m);

    for (int i = 0; i < m; ++i)
    {
        auto& [u, v] = qe[i];
        std::cin >> u >> v;
    }

    constexpr auto inf = std::numeric_limits<uint64>::max() / 2;

    std::vector dp(2, std::vector(n + 1, inf));
    dp[1][0] = dp[1][1] = 0;

    auto dfs = [&](const auto& self, int u, int fa) -> void
    {
        for (const auto& [v, w] : e[u])
        {
            if (v != fa)
            {
                dp[1][v] = std::min(dp[1][v], dp[1][u] + w);
                self(self, v, u);
                dp[1][u] = std::min(dp[1][u], dp[1][v] + w);
            }
        }
    };

    dfs(dfs, 1, 0);

    std::cout << *std::ranges::fold_left_first(dp[1], std::plus{}) << '\n';

    for (int i = 1; i <= n; ++i)
    {
        dp[0] = dp[1];

        for (const auto& [u, v] : qe)
        {
            const auto min = std::min(dp[0][u], dp[0][v]);

            dp[1][u] = std::min(dp[1][u], min);
            dp[1][v] = std::min(dp[1][v], min);
        }

        dfs(dfs, 1, 0);
        dfs(dfs, 1, 0);
        std::cout << *std::ranges::fold_left_first(dp[1], std::plus{}) << '\n';
    }

    return 0;
}
/**
 * VK Cup 2012 Round 1
 * 
 * => D. Distance in Tree ( @c 1800 )
 * 
 * -> https://codeforces.com/contest/161/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/161/submission/370310325 By huanhuanonly
 * 
 * @b Tree-DP
 * 
 * ----April 09, 2026 [01h:08m:32s]----
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

    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    std::vector dp(n + 1, std::vector(k + 1, uint64{}));

    uint64 ans = 0;

    auto dfs = [&](const auto& self, int u, int fa) -> void
    {
        dp[u][0] = 1;

        for (const auto& v : e[u])
        {
            if (v == fa)
            {
                continue;
            }

            self(self, v, u);

            for (int i = 1; i < k; ++i)
            {
                ans += dp[u][k - i] * dp[v][i - 1];
            }

            for (int i = 1; i <= k; ++i)
            {
                dp[u][i] += dp[v][i - 1];
            }
        }
    };

    dfs(dfs, 1, 0);

    for (int i = 1; i <= n; ++i)
    {
        ans += dp[i][k];
    }

    std::cout << ans << '\n';

    return 0;
}
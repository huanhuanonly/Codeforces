/**
 * 牛客周赛 Round 139
 *
 * => E-小红的树权值 ( @c 1300 )
 *
 * -> https://ac.nowcoder.com/acm/contest/131539/E
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83276165 By huanhuanonly
 *
 * @b Tree-DP
 *
 * ----April 14, 2026 [09h:57m:23s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
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

        std::vector dp(n + 1, std::array{0, 1});

        auto dfs = [&](const auto& self, int u, int fa) -> void
        {
            for (const auto& i : e[u])
            {
                if (i == fa)
                {
                    continue;
                }

                self(self, i, u);

                dp[u][0] += dp[i][1];
                dp[u][1] += std::min(dp[i][0], dp[i][1]);
            }
        };

        dfs(dfs, 1, 0);

        for (int i = 1; i <= n; ++i)
        {
            std::cout << std::min(dp[i][0], dp[i][1]) << " \n"[i == n];
        }
    }

    return 0;
}
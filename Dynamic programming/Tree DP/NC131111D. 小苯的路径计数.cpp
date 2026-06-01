/**
 * 牛客周赛 Round 138
 *
 * => D-小苯的路径计数 ( @c 1100 )
 *
 * -> https://ac.nowcoder.com/acm/contest/131111/D
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83152780 By huanhuanonly
 *
 * @b Tree-DP
 *
 * ----April 05, 2026 [19h:33m:51s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        std::vector<int> c(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> c[i];
        }

        std::vector<std::vector<int>> e(n + 1);

        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            e[u].push_back(v);
            e[v].push_back(u);
        }

        std::vector<uint64> dp(n + 1, 1);

        auto dfs = [&](const auto& self, int u, int fa) -> void
        {
            for (const auto& i : e[u])
            {
                if (i == fa)
                {
                    continue;
                }

                self(self, i, u);

                if (c[i] == c[u])
                {
                    dp[u] += dp[i];
                }
            }
        };

        dfs(dfs, 1, 0);

        std::cout << std::reduce(dp.begin() + 1, dp.end()) - n << '\n';
    }

    return 0;
}
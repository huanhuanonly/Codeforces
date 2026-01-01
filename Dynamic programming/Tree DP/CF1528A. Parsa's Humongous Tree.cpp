/**
 * Codeforces Round 722 (Div. 1)
 * 
 * => A. Parsa's Humongous Tree ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/1528/problem/A
 * 
 * Submissions ~> https://codeforces.com/contest/1528/submission/340323050 By huanhuanonly
 * 
 * @b Tree-DP
 * 
 * ----September 25, 2025 [17h:08m:18s]----
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

        std::vector<std::pair<int64, int64>> v(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i].first >> v[i].second;
        }

        std::vector<std::vector<int>> e(n + 1);

        for (int i = 1; i <= n - 1; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            e[u].push_back(v);
            e[v].push_back(u);
        }

        std::vector<std::array<int64, 2>> dp(n + 1);

        auto dfs = [&](const auto& self, int u, int fa) -> void
        {
            for (int i : e[u] | std::views::filter([fa](int i) -> bool { return i != fa; }))
            {
                self(self, i, u);

                dp[u][0] += std::max(dp[i][0] + std::abs(v[u].first - v[i].first), dp[i][1] + std::abs(v[u].first - v[i].second));
                dp[u][1] += std::max(dp[i][0] + std::abs(v[u].second - v[i].first), dp[i][1] + std::abs(v[u].second - v[i].second));
            }
        };

        dfs(dfs, 1, 0);

        std::cout << std::max(dp[1][0], dp[1][1]) << '\n';
    }

    return 0;
}
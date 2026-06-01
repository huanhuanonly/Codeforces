/**
 * The 2025 ICPC Asia East Continent Online Contest (I)
 * 
 * => D. Min-Max Tree
 * 
 * -> https://qoj.ac/contest/2513/problem/14304
 * 
 * Submissions ~> https://qoj.ac/submission/2212615 By huanhuanonly
 * 
 * @b Tree-DP
 * 
 * ----April 10, 2026 [00h:40m:31s]----
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

void chmax(auto& lhs, const auto& rhs)
{
    if (lhs < rhs)
    {
        lhs = rhs;
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n;
    std::cin >> n;

    std::vector<int64> w(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> w[i];
    }

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    constexpr auto inf = std::numeric_limits<int64>::max() / 2;

    std::vector dp(3, std::vector(n + 1, -inf));

    auto dfs = [&](const auto& self, int u, int fa) -> void
    {
        if (e[u].size() == 1 and e[u].front() == fa)
        {
            dp[0][u] = 0;
            dp[1][u] = -w[u];
            dp[2][u] = +w[u];
            return;
        }

        int64 sum = 0;
        std::multiset<int64, std::ranges::greater> set1, set2;

        for (const auto& i : e[u])
        {
            if (i == fa)
            {
                continue;
            }

            self(self, i, u);

            sum += dp[0][i];

            set1.insert(-dp[0][i] + dp[1][i]);
            set2.insert(-dp[0][i] + dp[2][i]);
        }

        dp[0][u] = sum;

        for (const auto& i : e[u])
        {
            if (i == fa)
            {
                continue;
            }

            chmax(dp[1][u], sum - dp[0][i] + dp[1][i]);
            chmax(dp[2][u], sum - dp[0][i] + dp[2][i]);

            chmax(dp[0][u], sum - dp[0][i] + dp[1][i] + w[u]);
            chmax(dp[0][u], sum - dp[0][i] + dp[2][i] - w[u]);

            auto nd1 = set1.extract(-dp[0][i] + dp[1][i]);
            auto nd2 = set2.extract(-dp[0][i] + dp[2][i]);

            if (not set1.empty())
            {
                chmax(dp[0][u], sum - dp[0][i] + dp[2][i] + *set1.begin());
                chmax(dp[0][u], sum - dp[0][i] + dp[1][i] + *set2.begin());
            }

            set1.insert(std::move(nd1));
            set2.insert(std::move(nd2));
        }

        chmax(dp[1][u], sum - w[u]);
        chmax(dp[2][u], sum + w[u]);
    };

    dfs(dfs, 1, 0);

    std::cout << dp[0][1] << '\n';

    return 0;
}
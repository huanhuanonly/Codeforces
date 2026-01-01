/**
 * Codeforces Round 1048 (Div. 2)
 * 
 * => E2. Maple and Tree Beauty (Hard Version) ( @c 2000 )
 * 
 * -> https://codeforces.com/contest/2139/problem/E2
 * 
 * Submissions ~> https://codeforces.com/contest/2139/submission/337951548 By huanhuanonly
 * 
 * @b Knapsack-DP ( @a 0/1-knapsack-problem-with-bitset-optimization ) and @b Trees
 * 
 * ----September 10, 2025 [20h:45m:17s]----
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
        int n, k;
        std::cin >> n >> k;

        std::vector<std::vector<int>> e(n + 1);

        for (int i = 2, fa; i <= n; ++i)
        {
            std::cin >> fa;
            e[fa].push_back(i);
        }

        std::vector<int> sizes(n + 1);
        int mindegree = n + 1;

        auto dfs = [&](const auto& self, int u, int d) -> void
        {
            ++sizes[d];

            for (int i : e[u])
            {
                self(self, i, d + 1);
            }

            if (e[u].empty())
            {
                mindegree = std::min(mindegree, d);
            }
        };

        dfs(dfs, 1, 1);

        const int remain = std::reduce(sizes.begin() + 1 + mindegree, sizes.end());

        constexpr int maxk = 2e5 + 1;
        using bset = std::bitset<maxk>;

        std::vector dp(2, bset());
        dp[0].set(0);

        for (int i = 1; i <= mindegree; ++i)
        {
            dp[i & 1] = dp[i - 1 & 1] | (dp[i - 1 & 1] << sizes[i]);
        }

        int pos = dp[mindegree & 1]._Find_first();
        for (int i = dp[mindegree & 1]._Find_next(pos); i <= k; pos = std::exchange(i, dp[mindegree & 1]._Find_next(i)));

        if (k - pos <= remain)
        {
            std::cout << mindegree << '\n';
        }
        else
        {
            std::cout << mindegree - 1 << '\n';
        }
    }

    return 0;
}
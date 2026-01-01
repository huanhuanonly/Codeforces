/**
 * Codeforces Round 1049 (Div. 2)
 * 
 * => E1. Prime Gaming (Easy Version) ( @c 2200 )
 * 
 * -> https://codeforces.com/contest/2140/problem/E1
 * 
 * Submissions ~> https://codeforces.com/contest/2140/submission/338869709 By huanhuanonly
 * 
 * @b Bitmask-DP and @b Combinatorics
 * 
 * ----September 16, 2025 [14h:26m:07s]----
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
        int n, m;
        std::cin >> n >> m;

        int k;
        std::cin >> k;

        std::vector<uint32> c(k);

        for (int i = 0; i < k; ++i)
        {
            std::cin >> c[i];
        }

        if (m == 1)
        {
            std::cout << 1 << '\n';
            continue;
        }

        constexpr uint64 mod = 1e9 + 7;

        std::vector dp(2, std::vector(n + 1, std::vector(1U << n, uint64{})));

        dp[0][1][0] = dp[1][1][0] = 1;
        dp[0][1][1] = dp[1][1][1] = 2;

        for (uint32 i = 2; i <= n; ++i)
        {
            for (uint32 s = 0; s < (1U << i); ++s)
            {
                dp[0][i][s] = std::numeric_limits<uint64>::min();
                dp[1][i][s] = std::numeric_limits<uint64>::max();

                for (uint32 r : c | std::views::take_while([i](uint32 r) -> bool { return r <= i; }))
                {
                    const uint32 mask = (1U << r - 1) - 1;
                    const uint32 next = (s >> 1) & ~mask | (s & mask);

                    dp[0][i][s] = std::max(dp[0][i][s], dp[1][i - 1][next]);
                    dp[1][i][s] = std::min(dp[1][i][s], dp[0][i - 1][next]);
                }
            }
        }

        std::cout << std::reduce(dp[0][n].begin(), dp[0][n].end()) << '\n';
    }

    return 0;
}
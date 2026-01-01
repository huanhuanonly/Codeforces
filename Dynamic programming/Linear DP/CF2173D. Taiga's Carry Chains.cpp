/**
 * Codeforces Round 1068 (Div. 2)
 * 
 * => D. Taiga's Carry Chains ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/2173/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2173/submission/352488646 By huanhuanonly
 * 
 * @b Linear-DP and @b Bitwise
 * 
 * ----December 08, 2025 [14h:36m:08s]----
*/

/// @brief This is an @c interesting problem!

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
        uint32 n, k;
        std::cin >> n >> k;

        constexpr auto bitcnt = static_cast<uint32>(30);

        std::vector dp(bitcnt, std::vector(bitcnt + 1, std::array<uint32, 2>{}));

        static auto $ = [](uint32 x, uint32 i) -> uint32
        {
            return std::popcount(x ^ x + (1U << i)) - 1;
        };

        static auto chmax = [](uint32& lhs, uint32 rhs) -> void
        {
            if (lhs < rhs)
            {
                lhs = rhs;
            }
        };

        for (uint32 i = 0; i < bitcnt; ++i)
        {
            for (uint32 j = 1; j <= i + 1; ++j)
            {
                if (j == 1)
                {
                    const auto t = $(n, i);
                    chmax(dp[i][j][!!t], t);
                }
                else
                {
                    for (uint32 k = 0; k < i; ++k)
                    {
                        if (n & (1U << k))
                        {
                            const auto t = $(n + (1U << k), i);
                            chmax(dp[i][j][!!t], dp[k][j - 1][1] + t);
                        }
                        else if (dp[k][j - 1][1])
                        {
                            const auto t = $(n + (1U << k + 1), i);
                            chmax(dp[i][j][!!t], dp[k][j - 1][1] + t);
                        }
                    }
                }
            }
        }

        uint32 ans = 0;

        for (uint32 i = 0; i < bitcnt; ++i)
        {
            for (uint32 j = 1; j <= std::min(bitcnt, k); ++j)
            {
                chmax(ans, dp[i][j][1] + k - j);
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}
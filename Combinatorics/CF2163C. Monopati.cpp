/**
 * Codeforces Round 1063 (Div. 2)
 * 
 * => C. Monopati ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/2163/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2163/submission/348408492 By huanhuanonly
 * 
 * @b Combinatorics and @b Prefix-sum
 * 
 * ----November 11, 2025 [10h:39m:38s]----
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

constexpr void chmin(auto& a, const auto& b) noexcept
{ b < a ? void(a = b) : void(); }

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
        int64 n;
        std::cin >> n;

        std::vector v(2, std::vector(n, int64{}));

        for (int64 i = 0; i < 2; ++i)
        {
            for (int64 j = 0; j < n; ++j)
            {
                std::cin >> v[i][j];
            }
        }

        auto premax = v[0];
        auto premin = v[0];
        
        auto sufmax = v[1];
        auto sufmin = v[1];

        std::partial_sum(premax.begin(), premax.end(), premax.begin(), std::ranges::max);
        std::partial_sum(premin.begin(), premin.end(), premin.begin(), std::ranges::min);

        std::partial_sum(sufmax.rbegin(), sufmax.rend(), sufmax.rbegin(), std::ranges::max);
        std::partial_sum(sufmin.rbegin(), sufmin.rend(), sufmin.rbegin(), std::ranges::min);

        std::vector dp(2 * n + 1, 2 * n + 1);

        for (int i = 0; i < n; ++i)
        {
            chmin(dp[std::min(premin[i], sufmin[i])], std::max(premax[i], sufmax[i]));
        }

        std::partial_sum(dp.rbegin(), dp.rend(), dp.rbegin(), std::ranges::min);

        int64 ans = 0;

        for (int i = 1; i <= 2 * n; ++i)
        {
            ans += 2 * n - dp[i] + 1;
        }

        std::cout << ans << '\n';
    }

    return 0;
}
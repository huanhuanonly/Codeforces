/**
 * 牛客周赛 Round 137
 *
 * => F-小苯的糖果盒 ( @c 2000 )
 *
 * -> https://ac.nowcoder.com/acm/contest/130843/F
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83204222 By huanhuanonly
 *
 * @b Linear-DP
 *
 * ----April 08, 2026 [21h:01m:03s]----
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

    constexpr int maxn = 100, maxv = 100;

    std::vector<int> sq(maxv + 1);
    std::iota(sq.begin(), sq.end(), 0);
    std::ranges::transform(sq, sq.begin(), [](int x) -> int { return x * x; });

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        std::vector<int> v(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
            v[i] += v[i - 1];
        }

        constexpr auto inf = std::numeric_limits<int>::max() / 2;

        std::vector dp(n + 1, std::vector(v.back() + 1, std::vector(maxv + 1, inf)));
        std::ranges::fill(dp[0][0], 0);

        for (int i = 1; i <= n; ++i)
        {
            for (int s = 0; s <= v.back(); ++s)
            {
                for (int c = 0; c <= maxv; ++c)
                {
                    if (s >= sq[c])
                    {
                        dp[i][s][c] = dp[i - 1][s - sq[c]][c] + std::abs(v[i] - s);
                    }
                }

                std::partial_sum(dp[i][s].begin(), dp[i][s].end(), dp[i][s].begin(), std::ranges::min);
            }
        }

        int min = inf;

        for (int c = 0; c <= maxv; ++c)
        {
            min = std::min(min, dp.back().back()[c]);
        }

        if (min != inf)
        {
            std::cout << min << '\n';
        }
        else
        {
            std::cout << -1 << '\n';
        }
    }

    return 0;
}
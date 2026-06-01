/**
 * 牛客周赛 Round 137
 *
 * => D-小苯的序列涂色 ( @c 1500 )
 *
 * -> https://ac.nowcoder.com/acm/contest/130843/D
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83054847 By huanhuanonly
 *
 * @b Linear-DP and @b Bitwise-XOR
 *
 * ----March 29, 2026 [21h:07m:34s]----
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

        std::vector<uint64> v(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
            v[i] ^= v[i - 1];
        }

        auto sum = [&](int l, int r) -> uint64
        {
            return v[r] ^ v[l - 1];
        };

        const auto inf = std::numeric_limits<uint64>::max() / 2;

        std::vector<uint64> dp(n + 1, inf);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i)
        {
            uint64 min = inf;

            for (int j = 0; j < i; ++j)
            {
                min = std::min(min, sum(j + 1, i));
                dp[i] = std::min(dp[i], dp[j] + min);
            }
        }

        std::cout << dp.back() << '\n';
    }

    return 0;
}
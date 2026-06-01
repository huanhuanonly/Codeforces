/**
 * 牛客周赛 Round 138
 *
 * => E-小苯的数字染色 ( @c 1400 )
 *
 * -> https://ac.nowcoder.com/acm/contest/131111/E
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83155852 By huanhuanonly
 *
 * @b Linear-DP
 *
 * ----April 06, 2026 [12h:39m:25s]----
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

        std::vector<int64> v(n);

        for (auto& i : v)
        {
            std::cin >> i;
        }

        constexpr auto inf = std::numeric_limits<int64>::max() / 2;

        std::vector<int64> dp(n);
        std::array<int64, 2> max{-inf, -inf};

        max[v.front() & 1] = v.front();

        for (int i = 1; i < n; ++i)
        {
            dp[i] = std::max(dp[i - 1], max[v[i] & 1] + v[i]);
            max[v[i] & 1] = std::max(max[v[i] & 1], dp[i - 1] + v[i]);
        }

        std::cout << dp.back() << '\n';
    }

    return 0;
}
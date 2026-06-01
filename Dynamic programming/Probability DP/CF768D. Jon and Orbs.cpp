/**
 * Divide by Zero 2017 and Codeforces Round 399 (Div. 1 + Div. 2, combined)
 * 
 * => D. Jon and Orbs ( @c 2200 )
 * 
 * -> https://codeforces.com/contest/768/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/768/submission/371946192 By huanhuanonly
 * 
 * @b Probability-DP
 * 
 * ----April 21, 2026 [15h:33m:11s]----
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

    int k, q;
    std::cin >> k >> q;

    constexpr int n = 2e4;

    std::vector<real80> v(n + 1);

    std::vector dp(2, std::vector<real80>(k + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        dp[1][0] = 0;

        for (int j = 1; j <= k; ++j)
        {
            dp[1][j] = dp[0][j - 1] * (k - j + 1) / k + dp[0][j] * j / k;
        }

        v[i] = dp[1][k];
        std::swap(dp[0], dp[1]);
    }

    while (q--)
    {
        int p;
        std::cin >> p;

        std::cout << std::ranges::lower_bound(v, p / 2000.L) - v.begin() << '\n';
    }

    return 0;
}
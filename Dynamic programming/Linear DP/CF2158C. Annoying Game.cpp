/**
 * Codeforces Round 1067 (Div. 2)
 * 
 * => C. Annoying Game ( @c 1400 )
 * 
 * -> https://codeforces.com/contest/2158/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2158/submission/351967037 By huanhuanonly
 * 
 * @b Linear-DP and @b Game-theory
 * 
 * ----December 05, 2025 [15h:41m:29s]----
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
        int64 n, k;
        std::cin >> n >> k;

        std::vector<int64> a(n + 1), b(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
        }

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> b[i];
        }

        std::vector dp(2, std::vector(n + 1, int64{}));

        for (int i = 1; i <= n; ++i)
        {
            dp[0][i] = std::max(dp[0][i - 1], int64{}) + a[i];
            dp[1][i] = std::max(std::max(dp[1][i - 1], int64{}) + a[i], dp[0][i] + b[i]);
        }

        std::cout <<
            std::ranges::max(
                *std::ranges::max_element(dp[0] | std::views::drop(1)),
                *std::ranges::max_element(dp[k & 1] | std::views::drop(1))) << '\n';
    }

    return 0;
}
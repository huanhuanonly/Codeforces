/**
 * Codeforces Round 1044 (Div. 2)
 * 
 * => D. Chicken Jockey ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/2133/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2133/submission/335403691 By huanhuanonly
 * 
 * @b Linear-DP
 * 
 * ----August 25, 2025 [01h:51m:04s]----
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
        int n;
        std::cin >> n;

        std::vector<int64> v(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
        }

        std::vector<std::array<int64, 2>> dp(n + 1);

        dp[1][0] = dp[1][1] = v[1];

        for (int i = 2; i <= n; ++i)
        {
            dp[i][0] = std::min(dp[i - 1][0] + v[i] - 1, dp[i - 1][1] + std::max(v[i] - (i - 1), 0LL));
            dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1]) + v[i];
        }

        std::cout << std::min(dp[n][0], dp[n][1]) << '\n';
    }

    return 0;
}
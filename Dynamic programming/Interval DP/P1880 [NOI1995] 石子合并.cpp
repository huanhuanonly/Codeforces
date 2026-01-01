/**
 * => P1880 [NOI1995] 石子合并 ( @c 普及+/提高 )
 * 
 * -> https://www.luogu.com.cn/problem/P1880
 * 
 * Submissions ~> https://www.luogu.com.cn/record/252132546 By huanhuanonly
 * 
 * @b Interval-DP
 * 
 * ----December 08, 2025 [10h:42m:26s]----
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

    int n;
    std::cin >> n;

    std::vector<int> v(n * 2 + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
        v[i + n] = v[i];
    }

    for (int i = 1; i <= n * 2; ++i)
    {
        v[i] += v[i - 1];
    }

    constexpr auto inf = std::numeric_limits<int>::max() / 3;

    std::vector dp(2, std::vector(n * 2 + 1, std::vector(n * 2 + 1, 0)));

    for (int i = 1; i <= n * 2; ++i)
    {
        for (int j = 1; j <= n * 2; ++j)
        {
            dp[0][i][j] = +inf;
            dp[1][i][j] = -inf;
        }
    }

    for (int i = 1; i <= n * 2; ++i)
    {
        dp[0][i][i] = dp[1][i][i] = 0;
    }

    for (int len = 2; len <= n; ++len)
    {
        for (int i = 1; i <= n * 2; ++i)
        {
            const int j = i + len - 1;

            if (j <= n * 2)
            {
                for (int k = i; k + 1 <= j; ++k)
                {
                    dp[0][i][j] = std::min(dp[0][i][j], dp[0][i][k] + dp[0][k + 1][j] + v[j] - v[i - 1]);
                    dp[1][i][j] = std::max(dp[1][i][j], dp[1][i][k] + dp[1][k + 1][j] + v[j] - v[i - 1]);
                }
            }
        }
    }

    int min = +inf, max = -inf;

    for (int i = 1; i <= n; ++i)
    {
        min = std::min(min, dp[0][i][i + n - 1]);
        max = std::max(max, dp[1][i][i + n - 1]);
    }

    std::cout << min << '\n';
    std::cout << max << '\n';

    return 0;
}
/**
 * Educational Codeforces Round 1
 * 
 * => E. Chocolate Bar ( @c 2000 )
 * 
 * -> https://codeforces.com/contest/598/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/598/submission/328925099 By huanhuanonly
 * 
 * @b Linear-DP
 * 
 * ----July 14, 2025 [23h:35m:44s]----
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

    constexpr int N = 30, K = 50;
    constexpr int inf = std::numeric_limits<int>::max() / 2;

    std::vector dp(N + 1, std::vector(N + 1, std::vector(K + 1, inf)));

    for (int i = 0; i <= N; ++i)
    {
        for (int j = 0; j <= N; ++j)
        {
            dp[i][j][0] = 0;

            if (i * j <= K)
            {
                dp[i][j][i * j] = 0;
            }
        }
    }

    static auto $ = [](int x) -> int
    {
        return x * x;
    };

    for (int n = 1; n <= N; ++n)
    {
        for (int m = 1; m <= N; ++m)
        {
            for (int k = 1; k <= K; ++k)
            {
                if (k >= n * m)
                {
                    break;
                }

                for (int i = 1; i <= n; ++i)
                {
                    for (int j = 1; j <= m; ++j)
                    {
                        if (not (k >= i * j))
                        {
                            break;
                        }

                        if (i == n)
                        {
                            dp[n][m][k] = std::min(dp[n][m][k], $(n) + dp[n][m - j][k - i * j]);
                        }
                        else if (j == m)
                        {
                            dp[n][m][k] = std::min(dp[n][m][k], $(m) + dp[n - i][m][k - i * j]);
                        }
                        else
                        {
                            dp[n][m][k] = std::min({
                                dp[n][m][k],
                                $(n) + $(j) + std::min(dp[n][m - j][k - i * j], dp[n - i][j][k - i * j]),
                                $(m) + $(i) + std::min(dp[n - i][m][k - i * j], dp[i][m - j][k - i * j])});
                        }
                    }
                }
            }
        }
    }

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, m, k;
        std::cin >> n >> m >> k;

        std::cout << dp[n][m][k] << '\n';
    }

    return 0;
}
/**
 * AtCoder Beginner Contest 419
 * 
 * => E - Subarray Sum Divisibility ( @c 475 )
 * 
 * -> https://atcoder.jp/contests/abc419/tasks/abc419_e
 * 
 * Submissions ~> https://atcoder.jp/contests/abc419/submissions/68604544 By huanhuanonly
 * 
 * @b Knapsack-DP
 * 
 * ----August 18, 2025 [00h:19m:15s]----
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

    int n, m, len;
    std::cin >> n >> m >> len;

    std::vector<int> v(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
    }

    std::vector costs(len + 1, std::vector<int>(m));

    for (int i = 1; i <= len; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            for (int k = i; k <= n; k += len)
            {
                if (v[k] <= j)
                {
                    costs[i][j] += j - v[k];
                }
                else
                {
                    costs[i][j] += m + j - v[k];
                }
            }
        }
    }

    constexpr int inf = std::numeric_limits<int>::max() / 2;

    std::vector dp(len + 1, std::vector(m + 1, inf));

    dp[0][0] = 0;

    for (int i = 1; i <= len; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            for (int k = 0; k < m; ++k)
            {
                dp[i][j] = std::min(dp[i][j], dp[i - 1][(j + m - k) % m] + costs[i][k]);
            }
        }
    }

    std::cout << dp[len][0];

    return 0;
}
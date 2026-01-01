/**
 * Codeforces Round 1051 (Div. 2)
 * 
 * => D1. Inversion Graph Coloring (Easy Version) ( @c 1800 )
 * 
 * -> https://codeforces.com/contest/2143/problem/D1
 * 
 * Submissions ~> https://codeforces.com/contest/2143/submission/339325579 By huanhuanonly
 * 
 * @b Linear-DP
 * 
 * ----September 19, 2025 [10h:05m:55s]----
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

        std::vector<int> v(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
        }

        constexpr uint64 mod = 1e9 + 7;

        /**
         * @brief dp[i][fmax][smax]
         * 
         * @param fmax Current maximum value in the subsequence;
         * 
         * @param smax The largest "covered" value (a value that was
         *             once the maximum, but later got overshadowed
         *             by a larger fmax).
         */
        std::vector dp(n + 1, std::vector(n + 1, std::vector(n + 1, 0ULL)));
        dp[0][0][0] = 1;

        for (int i = 1; i <= n; ++i)
        {
            dp[i] = dp[i - 1];

            for (int fmax = 0; fmax <= n; ++fmax)
            {
                for (int smax = 0; smax <= n; ++smax)
                {
                    if (smax <= fmax and fmax <= v[i])
                    {
                        (dp[i][v[i]][smax] += dp[i - 1][fmax][smax]) %= mod;
                    }
                    else if (smax <= v[i] and v[i] <= fmax)
                    {
                        (dp[i][fmax][v[i]] += dp[i - 1][fmax][smax]) %= mod;
                    }
                }
            }
        }

        uint64 sum = 0;

        for (int fmax = 0; fmax <= n; ++fmax)
        {
            for (int smax = 0; smax <= n; ++smax)
            {
                (sum += dp[n][fmax][smax]) %= mod;
            }
        }

        std::cout << sum << '\n';
    }

    return 0;
}
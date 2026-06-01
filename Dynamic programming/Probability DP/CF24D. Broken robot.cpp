/**
 * Codeforces Beta Round 24
 * 
 * => D. Broken robot ( @c 2400 )
 * 
 * -> https://codeforces.com/contest/24/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/24/submission/372104164 By huanhuanonly
 * 
 * @b Expectation-DP and @b Gaussian-elimination
 * 
 * ----April 22, 2026 [15h:12m:57s]----
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

    int n, m;
    std::cin >> n >> m;

    int x, y;
    std::cin >> x >> y;

    --x, --y;
    n -= x;

    std::vector dp(n, std::vector<real80>(m));
    std::vector v(m, std::vector<real80>(m + 1));

    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = 0; j < m; ++j)
        {
            const real80 p = 1.L / (2 + (j != 0) + (j != m - 1));

            if (j - 1 >= 0)
            {
                v[j][j - 1] = -p;
            }

            v[j][j] = 1 - p;

            if (j + 1 < m)
            {
                v[j][j + 1] = -p;
            }

            v[j].back() = 1 + (p * dp[i + 1][j]);
        }

        for (int k = 0; k < m; ++k)
        {
            const auto div = v[k][k];

            for (int j = k; j < std::min(k + 2, m); ++j)
            {
                v[k][j] /= div;
            }

            v[k].back() /= div;

            if (k + 1 < m)
            {
                const auto x = v[k + 1][k];

                for (int j = k; j < std::min(k + 3, m); ++j)
                {
                    v[k + 1][j] -= v[k][j] * x;
                }

                v[k + 1].back() -= v[k].back() * x;
            }
        }

        for (int j = m - 1; j >= 0; --j)
        {
            if (j + 1 < m)
            {
                v[j].back() -= v[j][j + 1] * v[j + 1].back();
                v[j][j + 1] = 0;
            }

            dp[i][j] = v[j].back();
        }
    }

    std::cout << std::fixed << std::setprecision(12) << dp[0][y] << '\n';

    return 0;
}
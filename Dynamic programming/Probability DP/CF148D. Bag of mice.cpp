/**
 * Codeforces Round 105 (Div. 2)
 * 
 * => D. Bag of mice ( @c 1800 )
 * 
 * -> https://codeforces.com/contest/148/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/148/submission/371142707 By huanhuanonly
 * 
 * @b Probability-DP
 * 
 * ----April 14, 2026 [22h:35m:39s]----
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

    int w, b;
    std::cin >> w >> b;

    std::vector dp(w + 1, std::vector(b + 1, real80{}));

    for (int i = 1; i <= w; ++i)
    {
        for (int j = 0; j <= b; ++j)
        {
            const real80 fi = i, fj = j;

            dp[i][j] = fi / (fi + fj);

            if (fi + fj > 2)
            {
                if (j - 3 >= 0)
                {
                    dp[i][j] += ((fj / (fi + fj)) * ((fj - 1) / (fi + fj - 1))) * dp[i][j - 3] * ((fj - 2) / (fi + fj - 2));
                }
    
                if (i - 1 >= 0 and j - 2 >= 0)
                {
                    dp[i][j] += ((fj / (fi + fj)) * ((fj - 1) / (fi + fj - 1))) * dp[i - 1][j - 2] * (fi / (fi + fj - 2));
                }
            }
        }
    }

    std::cout << std::fixed << std::setprecision(12) << dp[w][b] << '\n';

    return 0;
}
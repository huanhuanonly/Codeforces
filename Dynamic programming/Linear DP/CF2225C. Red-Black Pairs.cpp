/**
 * Educational Codeforces Round 189 (Rated for Div. 2)
 *
 * => C. Red-Black Pairs ( @c 1100 )
 *
 * -> https://codeforces.com/contest/2225/problem/C
 *
 * Submissions ~> https://codeforces.com/contest/2225/submission/372001235 By huanhuanonly
 *
 * @b Linear-DP
 *
 * ----April 22, 2026 [00h:10m:15s]----
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

        std::string s, t;
        std::cin >> s >> t;

        std::vector<int> dp(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + (s[i - 1] != t[i - 1]);

            if (i >= 2)
            {
                dp[i] = std::min(dp[i], dp[i - 2] + (s[i - 2] != s[i - 1]) + (t[i - 2] != t[i - 1]));
            }
        }

        std::cout << dp.back() << '\n';
    }

    return 0;
}
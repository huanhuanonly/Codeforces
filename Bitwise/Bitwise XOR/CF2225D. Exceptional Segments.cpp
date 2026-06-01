/**
 * Educational Codeforces Round 189 (Rated for Div. 2)
 *
 * => D. Exceptional Segments ( @c 1500 )
 *
 * -> https://codeforces.com/contest/2225/problem/D
 *
 * Submissions ~> https://codeforces.com/contest/2225/submission/372024521 By huanhuanonly
 *
 * @b Bitwise-XOR
 *
 * ----April 22, 2026 [00h:11m:32s]----
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
        uint64 n, x;
        std::cin >> n >> x;

        constexpr uint64 mod = 998244353;

        uint64 ans = 0;

        const uint64 x1 = x / 4 * 4;

        if (x1 + 3 <= n)
        {
            ans += ((x1 / 4 + 1) % mod) * ((n + 1 - x1) / 4 % mod) % mod;
        }

        if (x >= 2)
        {
            const uint64 x2 = (x - 2) / 4 * 4 + 2;

            if (x2 + 3 <= n)
            {
                ans += ((x2 / 4 + 1) % mod) * ((n + 1 - x2) / 4 % mod) % mod;
            }
        }

        std::cout << ans % mod << '\n';
    }

    return 0;
}
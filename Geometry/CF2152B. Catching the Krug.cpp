/**
 * Squarepoint Challenge (Codeforces Round 1055, Div. 1 + Div. 2)
 * 
 * => B. Catching the Krug ( @c 1300 )
 * 
 * -> https://codeforces.com/contest/2152/problem/B
 * 
 * Submissions ~> https://codeforces.com/contest/2152/submission/341686829 By huanhuanonly
 * 
 * @b Geometry and @b Game-theory
 * 
 * ----October 04, 2025 [09h:45m:34s]----
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
        int64 n, a, b, c, d;
        std::cin >> n >> a >> b >> c >> d;

        int64 ans = std::max(std::abs(a - c), std::abs(b - d));

        auto calc = [&](int64 x, int64 y, bool f = false) -> void
        {
            if (not (x >= 0 and x <= n and y >= 0 and y <= n))
            {
                return;
            }

            int64 d1 = std::abs(a - x) + std::abs(b - y);
            int64 d2 = std::max(std::abs(c - x), std::abs(d - y));

            if (d1 < d2 or (f and d1 == d2))
            {
                ans = std::max(ans, d2);
            }
        };

        calc(0, 0);
        calc(0, n);
        calc(n, 0);
        calc(n, n);

        calc(a - 1, 0, true);
        calc(a + 1, 0, true);
        calc(0, b - 1, true);
        calc(0, b + 1, true);
        
        calc(a - 1, n, true);
        calc(a + 1, n, true);
        calc(n, b - 1, true);
        calc(n, b + 1, true);

        std::cout << ans << '\n';
    }

    return 0;
}
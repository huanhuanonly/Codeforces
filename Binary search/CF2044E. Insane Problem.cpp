/**
 * Codeforces Round 993 (Div. 4)
 * 
 * => E. Insane Problem ( @c 1300 )
 * 
 * -> https://codeforces.com/contest/2044/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2044/submission/315650233 By huanhuanonly
 * 
 * @b BinarySearch
 * 
 * ----April 15, 2025 [11h:05m:24s]----
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

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int _;
    std::cin >> _;

    while (_--)
    {
        uint64 k, l1, r1, l2, r2;
        std::cin >> k >> l1 >> r1 >> l2 >> r2;

        auto calc = [&](uint64 a) -> uint64
        {
            if (a * l1 > r2 or a * r1 < l2)
            {
                return 0;
            }

            auto check = [&](uint64 mid) -> bool
            {
                assert(a * mid >= l2);
                return a * mid <= r2;
            };

            uint64 start = std::max(l2 / a + !!(l2 % a), l1);

            if (a * start > r2)
            {
                return 0;
            }

            uint64 l = start, r = r1 + 1, mid;

            while (r - l > 1)
            {
                mid = l + r >> 1;

                if (check(mid))
                    l = mid;
                else
                    r = mid;
            }

            return l - start + 1;
        };

        uint64 ans = 0;

        for (uint64 i = 1; i <= 1e9; i *= k)
        {
            ans += calc(i);
        }

        std::cout << ans << '\n';
    }

    return 0;
}
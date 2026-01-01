/**
 * Educational Codeforces Round 184 (Rated for Div. 2)
 * 
 * => D1. Removal of a Sequence (Easy Version) ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/2169/problem/D1
 * 
 * Submissions ~> https://codeforces.com/contest/2169/submission/353811067 By huanhuanonly
 * 
 * @b Binary-search
 * 
 * ----December 17, 2025 [17h:10m:12s]----
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
        uint64 x, y, k;
        std::cin >> x >> y >> k;

        auto check = [&](uint64 mid) -> bool
        {
            for (uint64 i = 0; i < x; ++i)
            {
                mid -= mid / y;
            }

            return mid >= k;
        };

        uint64 l = 0, r = 1e12, mid;

        while (r - l > 1)
        {
            mid = l + r >> 1;

            if (check(mid))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }

        if (check(r))
        {
            std::cout << r << '\n';
        }
        else
        {
            std::cout << -1 << '\n';
        }
    }

    return 0;
}
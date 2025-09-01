/**
 * Codeforces Round 1013 (Div. 3)
 * 
 * => D. Place of the Olympiad ( @c 1200 )
 * 
 * -> https://codeforces.com/contest/2091/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2091/submission/315943207 By huanhuanonly
 * 
 * @b Binary-search
 * 
 * ----April 17, 2025 [18h:44m:17s]----
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
        uint64 n, m, k;
        std::cin >> n >> m >> k;

        auto check = [&](uint64 mid) -> bool
        {
            return ((m + 1) / (mid + 1) * mid + ((m + 1) % (mid + 1) ? (m + 1) % (mid + 1) - 1 : 0)) * n >= k;
        };

        uint64 l = 0, r = m, mid;

        while (r - l > 1)
        {
            mid = l + r >> 1;

            if (check(mid))
                r = mid;
            else
                l = mid;
        }

        std::cout << r << '\n';
    }

    return 0;
}
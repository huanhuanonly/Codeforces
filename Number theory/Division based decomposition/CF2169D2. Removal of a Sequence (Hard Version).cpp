/**
 * Educational Codeforces Round 184 (Rated for Div. 2)
 * 
 * => D2. Removal of a Sequence (Hard Version) ( @c 2100 )
 * 
 * -> https://codeforces.com/contest/2169/problem/D2
 * 
 * Submissions ~> https://codeforces.com/contest/2169/submission/353991762 By huanhuanonly
 * 
 * @b Number-theory ( @a division-based-decomposition )
 * 
 * ----December 18, 2025 [23h:30m:09s]----
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

        if (y == 1)
        {
            std::cout << -1 << '\n';
            continue;
        }

        constexpr uint64 limit = 1e12;

        for (uint64 i = 0; i < x; )
        {
            const auto add = (k - 1) / (y - 1);
            
            if (add == 0)
            {
                break;
            }
            
            const auto upp = (add + 1) * (y - 1) - 1;
            const auto cnt = std::min((upp + 1 - k) / add + 1, x - i);

            k += add * cnt;

            if (k > limit)
            {
                break;
            }

            i += cnt;
        }

        if (k <= limit)
        {
            std::cout << k << '\n';
        }
        else
        {
            std::cout << -1 << '\n';
        }
    }

    return 0;
}
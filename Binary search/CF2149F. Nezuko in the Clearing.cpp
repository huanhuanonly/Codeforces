/**
 * Codeforces Round 1054 (Div. 3)
 * 
 * => F. Nezuko in the Clearing ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/2149/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/2149/submission/340552160 By huanhuanonly
 * 
 * @b Binary-search
 * 
 * ----September 26, 2025 [10h:52m:20s]----
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

    std::vector<int64> presum(2e5);
    std::iota(presum.begin(), presum.end(), 0);
    std::partial_sum(presum.begin(), presum.end(), presum.begin());

    int _;
    std::cin >> _;

    while (_--)
    {
        int64 h, d;
        std::cin >> h >> d;

        auto check = [&](int64 mid) -> bool
        {
            int64 block = mid - d + 1;

            int64 health = h;

            const int64 dist = d / block;

            const int64 overflowing = d % block;

            if (health <= presum[dist])
            {
                return false;
            }

            health -= (block - overflowing) * (presum[dist] - 1);

            if (overflowing and health <= presum[dist + 1])
            {
                return false;
            }

            health -= overflowing * (presum[dist + 1] - 1);

            --health;

            return health > 0;
        };

        int64 l = d - 1, r = 2e9, mid;

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

        std::cout << r << '\n';
    }

    return 0;
}
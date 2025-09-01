/**
 * The 13th Shaanxi Provincial Collegiate Programming Contest
 * 
 * => K. Welfare
 * 
 * -> https://codeforces.com/gym/105891/problem/K
 * 
 * Submissions ~> https://codeforces.com/gym/105891/submission/319925329 By huanhuanonly
 * 
 * @b Binary-search
 * 
 * ----May 17, 2025 [12h:48m:59s]----
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
        int64 n, m, x, y;
        std::cin >> n >> m >> x >> y;

        if (y >= x)
        {
            std::cout << (n + m) * y << '\n';
            continue;
        }
        else if (n == 0)
        {
            std::cout << !!(m) * x << '\n';
            continue;
        }
        else if (m == 0)
        {
            std::cout << x + (n - 1) * y << '\n';
            continue;
        }

        int64 ans = n * y + x;

        auto check = [&](int64 mid) -> bool
        {
            return x / (mid + 1) + !!(x % (mid + 1)) <= y;
        };

        int64 l = -1, r = n, mid;

        while (r - l > 1)
        {
            mid = l + r >> 1;

            if (check(mid))
                r = mid;
            else
                l = mid;
        }

        if (check(r))
            std::cout << std::max(ans, !!(r) * x + (m + n - r) * y) << '\n';
        else
            std::cout << ans << '\n';
    }

    return 0;
}
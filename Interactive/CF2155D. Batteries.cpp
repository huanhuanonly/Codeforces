/**
 * Codeforces Round 1056 (Div. 2)
 * 
 * => D. Batteries ( @c 1800 )
 * 
 * -> https://codeforces.com/contest/2155/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2155/submission/342699933 By huanhuanonly
 * 
 * @b Interactive
 * @b Constructive
 * @b Combinatorics ( @a Pigeonhole-principle )
 * 
 * ----October 09, 2025 [15h:03m:43s]----
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
        int n;
        std::cin >> n;

        auto query = [n](int u, int v) -> bool
        {
            if (v == 0)
            {
                v = n;
            }

            std::cout << u << ' ' << v << std::endl;

            bool res;
            std::cin >> res;

            return res;
        };

        bool found = false;

        for (int d = 1; d < n and not found; ++d)
        {
            for (int i = 1; i <= n and not found; ++i)
            {
                if (query(i, (i + d) % n))
                {
                    found = true;
                }
            }
        }
    }

    return 0;
}
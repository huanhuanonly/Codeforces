/**
 * Codeforces Round 1022 (Div. 2)
 * 
 * => B. SUMdamental Decomposition ( @c 1300 )
 * 
 * -> https://codeforces.com/contest/2108/problem/B
 * 
 * Submissions ~> https://codeforces.com/contest/2108/submission/318686534 By huanhuanonly
 * 
 * @b Classification-discussion
 * 
 * ----May 07, 2025 [12h:25m:08s]----
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
        uint64 n, x;
        std::cin >> n >> x;

        if (x == 1)
        {
            if (n & 1)
            {
                std::cout << n << '\n';
            }
            else
            {
                std::cout << n - 2 + 2 + 3 << '\n';
            }
        }
        else if (x == 0)
        {
            if (n == 1)
            {
                std::cout << -1 << '\n';
            }
            else if (n & 1)
            {
                std::cout << n - 2 + 2 + 3 << '\n';
            }
            else
            {
                std::cout << n << '\n';
            }
        }
        else
        {
            if (uint64 m = std::popcount(x); m >= n)
            {
                std::cout << x << '\n';
            }
            else
            {
                std::cout << n - m + x + ((n - m) & 1) << '\n';
            }
        }
    }

    return 0;
}
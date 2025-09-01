/**
 * Codeforces Round 1035 (Div. 2)
 * 
 * => C. A Good Problem ( @c 1300 )
 * 
 * -> https://codeforces.com/contest/2119/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2119/submission/327621473 By huanhuanonly
 * 
 * @b Bitwise-AND
 * 
 * ----July 06, 2025 [11h:58m:03s]----
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
        uint64 n, l, r, k;
        std::cin >> n >> l >> r >> k;

        if (n & 1)
        {
            std::cout << l << '\n';
        }
        else if (n == 2)
        {
            std::cout << -1 << '\n';
        }
        else
        {
            uint64 x = 1;
            
            for (; x <= l; x <<= 1);
            
            if (l <= x and x <= r)
            {
                if (k == n - 1 or k == n)
                {
                    std::cout << x << '\n';
                }
                else
                {
                    std::cout << l << '\n';
                }
            }
            else
            {
                std::cout << -1 << '\n';
            }
        }
    }

    return 0;
}
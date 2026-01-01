/**
 * Codeforces Round 1057 (Div. 2)
 * 
 * => B. Bitwise Reversion ( @c 800 )
 * 
 * -> https://codeforces.com/contest/2153/problem/B
 * 
 * Submissions ~> https://codeforces.com/contest/2153/submission/342961843 By huanhuanonly
 * 
 * @b Bitwise-AND
 * 
 * ----October 11, 2025 [10h:46m:17s]----
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
        int x, y, z;
        std::cin >> x >> y >> z;

        const int a = x | z, b = x | y, c = y | z;

        if ((a & b) == x and (b & c) == y and (a & c) == z)
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}
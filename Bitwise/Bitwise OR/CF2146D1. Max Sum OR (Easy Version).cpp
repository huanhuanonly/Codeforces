/**
 * Codeforces Round 1052 (Div. 2)
 * 
 * => D1. Max Sum OR (Easy Version) ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/2146/problem/D1
 * 
 * Submissions ~> https://codeforces.com/contest/2146/submission/340062884 By huanhuanonly
 * 
 * @b Bitwise-OR
 * 
 * ----September 24, 2025 [01h:01m:29s]----
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

constexpr int64 lowbit(int64 x)
{
    return x & -x;
}

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
        int64 l, r;
        std::cin >> l >> r;

        std::vector<int64> v(r + 1);
        std::iota(v.begin(), v.end(), 0);

        for (int64 i = r; i > 0; )
        {
            int64 mask = i << 1;
            
            for (; mask != lowbit(mask); mask -= lowbit(mask));
            --mask;

            const int64 j = i ^ mask;

            std::reverse(v.begin() + j, v.begin() + i + 1);
            i = j - 1;
        }

        std::cout << r * (r + 1) << '\n';

        for (int64 i : v)
        {
            std::cout << i << ' ';
        }

        std::cout.put('\n');
    }

    return 0;
}
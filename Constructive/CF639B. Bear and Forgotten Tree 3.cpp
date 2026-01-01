/**
 * VK Cup 2016 - Round 1
 * 
 * => B. Bear and Forgotten Tree 3 ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/639/problem/B
 * 
 * Submissions ~> https://codeforces.com/contest/639/submission/345337900 By huanhuanonly
 * 
 * @b Constructive and @b Trees
 * 
 * ----October 23, 2025 [19h:54m:34s]----
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

    int n, d, h;
    std::cin >> n >> d >> h;

    if (d > h * 2 or (d == 1 and n != 2))
    {
        std::cout << -1 << '\n';
    }
    else
    {
        int last = 1;
        int cur = 2;

        for (int i = 0; i < h; ++i)
        {
            std::cout << last << ' ' << cur << '\n';
            last = std::exchange(cur, cur + 1);
        }

        last = 1;

        for (int i = 0; i < d - h; ++i)
        {
            std::cout << last << ' ' << cur << '\n';
            last = std::exchange(cur, cur + 1);
        }

        for (; cur <= n; ++cur)
        {
            std::cout << (d == h) + 1 << ' ' << cur << '\n';
        }
    }

    return 0;
}
/**
 * Codeforces Round 1082 (Div. 2)
 * 
 * => D. Recollect Numbers ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/2202/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2202/submission/368877247 By huanhuanonly
 * 
 * @b Constructive
 * 
 * ----March 31, 2026 [00h:10m:09s]----
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

#if defined(__SIZEOF_INT128__)
using int128 = __int128;
using uint128 = unsigned __int128;
#endif

using real32 = float;
using real64 = double;

#if defined(__SIZEOF_FLOAT80__)
using real80 = __float80;
#endif

#if defined(__SIZEOF_FLOAT128__)
using real128 = __float128;
#endif

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, k;
        std::cin >> n >> k;

        if (not (n <= k and k <= 2 * n - 1))
        {
            std::cout << "NO\n";
            continue;
        }

        std::cout << "YES\n";

        const int cnt = 2 * n - 1 - k;
        const int rem = n - cnt;

        if (rem == 1)
        {
            std::cout << 1 << ' ' << 1 << ' ';
        }
        else
        {
            std::cout << 1 << ' ' << 2 << ' ';
            
            for (int i = 3; i <= rem; ++i)
            {
                std::cout << i << ' ' << i - 2 << ' ';
            }
            
            std::cout << rem - 1 << ' ' << rem << ' ';
        }

        for (int i = 0; i < cnt; ++i)
        {
            std::cout << n - i << ' ' << n - i << ' ';
        }

        std::cout.put('\n');
    }

    return 0;
}
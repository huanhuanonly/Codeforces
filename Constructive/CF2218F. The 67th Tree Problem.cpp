/**
 * Codeforces Round 1090 (Div. 4)
 *
 * => F. The 67th Tree Problem ( @c 1500 )
 *
 * -> https://codeforces.com/contest/2218/problem/F
 *
 * Submissions ~> https://codeforces.com/contest/2218/submission/370168692 By huanhuanonly
 *
 * @b Constructive and @b Trees
 *
 * ----April 07, 2026 [23h:59m:35s]----
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
        int x, y;
        std::cin >> x >> y;

        const int n = x + y;

        int id = 1;

        std::vector<std::vector<int>> e(n + 1);

        auto build = [&]() -> bool
        {
            if (x > y)
            {
                return false;
            }
            else if (x)
            {
                const int rt = ++id;
                e[1].push_back(rt);

                e[++id].push_back(rt);

                --x, --y;
            }
            else if (y)
            {
                const int rt = ++id;
                e[1].push_back(rt);

                --y;
            }
            else
            {
                return false;
            }

            return true;
        };

        if (n & 1)
        {
            --y;
        }
        else
        {
            --x;
        }

        bool yes = x >= 0 and y >= 0;
        for (; yes and (x or y); yes = build());

        if (yes)
        {
            std::cout << "YES\n";

            for (int i = 1; i <= n; ++i)
            {
                for (const auto& j : e[i])
                {
                    std::cout << i << ' ' << j << '\n';
                }
            }
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}
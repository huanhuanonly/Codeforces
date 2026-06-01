/**
 * Codeforces Round 1087 (Div. 2)
 *
 * => C. Find the Zero ( @c 1400 )
 *
 * -> https://codeforces.com/contest/2209/problem/C
 *
 * Submissions ~> https://codeforces.com/contest/2209/submission/368046025 By huanhuanonly
 *
 * @b Interactive and @b Constructive
 *
 * ----March 24, 2026 [23h:21m:08s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        int k = 0;

        auto query = [&](int i, int j) -> void
        {
            if (not k)
            {
                std::cout << "? " << i << ' ' << j << std::endl;

                bool b;
                std::cin >> b;

                if (b)
                {
                    k = i;
                }
            }
        };

        auto answer = [&]() -> void
        {
            std::cout << "! " << k << std::endl;
        };

        if (n == 2)
        {
            query(1, 2);
            query(1, 3);
            query(2, 3);

            if (not k)
            {
                k = 4;
            }
        }
        else
        {
            for (int i = 1; i < n; ++i)
            {
                query(i, n + i);
            }

            query(1, n);
            query(n + 1, n + n);

            if (not k)
            {
                k = n + n;
            }
        }

        answer();
    }

    return 0;
}
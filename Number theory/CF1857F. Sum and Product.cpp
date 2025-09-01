/**
 * Codeforces Round 891 (Div. 3)
 * 
 * => F. Sum and Product ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/1857/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/1857/submission/331484838 By huanhuanonly
 * 
 * @b Math ( @a Quadratic-Formula )
 * 
 * ----July 30, 2025 [01h:23m:05s]----
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

        std::map<int, int64> cnt;

        for (int i = 0, v; i < n; ++i)
        {
            std::cin >> v;
            ++cnt[v];
        }

        int q;
        std::cin >> q;

        while (q--)
        {
            int64 x, y;
            std::cin >> x >> y;

            int64 a = (x - std::sqrt(x * x - 4 * y)) / 2;
            int64 b = x - a;

            if (a * b == y)
            {
                if (a == b)
                {
                    std::cout << cnt[a] * (cnt[a] - 1) / 2 << ' ';
                }
                else
                {
                    std::cout << cnt[a] * cnt[b] << ' ';
                }
            }
            else
            {
                std::cout << 0 << ' ';
            }
        }

        std::cout.put('\n');
    }

    return 0;
}
/**
 * Codeforces Round 1068 (Div. 2)
 * 
 * => E. Shiro's Mirror Duel ( @c 2200 )
 * 
 * -> https://codeforces.com/contest/2173/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2173/submission/352523957 By huanhuanonly
 * 
 * @b Interactive and @b Two-pointers ( @a >==< )
 * 
 * ----December 08, 2025 [17h:16m:05s]----
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

        std::vector<int> v(n + 1);
        std::vector<int> pos(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
            pos[v[i]] = i;
        }

        auto query = [&](int x, int y) -> void
        {
            int rx, ry;

            do
            {
                std::cout << '?' << ' ' << x << ' ' << y << std::endl;
                std::cin >> rx >> ry;

                std::ranges::swap(pos[v[rx]], pos[v[ry]]);
                std::ranges::swap(v[rx], v[ry]);

            } while (std::minmax(x, y) != std::minmax(rx, ry));
        };

        static auto answer = []() -> void
        {
            std::cout.put('!').put('\n').flush();
        };

        for (int l = 1, r = n; l < r; ++l, --r)
        {
            while (pos[l] != l or pos[r] != r)
            {
                if (pos[l] != l)
                {
                    query(pos[l], l);
                }
    
                if (pos[r] != r)
                {
                    query(pos[r], r);
                }
            }
        }
        
        answer();
    }

    return 0;
}
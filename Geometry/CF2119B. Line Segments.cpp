/**
 * Codeforces Round 1035 (Div. 2)
 * 
 * => B. Line Segments ( @c 1200 )
 * 
 * -> https://codeforces.com/contest/2119/problem/B
 * 
 * Submissions ~> https://codeforces.com/contest/2119/submission/327673220 By huanhuanonly
 * 
 * @b Geometry
 * 
 * ----July 06, 2025 [13h:42m:50s]----
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

        uint64 sx, sy, tx, ty;
        std::cin >> sx >> sy >> tx >> ty;

        real128 dis = std::sqrt((sx - tx) * (sx - tx) + (sy - ty) * (sy - ty));

        bool yes = true;
        std::vector<uint64> v(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
            v[i] += v[i - 1];
        }

        auto get = [&](int l, int r) -> uint64
        {
            return v[r] - v[l - 1];
        };

        for (int i = 1; i <= n; ++i)
        {
            if (get(1, i) < dis)
            {
                continue;
            }

            if (get(i, i) > get(1, i - 1) + dis and (i == n or get(i, i) - get(1, i - 1) - dis > get(i + 1, n)))
            {
                yes = false;
                break;
            }
        }

        if (not yes or get(1, n) < dis)
        {
            std::cout << "No\n";
        }
        else
        {
            std::cout << "Yes\n";
        }
    }

    return 0;
}
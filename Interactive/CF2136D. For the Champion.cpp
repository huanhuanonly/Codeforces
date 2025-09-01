/**
 * Codeforces Round 1046 (Div. 2)
 * 
 * => D. For the Champion ( @c Rating )
 * 
 * -> https://codeforces.com/contest/2136/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2136/submission/336036256 By huanhuanonly
 * 
 * @b Interactive and @b Geometry
 * 
 * ----August 29, 2025 [01h:25m:28s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int64 n;
        std::cin >> n;

        using coord = std::pair<int64, int64>;

        std::vector<coord> v(n);

        auto dist = [](const coord& lv, const coord& rv) -> int64
        {
            return std::abs(lv.first - rv.first) + std::abs(lv.second - rv.second);
        };

        constexpr int64 inf = std::numeric_limits<int64>::max() / 2;

        int64 mru = inf;
        int64 mlu = inf;

        for (int64 i = 0; i < n; ++i)
        {
            std::cin >> v[i].first >> v[i].second;

            mru = std::min(mru, dist(v[i], {1e9, 1e9}));
            mlu = std::min(mlu, dist(v[i], {-2e9, 1e9}));
        }

        auto query = [](char c, int64 k) -> int64
        {
            std::cout << "? " << c << ' ' << k << std::endl;

            int64 s;
            std::cin >> s;

            return s;
        };

        auto answer = [](int64 x, int64 y) -> void
        {
            std::cout << "! " << x << ' ' << y << std::endl;
        };

        query('R', 1e9);
        query('R', 1e9);
        query('U', 1e9);
        int64 ru = query('U', 1e9) - mru;

        query('L', 1e9);
        query('L', 1e9);
        query('L', 1e9);
        int64 lu = query('L', 1e9) - mlu;

        // (+, -)
        coord cru{1e9, 1e9 + ru};
        cru.first -= 2e9, cru.second -= 2e9;
       
        // (-, -)
        coord clu{-2e9, 1e9 + lu};
        clu.first += 2e9, clu.second -= 2e9;

        if (cru.second > clu.second)
        {
            cru.first += cru.second - clu.second;
            cru.second -= cru.second - clu.second;
        }
        else
        {
            clu.first -= clu.second - cru.second;
            clu.second -= clu.second - cru.second;
        }

        int64 diff = (clu.first - cru.first) / 2;
        
        cru.first += diff, cru.second -= diff;
        clu.first -= diff, clu.second -= diff;

        assert(cru == clu);

        answer(cru.first, cru.second);
    }

    return 0;
}
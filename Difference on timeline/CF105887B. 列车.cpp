/**
 * 第十三届重庆市大学生程序设计竞赛
 * 
 * => B - 列车
 * 
 * -> https://codeforces.com/gym/105887/problem/B
 * 
 * Submissions ~> https://codeforces.com/gym/105887/submission/319783509 By huanhuanonly
 * 
 * @b Difference-on-timeline
 * 
 * ----May 16, 2025 [14h:43m:45s]----
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
        int n, m;
        std::cin >> n >> m;

        auto id = [](int64 x) -> int64 { return x * 3; };

        std::map<int64, int64> mp{{id(1), 0}, {id(n), 0}};

        int64 l, r, c;
        for (int i = 0; i < m; ++i)
        {
            std::cin >> l >> r >> c;

            mp[id(l)] += c;
            mp[id(r) + 1] -= c;
        }

        if (mp.rbegin()->first > id(n))
        {
            mp.erase(mp.rbegin()->first);
        }

        int64 mn = std::numeric_limits<int64>::max();
        int64 sum = 0;

        for (int64 i : mp | std::views::values)
        {
            mn = std::min(mn, sum += i);
        }

        std::cout << mn << '\n';
    }

    return 0;
}
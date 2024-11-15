/**
 * Codeforces Round 977 (Div. 2, based on COMPFEST 16 - Final
 * 
 * => C2. Adjust The Presentation (Hard Version) ( @c 1900 )
 * 
 * -> https://codeforces.com/problemset/problem/2021/C2
 * 
 * Submissions ~> https://codeforces.com/contest/2021/submission/291551980 By huanhuanonly
 * 
 * @b Reindex
 * 
 * ----November 15, 2024 [17h:44m:01s]----
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

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    uint32 _;
    std::cin >> _;

    while (_--)
    {
        uint32 n, m, q;
        std::cin >> n >> m >> q;

        std::vector<uint32> v(n + 1);

        std::vector<uint32> mp(n + 1);

        for (uint32 i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
            mp[v[i]] = i;
        }

        std::vector<uint32> b(m + 1);

        constexpr uint32 inf = std::numeric_limits<uint32>::max();
        std::vector<std::set<uint32>> pos(n + 1, {inf});
        std::vector<uint32> ft(n + 1, inf);

        for (uint32 i = 1; i <= m; ++i)
        {
            std::cin >> b[i];
            b[i] = mp[b[i]];

            pos[b[i]].insert(i);
            ft[b[i]] = std::min(ft[b[i]], i);
        }

        uint32 wa = 0;

        for (uint32 i = 1; i < n; ++i)
        {
            wa += not(ft[i] <= ft[i + 1]);
        }

        auto check = [&](uint32 i) -> uint32
        {
            uint32 sum = 0;

            if (i != 1)
            {
                sum += not(ft[i - 1] <= ft[i]);
            }

            if (i != n)
            {
                sum += not(ft[i] <= ft[i + 1]);
            }

            return sum;
        };

        std::cout << (not wa ? "YA\n" : "TIDAK\n");

        while (q--)
        {
            uint32 s, t;
            std::cin >> s >> t;

            t = mp[t];

            wa -= check(b[s]);

            pos[b[s]].erase(s);
            ft[b[s]] = *pos[b[s]].begin();

            wa += check(b[s]);

            wa -= check(t);

            pos[t].insert(s);
            ft[t] = *pos[t].begin();

            wa += check(t);

            b[s] = t;

            std::cout << (not wa ? "YA\n" : "TIDAK\n");
        }
    }

    return 0;
}

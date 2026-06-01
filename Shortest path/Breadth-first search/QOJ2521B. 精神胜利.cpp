/**
 * 2025 CCPC 全国邀请赛（南昌）暨第二届江西省赛
 * 
 * => B. 精神胜利
 * 
 * -> https://qoj.ac/contest/2521/problem/14502
 * 
 * Submissions ~> https://qoj.ac/submission/2204945 By huanhuanonly
 * 
 * @b Breadth-first-search ( @a bitset-optimization )
 * 
 * ----April 07, 2026 [22h:13m:30s]----
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

    int n, q;
    std::cin >> n >> q;

    using bset = std::bitset<5000>;

    std::vector<bset> e(n);
    std::vector dis(n, std::vector(n, -1));

    std::string s;
    
    for (int i = 0; i < n - 1; ++i)
    {
        std::cin >> s;

        for (int j = i + 1, pos = 0; j < n; ++j, ++pos)
        {
            if (s[pos] - '0')
            {
                e[i].set(j);
            }

            if (not (s[pos] - '0'))
            {
                e[j].set(i);
            }
        }
    }

    auto bfs = [&](int start) -> void
    {
        bset cur, next, vis;

        cur.set(start);

        int lay = 0;

        do
        {
            vis |= cur;

            for (int i = cur._Find_first(); i < n; i = cur._Find_next(i))
            {
                next |= e[i];
            }

            next &= ~vis;

            for (int i = next._Find_first(); i < n; i = next._Find_next(i))
            {
                dis[start][i] = lay;
            }

            cur = std::move(next);
            next.reset();

            ++lay;

        } while (cur.any());
    };

    std::ranges::for_each(std::views::iota(0, n), bfs);

    while (q--)
    {
        int u, v;
        std::cin >> u >> v;

        --u, --v;

        std::cout << dis[u][v] << '\n';
    }

    return 0;
}
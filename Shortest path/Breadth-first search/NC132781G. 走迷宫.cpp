/**
 * 哈尔滨华德学院第十七届程序设计竞赛（同步赛）
 *
 * => G-走迷宫
 *
 * -> https://ac.nowcoder.com/acm/contest/132781/G
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83574364 By huanhuanonly
 *
 * @b Breadth-first-search
 *
 * ----May 12, 2026 [19h:08m:26s]----
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
        int n;
        std::cin >> n;

        std::vector mp(n, std::vector(n, std::vector(n, std::vector(n, '.'))));

        std::tuple<int, int, int, int> s, e;

        for (int i = 0; i < n * n; ++i)
        {
            for (int j = 0; j < n * n; ++j)
            {
                const int x = i % n, y = j % n, z = j / n, t = i / n;

                char& c = mp[x][y][z][t];
                std::cin >> c;

                if (c == 'S')
                {
                    s = std::make_tuple(x, y, z, t);
                }
                else if (c == 'E')
                {
                    e = std::make_tuple(x, y, z, t);
                }
            }
        }

        std::vector vis(n, std::vector(n, std::vector(n, std::vector<bool>(n))));

        struct item
        {
            std::tuple<int, int, int, int> pos;
            int dis;
        };

        std::queue<item> que;
        que.emplace(s, 0);

        int dis = -1;

        while (not que.empty())
        {
            auto cur = que.front();
            que.pop();

            if (cur.pos == e)
            {
                dis = cur.dis;
                break;
            }

            if (vis[std::get<0>(cur.pos)][std::get<1>(cur.pos)][std::get<2>(cur.pos)][std::get<3>(cur.pos)])
            {
                continue;
            }

            vis[std::get<0>(cur.pos)][std::get<1>(cur.pos)][std::get<2>(cur.pos)][std::get<3>(cur.pos)] = true;

            for (uint32 mask = 1; mask < (1 << 4); mask <<= 1)
            {
                const int x = std::get<0>(cur.pos) + !!(mask & (1 << 0));
                const int y = std::get<1>(cur.pos) + !!(mask & (1 << 1));
                const int z = std::get<2>(cur.pos) + !!(mask & (1 << 2));
                const int t = std::get<3>(cur.pos) + !!(mask & (1 << 3));

                if (x < n and y < n and z < n and t < n and mp[x][y][z][t] != '#')
                {
                    que.emplace(std::make_tuple(x, y, z, t), cur.dis + 1);
                }
            }

            for (uint32 mask = 1; mask < (1 << 4); mask <<= 1)
            {
                const int x = std::get<0>(cur.pos) - !!(mask & (1 << 0));
                const int y = std::get<1>(cur.pos) - !!(mask & (1 << 1));
                const int z = std::get<2>(cur.pos) - !!(mask & (1 << 2));
                const int t = std::get<3>(cur.pos) - !!(mask & (1 << 3));

                if (x >= 0 and y >= 0 and z >= 0 and t >= 0 and mp[x][y][z][t] != '#')
                {
                    que.emplace(std::make_tuple(x, y, z, t), cur.dis + 1);
                }
            }
        }

        std::cout << dis << '\n';
    }

    return 0;
}
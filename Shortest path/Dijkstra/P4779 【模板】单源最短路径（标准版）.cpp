/**
 * => P4779 【模板】单源最短路径（标准版） ( @c 普及/提高− )
 * 
 * -> https://www.luogu.com.cn/problem/P4779
 * 
 * Submissions ~> https://www.luogu.com.cn/record/214202535 By huanhuanonly
 * 
 * @b Dijkstra
 * 
 * ----April 18, 2025 [22h:11m:08s]----
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

    int n, m, s;
    std::cin >> n >> m >> s;

    struct edge
    {
        int64 point, w;

        bool operator<(const edge& other) const
        {
            return this->w > other.w;
        }
    };

    std::vector<std::vector<edge>> e(n + 1);

    std::vector<bool> vis(n + 1);

    constexpr int64 inf = std::numeric_limits<int64>::max() / 2;
    std::vector<int64> dis(n + 1, inf);

    for (int i = 0; i < m; ++i)
    {
        int64 u, v, w;
        std::cin >> u >> v >> w;

        e[u].push_back({v, w});
    }

    auto bfs = [&]() -> void
    {
        std::priority_queue<edge> que;
        que.push({s, 0});
        dis[s] = 0;

        while (not que.empty())
        {
            auto cur = que.top();
            que.pop();

            if (vis[cur.point])
                continue;
            else
                vis[cur.point] = true;

            for (const auto& next : e[cur.point])
            {
                if (int64 newdis = dis[cur.point] + next.w; newdis < dis[next.point])
                {
                    dis[next.point] = newdis;
                    que.push({next.point, newdis});
                }
            }
        }
    };

    bfs();

    for (int i = 1; i <= n; ++i)
    {
        std::cout << dis[i] << ' ';
    }

    return 0;
}
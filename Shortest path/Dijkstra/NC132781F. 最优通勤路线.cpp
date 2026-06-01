/**
 * 哈尔滨华德学院第十七届程序设计竞赛（同步赛）
 *
 * => F-最优通勤路线
 *
 * -> https://ac.nowcoder.com/acm/contest/132781/F
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83569546 By huanhuanonly
 *
 * @b Dijkstra
 *
 * ----May 12, 2026 [17h:58m:02s]----
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

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> e(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        std::cin >> u >> v >> w;

        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }

    auto bfs = [&](int s, int t) -> int64
    {
        constexpr auto inf = std::numeric_limits<int64>::max() / 2;

        std::vector dis(n + 1, inf);
        std::vector vis(n + 1, false);

        struct item
        {
            int64 to, dis;

            bool operator<(const item& other) const
            {
                return dis > other.dis;
            }
        };

        std::priority_queue<item> que;
        que.emplace(s, 0);
        dis[s] = 0;

        while (not que.empty())
        {
            auto cur = que.top();
            que.pop();

            if (vis[cur.to])
            {
                continue;
            }

            vis[cur.to] = true;

            for (const auto& [u, w] : e[cur.to])
            {
                const auto ndis = dis[cur.to] + w;

                if (ndis < dis[u])
                {
                    dis[u] = ndis;
                    que.emplace(u, ndis);
                }
            }
        }

        return dis[t];
    };

    int s, x, t;
    std::cin >> s >> x >> t;

    std::cout << bfs(s, x) + bfs(x, t) << '\n';

    return 0;
}
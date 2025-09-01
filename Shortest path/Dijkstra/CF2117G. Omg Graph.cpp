/**
 * Codeforces Round 1029 (Div. 3)
 * 
 * => G. Omg Graph ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/2117/problem/G
 * 
 * Submissions ~> https://codeforces.com/contest/2117/submission/328381658 By huanhuanonly
 * 
 * @b Dijkstra
 * 
 * ----July 10, 2025 [20h:58m:44s]----
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

        struct edge
        {
            int to, w;
        };

        std::vector<std::vector<edge>> e(n + 1);

        for (int i = 0; i < m; ++i)
        {
            int u, v, w;
            std::cin >> u >> v >> w;

            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }

        std::vector<int> min(n + 1, std::numeric_limits<int>::max());
        std::vector<int> max(n + 1, std::numeric_limits<int>::max());
        
        auto bfs = [&]() -> void
        {
            std::vector<uint8> vis(n + 1);

            struct item
            {
                int point;
                int max;

                bool operator<(const item& other) const noexcept
                {
                    return max > other.max;
                }
            };

            std::priority_queue<item> que;
            que.push({1, 0});

            min[1] = 0;
            max[1] = 0;

            while (not que.empty())
            {
                item cur = que.top();
                que.pop();

                if (std::exchange(vis[cur.point], true))
                {
                    continue;
                }

                for (const auto& [to, w] : e[cur.point])
                {
                    min[to] = std::min(min[to], w);

                    if (int cmax = std::max(max[cur.point], w); cmax < max[to])
                    {
                        max[to] = cmax;
                        que.push({to, cmax});
                    }
                }
            }
        };

        bfs();

        int ans = std::numeric_limits<int>::max();

        for (int i = 2; i <= n; ++i)
        {
            ans = std::min(ans, std::max(max[n], max[i]) + min[i]);
        }

        std::cout << ans << '\n';
    }

    return 0;
}
/**
 * Codeforces Round 816 (Div. 2)
 * 
 * => E. Long Way Home ( @c 2400 )
 * 
 * -> https://codeforces.com/contest/1715/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/1715/submission/348712624 By huanhuanonly
 * 
 * @b DP with @b Convex-hull-trick
 * @b Prefix-sum
 * @b Monotonic-queue
 * @b Dijkstra
 * 
 * ----November 13, 2025 [15h:22m:55s]----
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

    int64 n, m, k;
    std::cin >> n >> m >> k;

    struct edge
    {
        int64 to, w;
    };

    std::vector<std::vector<edge>> e(n + 1);

    for (int64 i = 0; i < m; ++i)
    {
        int64 u, v, w;
        std::cin >> u >> v >> w;

        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
    
    auto bfs = [&](std::vector<int64>& dis, const auto& set) -> void
    {
        std::vector<bool> vis(n + 1);

        struct item
        {
            int64 point, dis;

            bool operator<(const item& other) const noexcept
            {
                return dis > other.dis;
            }
        };

        std::priority_queue<item> que;
        
        for (const auto i : set)
        {
            que.emplace(i, dis[i]);
        }

        while (not que.empty())
        {
            auto cur = que.top();
            que.pop();

            if (vis[cur.point])
            {
                continue;
            }

            vis[cur.point] = true;

            for (const auto& [to, w] : e[cur.point])
            {
                if (const auto ndis = dis[cur.point] + w; ndis < dis[to])
                {
                    dis[to] = ndis;
                    que.emplace(to, ndis);
                }
            }
        }
    };

    const auto inf = static_cast<int64>(1e12);

    std::vector dp(k + 1, std::vector(n + 1, inf));
    
    for (int64 i = 0; i <= k; ++i)
    {
        dp[i][1] = 0;
    }

    bfs(dp[0], std::views::single(1));

    struct point
    {
        int64 x, y;

        point operator-(const point& other) const noexcept
        {
            return {x - other.x, y - other.y};
        }

        int64 operator*(const point& other) const noexcept
        {
            return (x * other.y) - (y * other.x);
        }
    };

    for (int64 i = 1; i <= k; ++i)
    {
        std::deque<point> que;
        
        for (int64 j = 1; j <= n; ++j)
        {
            const point c{j, dp[i - 1][j] + j * j};

            for (; que.size() >= 2 and (que[que.size() - 2] - que.back()) * (c - que.back()) > 0; que.pop_back());
            que.push_back(c);
        }

        for (int64 j = 1; j <= n; ++j)
        {
            auto $ = [&](const point& c) -> int64
            {
                return (c.y - 2 * j * c.x) + j * j;
            };

            for (; que.size() >= 2 and $(que[0]) >= $(que[1]); que.pop_front());

            dp[i][j] = std::min(dp[i - 1][j], $(que.front()));
        }

        bfs(dp[i], std::views::iota(int64(1), n + 1));
    }

    for (int64 i = 1; i <= n; ++i)
    {
        std::cout << dp[k][i] << ' ';
    }

    return 0;
}
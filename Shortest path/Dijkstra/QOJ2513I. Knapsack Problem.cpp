/**
 * The 2025 ICPC Asia East Continent Online Contest (I)
 * 
 * => I. Knapsack Problem
 * 
 * -> https://qoj.ac/contest/2513/problem/14309
 * 
 * Submissions ~> https://qoj.ac/submission/2210853 By huanhuanonly
 * 
 * @b Dijkstra
 * 
 * ----April 09, 2026 [15h:56m:46s]----
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

    int n, m, V, T;
    std::cin >> n >> m >> V >> T;

    std::vector<std::vector<std::pair<int, int>>> e(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        std::cin >> u >> v >> w;

        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }

    constexpr auto inf = std::numeric_limits<int>::max() / 2;

    std::vector dis(n + 1, std::make_pair(inf, 0));
    std::vector vis(n + 1, false);

    struct item
    {
        int idx;
        int cnt;
        int cap;

        bool operator<(const item& other) const
        {
            if (cnt != other.cnt)
            {
                return cnt > other.cnt;
            }
            else
            {
                return cap < other.cap;
            }
        }
    };

    std::priority_queue<item> que;
    que.emplace(T, 1, V);

    dis[T] = {1, V};

    while (not que.empty())
    {
        auto cur = que.top();
        que.pop();

        if (vis[cur.idx])
        {
            continue;
        }

        vis[cur.idx] = true;

        for (const auto& [v, w] : e[cur.idx])
        {
            int ncnt = dis[cur.idx].first, ncap = dis[cur.idx].second - w;

            if (ncap < 0)
            {
                ++ncnt, ncap = V - w;
            }

            if (ncnt < dis[v].first or (ncnt == dis[v].first and ncap > dis[v].second))
            {
                que.emplace(v, ncnt, ncap);
                dis[v] = {ncnt, ncap};
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
        {
            std::cout << dis[i].first << ' ';
        }
        else
        {
            std::cout << -1 << ' ';
        }
    }

    std::cout.put('\n');

    return 0;
}
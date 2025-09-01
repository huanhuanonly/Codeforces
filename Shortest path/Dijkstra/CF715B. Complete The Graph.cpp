/**
 * Codeforces Round 372 (Div. 1)
 * 
 * => B. Complete The Graph ( @c 2300 )
 * 
 * -> https://codeforces.com/contest/715/problem/B
 * 
 * Submissions ~> https://codeforces.com/contest/716/submission/271853166 By huanhuanonly
 * 
 * @b Dijkstra
 * 
 * ----July 22, 2024 [11h:06m:05s]----
*/

#include <bits/stdc++.h>

using uint    = unsigned int;
using llong   = long long int;
using ullong  = unsigned long long int;
using ldouble = long double;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    ullong n, m, L, s, t;
    std::cin >> n >> m >> L >> s >> t;

    struct edge
    {
        ullong to, w;

        bool operator<(const edge& e) const
        {
            return this->w > e.w;
        }
    };

    std::vector<std::vector<edge>> e(n);

    std::stack<std::pair<int, int>, std::vector<std::pair<int, int>>> log;

    for (int i = 0; i < m; ++i)
    {
        ullong u, v, w;
        std::cin >> u >> v >> w;

        if (w)
        {
            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }
        else
        {
            log.push({u, v});
        }
    }

    constexpr ullong inf = 1000000000000000000;
    
    auto bfs = [&]() -> ullong
    {
        std::vector<ullong> dis(n, inf);
        std::vector<bool> vis(n);

        std::priority_queue<edge> que;
        que.push({s, 0});
        dis[s] = 0;
        
        while (not que.empty())
        {
            auto now = que.top();
            que.pop();

            if (vis[now.to])
                continue;
            else
                vis[now.to] = true;

            for (const auto& i : e[now.to])
            {
                ullong ndis = dis[now.to] + i.w;
                if (ndis < dis[i.to])
                {
                    dis[i.to] = ndis;
                    que.push({i.to, ndis});
                }
            }
        }

        return dis[t];
    };

    ullong res = bfs();

    if (res < L)
    {
        std::cout << "NO\n";
        return 0;
    }
    else if (res == L)
    {
        std::cout << "YES\n";
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < e[i].size(); ++j)
            {
                if (i < e[i][j].to)
                    std::cout << i << ' ' << e[i][j].to << ' ' << e[i][j].w << '\n';
            }
        }

        while (not log.empty())
        {
            std::cout << log.top().first << ' ' << log.top().second << ' ' << inf << '\n';
            log.pop();
        }

        return 0;
    }


    while (not log.empty())
    {
        e[log.top().first].push_back({static_cast<ullong>(log.top().second), 1ull});
        e[log.top().second].push_back({static_cast<ullong>(log.top().first), 1ull});

        if ((res = bfs()) > L)
        {
            log.pop();
            continue;
        }

        e[log.top().first].back().w = L - res + 1;
        e[log.top().second].back().w = L - res + 1;

        log.pop();

        int cnt = 0;

        std::cout << "YES\n";

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < e[i].size(); ++j)
            {
                if (i > e[i][j].to)
                    continue;

                std::cout << i << ' ' << e[i][j].to << ' ' << e[i][j].w << '\n';
            }
        }

        while (not log.empty())
        {
            std::cout << log.top().first << ' ' << log.top().second << ' ' << inf << '\n';
            log.pop();
        }

        return 0;
    }

    std::cout << "NO\n";
    return 0;
}
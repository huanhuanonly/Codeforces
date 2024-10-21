/**
 * => P3381 【模板】最小费用最大流
 * 
 * -> https://www.luogu.com.cn/problem/P3381
 * 
 * @b Dinic for @a Minimum-cost-maximum-flow-problems
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

    int n, m, s, t;
    std::cin >> n >> m >> s >> t;

    struct edge
    {
        int to;
        int w;
        int cost;

        int rid;
    };

    std::vector<std::vector<edge>> e(n + 1);

    auto add_edge = [&](int u, int v, int w, int cost) -> void
    {
        e[u].push_back({v, w, cost, int(e[v].size())});
        e[v].push_back({u, 0, -cost, int(e[u].size() - 1)});
    };

    for (int i = 0; i < m; ++i)
    {
        int u, v, w, c;
        std::cin >> u >> v >> w >> c;

        add_edge(u, v, w, c);
    }

    constexpr llong inf = LLONG_MAX / 2;

    std::vector<llong> dis(n + 1);
    std::vector<int> cur(n + 1);
    std::vector<bool> vis(n + 1);

    auto bfs = [&]() -> bool
    {
        std::fill(dis.begin(), dis.end(), inf);
        std::fill(cur.begin(), cur.end(), 0);

        std::queue<int> que;
        que.push(s);
        vis[s] = true;
        dis[s] = 0;

        while (not que.empty())
        {
            int u = que.front();
            que.pop();

            vis[u] = false;

            for (const auto& i : e[u])
            {
                if (i.w == 0)
                    continue;

                if (dis[u] + i.cost < dis[i.to])
                {
                    dis[i.to] = dis[u] + i.cost;

                    if (vis[i.to] == false)
                    {
                        vis[i.to] = true;
                        que.push(i.to);
                    }
                }
            }
        }

        return dis[t] != inf;
    };

    llong cost = 0;

    std::function<int(int, int)> dfs = [&](int u, int limit) -> int
    {
        if (u == t)
            return limit;

        for (int c = cur[u]; c < e[u].size(); ++c)
        {
            cur[u] = c;

            auto& i = e[u][c];

            if (i.w == 0 or dis[i.to] != dis[u] + i.cost or vis[i.to])
                continue;

            vis[i.to] = true;

            if (int flow = dfs(i.to, std::min(i.w, limit)); flow)
            {
                i.w -= flow;
                e[i.to][i.rid].w += flow;
                cost += llong(i.cost) * flow;

                return flow;
            }
            else
            {
                dis[i.to] = inf;
            }
        }

        return 0;
    };

    int maxflow = 0;
    int flow;

    while (bfs())
    {
        while (flow = dfs(s, INT_MAX))
        {
            maxflow += flow;
            vis.assign(n + 1, false);
        }
        vis.assign(n + 1, false);
    }

    std::cout << maxflow << ' ' << cost;

    return 0;
}
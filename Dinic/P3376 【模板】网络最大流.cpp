/**
 * => P3376 【模板】网络最大流
 * 
 * -> https://www.luogu.com.cn/problem/P3376
 * 
 * @b Dinic for @a Netword-flow-problems
 * 
 * @see also https://www.luogu.com.cn/article/mdxzcolz
 * @see also https://www.bilibili.com/video/BV1j64y1R7yK/?share_source=copy_web&vd_source=732393e31697536fd95455eba7a2b048
 * @see also https://www.bilibili.com/video/av21945401/?vd_source=cd60a4f26275c444c0463c3d3af089ba
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
        int to, w, rid;
    };

    std::vector<std::vector<edge>> e(n + 1);
    std::vector<int> dis(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        std::cin >> u >> v >> w;

        e[u].push_back({v, w, int(e[v].size())});
        e[v].push_back({u, 0, int(e[u].size()) - 1});
    }

    auto bfs = [&]() -> bool
    {
        std::fill(dis.begin(), dis.end(), 0);

        std::queue<int> que;

        que.push(s);
        dis[s] = 1;

        while (not que.empty())
        {
            int u = que.front();
            que.pop();

            for (const auto& i : e[u])
            {
                if (dis[i.to] == 0 and i.w)
                {
                    dis[i.to] = dis[u] + 1;
                    que.push(i.to);
                }
            }
        }

        return dis[t];
    };

    std::function<int(int, int)> dfs = [&](int u, int limit) -> int
    {
        if (u == t)
            return limit;

        for (auto& i : e[u])
        {
            if (dis[i.to] == dis[u] + 1 and i.w)
            {
                if (int res = dfs(i.to, std::min(limit, i.w)); res)
                {
                    i.w -= res;
                    e[i.to][i.rid].w += res;
                    return res;
                }
                else
                {
                    dis[i.to] = 0;
                }
            }
        }

        return 0;
    };

    ullong maxflow = 0;
    ullong flow;

    while (bfs())
    {
        while (flow = dfs(s, INT_MAX))
            maxflow += flow;
    }

    std::cout << maxflow;

    return 0;
}
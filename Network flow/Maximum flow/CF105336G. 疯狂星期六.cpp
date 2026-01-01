/**
 * The 2024 CCPC Online Contest
 * 
 * => G. 疯狂星期六
 * 
 * -> https://codeforces.com/gym/105336/attachments
 * 
 * Submissions ~> https://codeforces.com/gym/105336/submission/283039196 By huanhuanonly
 * 
 * @b Dinic for @a Max-flow
 * 
 * ----September 26, 2024 [20h:04m:35s]----
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

    llong n, m;
    std::cin >> n >> m;

    struct edge
    {
        llong to, w, rid;
    };

    // [0] [{n}] [{m}] [{s, t}]
    std::vector<std::vector<edge>> e(1 + n + m + 2);

    const llong s = e.size() - 2, t = e.size() - 1;

    auto add_edge = [&](llong u, llong v, llong w) -> void
    {
        e[u].push_back({v, w, llong(e[v].size())});
        e[v].push_back({u, 0ll, llong(e[u].size() - 1)});
    };

    struct Data
    {
        llong a, V;
    };

    std::vector<Data> cost(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> cost[i].a >> cost[i].V;
    }

    llong sum = 0, sum_of_yyq = cost[1].V;

    for (int i = 1; i <= m; ++i)
    {
        llong x, y, W;
        std::cin >> x >> y >> W;

        if (x == 1 or y == 1)
        {
            sum_of_yyq += W;
        }

        add_edge(s, n + i, W);
        
        if (x != y)
        {
            add_edge(n + i, x, W);
            add_edge(n + i, y, W);
        }
        else
        {
            add_edge(n + i, x, W);
        }

        sum += W;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (i == 1)
        {
            add_edge(i, t, cost[i].a - cost[i].V);
        }
        else
        {
            if (std::min(sum_of_yyq, cost[1].a) - cost[i].V - 1 < 0)
            {
                std::cout << "NO\n";
                return 0;
            }

            add_edge(i, t, std::min(cost[i].a - cost[i].V, std::min(sum_of_yyq, cost[1].a) - cost[i].V - 1));
        }
    }

    std::vector<llong> cur(e.size()), layer(e.size());

    auto bfs = [&]() -> bool
    {
        std::fill(cur.begin(), cur.end(), 0);
        std::fill(layer.begin(), layer.end(), 0);

        std::queue<llong> que;
        que.push(s);

        layer[s] = 1;

        while (not que.empty())
        {
            llong now = que.front();
            que.pop();

            for (auto& i : e[now])
            {
                if (layer[i.to] == 0 and i.w)
                {
                    layer[i.to] = layer[now] + 1;
                    que.push(i.to);
                }
            }
        }

        return layer[t];
    };

    auto dfs = [&](auto& self, llong now, llong limit) -> llong
    {
        if (now == t)
        {
            return limit;
        }

        for (llong c = cur[now]; c < e[now].size(); ++c)
        {
            cur[now] = c;

            auto& i = e[now][c];

            if (layer[now] + 1 != layer[i.to] or i.w == 0)
            {
                continue;
            }

            if (llong flow = self(self, i.to, std::min(i.w, limit)); flow)
            {
                i.w -= flow;
                e[i.to][i.rid].w += flow;
                return flow;
            }
            else
            {
                layer[i.to] = 0;
            }
        }

        return 0;
    };

    constexpr llong inf = LLONG_MAX;
    llong maxflow = 0, flow;

    while (bfs())
    {
        while (flow = dfs(dfs, s, inf))
        {
            maxflow += flow;
        }
    }

    if (maxflow == sum)
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "NO\n";
    }

    return 0;
}
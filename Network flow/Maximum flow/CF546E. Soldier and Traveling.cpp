/**
 * Codeforces Round 304 (Div. 2)
 * 
 * => E. Soldier and Traveling ( @c 2100 )
 * 
 * -> https://codeforces.com/contest/546/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/546/submission/262080354 By huanhuanonly
 * 
 * @b Dinic for @a Max-flow
 * 
 * ----May 22, 2024 [11h:07m:59s]----
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

    int n, m;
    std::cin >> n >> m;

    struct edge
    {
        int to, w, rid;
        bool is_reverse;
    };

    std::vector<std::vector<edge>> e(n + n + 2 + 1);

    auto add_edge = [&](int u, int v, int w) -> void
    {
        e[u].push_back({v, w, int(e[v].size()), false});
        e[v].push_back({u, 0, int(e[u].size() - 1), true});
    };

    int s = e.size() - 1, t = e.size() - 2;

    constexpr int inf = INT_MAX / 2;

    int sum_a = 0, sum_b = 0;

    for (int i = 1; i <= n; ++i)
    {
        int w;
        std::cin >> w;

        sum_a += w;

        add_edge(s, i, w);
        add_edge(i, n + i, inf);
    }

    for (int i = n + 1; i <= n + n; ++i)
    {
        int w;
        std::cin >> w;

        sum_b += w;

        add_edge(i, t, w);
    }

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        add_edge(u, n + v, inf);
        add_edge(v, n + u, inf);
    }

    std::vector<int> layer(e.size()), cur(e.size());

    auto bfs = [&]() -> bool
    {
        std::fill(layer.begin(), layer.end(), 0);
        std::fill(cur.begin(), cur.end(), 0);

        std::queue<int> que;
        que.push(s);
        layer[s] = 1;

        while (not que.empty())
        {
            int u = que.front();
            que.pop();

            for (const auto& i : e[u])
            {
                if (i.w == 0 or layer[i.to])
                    continue;

                layer[i.to] = layer[u] + 1;
                que.push(i.to);
            }
        }

        return layer[t];
    };

    std::function<int(int, int)> dfs = [&](int u, int limit) -> int
    {
        if (u == t)
            return limit;

        for (int c = cur[u]; c < e[u].size(); ++c)
        {
            cur[u] = c;

            auto& i = e[u][c];

            if (i.w == 0 or layer[i.to] != layer[u] + 1)
                continue;

            if (int flow = dfs(i.to, std::min(i.w, limit)); flow)
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

    int maxflow = 0, flow;

    while (bfs())
    {
        while (flow = dfs(s, inf))
        {
            maxflow += flow;
        }
    }

    if (maxflow != sum_a or sum_a != sum_b)
    {
        std::cout << "NO\n";
        return 0;
    }

    std::cout << "YES\n";

    for (int i = 1; i <= n; ++i)
    {
        std::vector<int> ans(n);

        for (const auto& u : e[i])
        {
            if (u.is_reverse)
                continue;

            ans[u.to - n - 1] = e[u.to][u.rid].w;
        }

        for (const auto& j : ans)
            std::cout << j << ' ';

        std::cout.put('\n');
    }

    return 0;
}
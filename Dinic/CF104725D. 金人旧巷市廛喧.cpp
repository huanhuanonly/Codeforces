/**
 * 2023年中国大学生程序设计竞赛女生专场
 * 
 * => D. 金人旧巷市廛喧
 * 
 * -> https://codeforces.com/gym/104725/problem/D
 * 
 * @b Dinic for @a Maximum-cost-flow
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

    int n, m, k;
    std::cin >> n >> m >> k;

    struct edge
    {
        int to, w, cost, rid;
    };

    std::vector<std::vector<edge>> e(1 + n * m * 2 + 2);

    int s = e.size() - 1, t = s - 1;

    auto add_edge = [&](int u, int v, int w, int cost) -> void
    {
        e[u].push_back({v, w, cost, int(e[v].size())});
        e[v].push_back({u, 0, -cost, int(e[u].size() - 1)});
    };

    auto id = [&](int x, int y) -> int
    {
        return x * m + y + 1;
    };

    int cost = 0;

    std::vector<std::vector<int>> mp(n, std::vector<int>(m));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> mp[i][j];

    constexpr std::pair<int, int> d[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (mp[i][j] == -1)
                continue;

            add_edge(id(i, j), n * m + id(i, j), 1, mp[i][j]);

            for (const auto& [dx, dy] : d)
            {
                if (i + dx >= 0 and i + dx < n and j + dy >= 0 and j + dy < m and mp[i + dx][j + dy] != -1)
                {
                    add_edge(n * m + id(i, j), id(i + dx, j + dy), 1, -1);
                }
            }
        }
    }

    for (int i = 0; i < k; ++i)
    {
        int x, y;
        std::cin >> x >> y;

        add_edge(s, id(x - 1, y - 1), 1, -1);
    }

    for (int i = 0; i < k; ++i)
    {
        int x, y;
        std::cin >> x >> y;

        add_edge(n * m + id(x - 1, y - 1), t, 1, 100);
    }

    constexpr int inf = INT_MAX / 2;

    std::vector<int> dis(e.size(), -inf), cur(e.size());
    std::vector<bool> vis(e.size());

    auto bfs = [&]() -> bool
    {
        std::fill(dis.begin(), dis.end(), -inf);
        std::fill(cur.begin(), cur.end(), 0);

        std::queue<int> que;
        que.push(s);
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

                if (dis[u] + i.cost > dis[i.to])
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

        // The only difference between max-cost flow and max-cost max-flow
        return dis[t] >= 0;
    };

    std::function<int(int, int)> dfs = [&](int u, int limit) -> int
    {
        if (u == t)
            return limit;

        for (int c = cur[u]; c < e[u].size(); ++c)
        {
            cur[u] = c;
            auto& i = e[u][c];

            if (i.w == 0 or vis[i.to] or dis[i.to] != dis[u] + i.cost)
                continue;

            vis[i.to] = true;

            if (int flow = dfs(i.to, std::min(i.w, limit)); flow)
            {
                i.w -= flow;
                e[i.to][i.rid].w += flow;
                cost += flow * i.cost;
                return flow;
            }
            else
            {
                dis[i.to] = -inf;
            }
        }

        return 0;
    };

    while (bfs())
    {
        while (dfs(s, inf))
        {
            vis.assign(vis.size(), false);
        }
        vis.assign(vis.size(), false);
    }

    std::cout << cost;

    return 0;
}
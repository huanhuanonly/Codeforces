/**
 * Educational Codeforces Round 160 (Rated for Div. 2)
 * 
 * => E. Matrix Problem ( @c 2400 )
 * 
 * -> https://codeforces.com/problemset/problem/1913/E
 * 
 * Submissions ~> https://codeforces.com/contest/1913/submission/291526012 By huanhuanonly
 * 
 * @b Dinic for @a Minimum-cost-maximum-flow-problem
 * 
 * ----November 15, 2024 [13h:06m:47s]----
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

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    uint32 n, m;
    std::cin >> n >> m;

    std::vector<std::vector<uint32>> matrix(n + 1, std::vector<uint32>(m + 1));

    for (uint32 i = 1; i <= n; ++i)
    {
        for (uint32 j = 1; j <= m; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<uint32> a(n + 1), b(m + 1);

    for (uint32& i : a | std::views::drop(1))
    {
        std::cin >> i;
    }

    for (uint32& i : b | std::views::drop(1))
    {
        std::cin >> i;
    }

    struct edge
    {
        int32 to, cap, cost, rid;
    };

    std::vector<std::vector<edge>> e(1 + n + m + 1);

    uint32 s = 0, t = e.size() - 1;

    auto add_edge = [&](int32 from, int32 to, int32 flow, int32 cost) -> void
    {
        e[from].push_back({to, flow, cost, static_cast<int32>(e[to].size())});
        e[to].push_back({from, 0, -cost, static_cast<int32>(e[from].size() - 1)});
    };

    auto row = [&](uint32 i) constexpr -> uint32
    {
        return i;
    };

    auto col = [&](uint32 i) constexpr -> uint32
    {
        return n + i;
    };

    constexpr int32 inf = std::numeric_limits<int32>::max() / 2;

    int32 cost = 0;

    for (uint32 i = 1; i <= n; ++i)
    {
        add_edge(s, row(i), a[i], 0);

        for (uint32 j = 1; j <= m; ++j)
        {
            if (matrix[i][j] == 1)
            {
                ++cost;
                add_edge(row(i), col(j), 1, -1);
            }
            else
            {
                add_edge(row(i), col(j), 1, 1);
            }
        }
    }

    for (uint32 j = 1; j <= m; ++j)
    {
        add_edge(col(j), t, b[j], 0);
    }

    std::vector<int32> dis(e.size());
    std::vector<int32> current(e.size());
    std::vector<uint32> count(e.size());
    std::vector<bool> vis(e.size());

    auto bfs = [&]() -> bool
    {
        std::fill(dis.begin(), dis.end(), inf);
        std::fill(current.begin(), current.end(), 0);
        std::fill(count.begin(), count.end(), 0);

        std::queue<uint32> que;
        que.push(s);
        vis[s] = true;
        count[s] = 1;
        dis[s] = 0;

        while (not que.empty())
        {
            uint32 u = que.front();
            que.pop();

            vis[u] = false;

            for (const auto& i : e[u])
            {
                if (i.cap == 0)
                {
                    continue;
                }

                if (dis[u] + i.cost < dis[i.to])
                {
                    dis[i.to] = dis[u] + i.cost;

                    if (vis[i.to] == false)
                    {
                        vis[i.to] = true;

                        if (++count[i.to] >= e.size())
                        {
                            throw std::exception();
                        }

                        que.push(i.to);
                    }
                }
            }
        }

        return dis[t] != inf;
    };

    auto dfs = [&](auto& dfs, int32 u, int32 limit) -> int32
    {
        if (u == t)
        {
            return limit;
        }

        vis[u] = true;

        for (int32 cur = current[u]; cur < e[u].size(); ++cur)
        {
            current[u] = cur;

            auto& i = e[u][cur];

            if (i.cap == 0 or dis[i.to] != dis[u] + i.cost or vis[i.to])
            {
                continue;
            }

            if (int32 flow = dfs(dfs, i.to, std::min(i.cap, limit)); flow)
            {
                i.cap -= flow;
                e[i.to][i.rid].cap += flow;
                cost += i.cost * flow;

                vis[u] = false;
                return flow;
            }
            else
            {
                dis[i.to] = inf;
            }
        }

        vis[u] = false;
        return 0;
    };

    bool exist = true;

    try
    {
        while (bfs())
        {
            while (dfs(dfs, s, inf))
            { }
        }
    }
    catch (...)
    {
        exist = false;
        goto done;
    }

    {
        for (const auto& i : e[s])
        {
            if (i.cap)
            {
                exist = false;
                break;
            }
        }

        for (const auto& i : e[t])
        {
            if (e[i.to][i.rid].cap)
            {
                exist = false;
                break;
            }
        }
    }

done:
    if (exist)
        std::cout << cost;
    else
        std::cout << -1;

    return 0;
}

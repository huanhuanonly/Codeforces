/**
 * Educational Codeforces Round 171 (Rated for Div. 2)
 * 
 * => E. Best Subsequence ( @c 2500 )
 * 
 * -> https://codeforces.com/problemset/problem/2026/E
 * 
 * Submissions ~> https://codeforces.com/contest/2026/submission/291307999 By huanhuanonly
 * 
 * @b Dinic for @a Min-Cut
 * 
 * ----November 13, 2024 [19h:24m:04s]----
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

    uint32 _;
    std::cin >> _;

    while (_--)
    {
        uint32 n;
        std::cin >> n;

        std::vector<uint64> v(1 + n);

        for (uint64& i : v | std::views::drop(1))
        {
            std::cin >> i;
        }

        struct edge
        {
            uint32 to, cap, rid;
        };

        constexpr uint32 inf = std::numeric_limits<uint32>::max();

        std::vector<std::vector<edge>> e(1 + n + 64 + 2);

        auto add_edge = [&](uint32 from, uint32 to, uint32 flow) -> void
        {
            e[from].push_back({to, flow, static_cast<uint32>(e[to].size())});
            e[to].push_back({from, 0, static_cast<uint32>(e[from].size() - 1)});
        };

        uint32 s = e.size() - 1, t = e.size() - 2;

        for (uint32 i = 1; i <= n; ++i)
        {
            add_edge(s, i, 1);

            for (uint64 k = 0; k < 64; ++k)
            {
                if ((v[i] >> k) & 1)
                {
                    add_edge(i, n + 1 + k, inf);
                }
            }
        }

        for (uint32 i = 1; i <= 64; ++i)
        {
            add_edge(n + i, t, 1);
        }

        std::vector<uint32> layer(e.size());
        std::vector<uint32> current(e.size());

        auto bfs = [&]() -> bool
        {
            std::fill(layer.begin(), layer.end(), 0);
            std::fill(current.begin(), current.end(), 0);

            std::queue<uint32> que;
            que.push(s);
            layer[s] = 1;

            while (not que.empty())
            {
                uint32 u = que.front();
                que.pop();

                for (const auto& i : e[u])
                {
                    if (i.cap == 0 or layer[i.to])
                    {
                        continue;
                    }

                    layer[i.to] = layer[u] + 1;
                    que.push(i.to);
                }
            }

            return static_cast<bool>(layer[t]);
        };

        auto dfs = [&](auto& dfs, uint32 u, uint32 limit) -> uint32
        {
            if (u == t)
            {
                return limit;
            }

            for (uint32 cur = current[u]; cur < e[u].size(); ++cur)
            {
                current[u] = cur;
                
                auto& i = e[u][cur];

                if (i.cap == 0 or layer[i.to] != layer[u] + 1)
                {
                    continue;
                }

                if (uint32 flow = dfs(dfs, i.to, std::min(limit, i.cap)); flow)
                {
                    i.cap -= flow;
                    e[i.to][i.rid].cap += flow;
                    return flow;
                }
                else
                {
                    layer[i.to] = 0;
                }
            }

            return 0;
        };

        uint32 maxflow = 0, flow;
        
        while (bfs())
        {
            while (flow = dfs(dfs, s, inf))
            {
                maxflow += flow;
            }
        }

        std::cout << n - maxflow << '\n';
    }

    return 0;
}
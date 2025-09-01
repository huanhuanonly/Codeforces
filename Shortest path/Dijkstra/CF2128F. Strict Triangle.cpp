/**
 * Codeforces Round 1039 (Div. 2)
 * 
 * => F. Strict Triangle ( @c 3200 )
 * 
 * -> https://codeforces.com/contest/2128/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/2128/submission/331613082 By huanhuanonly
 * 
 * @b Dijkstra
 * 
 * ----July 30, 2025 [23h:01m:13s]----
*/

/// @brief This is an @c interesting problem!

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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, m, k;
        std::cin >> n >> m >> k;

        struct edge
        {
            int to, l, r;
        };

        std::vector<std::vector<edge>> e(n + 1);

        for (int i = 0; i < m; ++i)
        {
            int u, v, l, r;
            std::cin >> u >> v >> l >> r;

            e[u].push_back({v, l, r});
            e[v].push_back({u, l, r});
        }

        constexpr int64 inf = std::numeric_limits<int64>::max() / 3;
        
        auto bfs_from = [&](int start) -> std::vector<int64>
        {
            std::vector<int64> dis(n + 1, inf);
            std::vector<bool> vis(n + 1);

            struct item
            {
                int point;
                uint64 dis;
                
                bool operator<(const item& other) const noexcept
                {
                    return dis > other.dis;
                }
            };

            std::priority_queue<item> que;
            
            que.push({start, 0});
            dis[start] = 0;

            while (not que.empty())
            {
                auto [cpoint, cdis] = que.top();
                que.pop();

                if (vis[cpoint])
                {
                    continue;
                }

                vis[cpoint] = true;

                for (const auto& i : e[cpoint])
                {
                    if (uint64 ndis = dis[cpoint] + i.r; ndis < dis[i.to])
                    {
                        dis[i.to] = ndis;
                        que.push({i.to, ndis});
                    }
                }
            }

            return dis;
        };

        auto dis_from_k = bfs_from(k);

        auto get_remain = [&]() -> int64
        {
            std::vector<int64> remain(n + 1, -inf);
            std::vector<bool> vis(n + 1);

            struct item
            {
                int point;
                int64 remain;
                
                bool operator<(const item& other) const noexcept
                {
                    return remain < other.remain;
                }
            };

            std::priority_queue<item> que;
            
            que.push({1, 0});
            remain[1] = dis_from_k[1];

            while (not que.empty())
            {
                auto [cpoint, cremain] = que.top();
                que.pop();

                if (vis[cpoint])
                {
                    continue;
                }

                vis[cpoint] = true;

                for (const auto& i : e[cpoint])
                {
                    if (int64 nremain = std::min(remain[cpoint] - i.l, dis_from_k[i.to]); nremain > remain[i.to] and nremain + dis_from_k[i.to] > 0)
                    {
                        remain[i.to] = nremain;
                        que.push({i.to, nremain});
                    }
                }
            }

            return remain[n];
        };

        if (get_remain() + dis_from_k[n] > 0)
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}
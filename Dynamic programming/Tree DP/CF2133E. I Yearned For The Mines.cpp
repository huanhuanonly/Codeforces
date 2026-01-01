/**
 * Codeforces Round 1044 (Div. 2)
 * 
 * => E. I Yearned For The Mines ( @c 2500 )
 * 
 * -> https://codeforces.com/contest/2133/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2133/submission/335543208 By huanhuanonly
 * 
 * @b Tree-DP
 * 
 * ----August 26, 2025 [12h:22m:13s]----
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

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        std::vector<std::vector<int>> e(n + 1);

        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            e[u].push_back(v);
            e[v].push_back(u);
        }

        std::vector<std::array<int, 3>> dp(n + 1);
        std::vector<std::array<int, 3>> from(n + 1);

        auto dfs = [&](const auto& self, int u, int fa) -> void
        {
            dp[u][1] = 1;

            if (e[u].size() == 1 and e[u][0] == fa)
            {
                return;
            }

            auto condition = [fa](int i) -> bool
            {
                return i != fa;
            };

            for (int i : e[u] | std::views::filter(condition))
            {
                self(self, i, u);
                
                dp[u][0] += dp[i][1];
                dp[u][1] += std::min(dp[i][1], dp[i][2]);
                dp[u][2] += dp[i][1];

                from[i][0] = 1;
                from[i][1] = (dp[i][1] < dp[i][2] ? 1 : 2);
                from[i][2] = 1;
            }
            
            constexpr int inf = std::numeric_limits<int>::max();

            std::pair<int, int> min1{inf, 0};
            std::pair<int, int> min2{inf, 0};

            for (int i : e[u] | std::views::filter(condition))
            {
                min1 = std::min(min1, {dp[u][0] - dp[i][1] + dp[i][0], i});
            }

            if (min1.first < dp[u][0])
            {
                dp[u][0] = min1.first;
                from[min1.second][0] = 0;

                for (int i : e[u] | std::views::filter(condition))
                {
                    if (i != min1.second)
                    {
                        min2 = std::min(min2, {min1.first - dp[i][1] + dp[i][0], i});
                    }
                }
                
                from[min1.second][2] = 0;
    
                if (min2.first != inf and min2.first < min1.first)
                {
                    dp[u][2] = min2.first;
                    from[min2.second][2] = 0;
                }
                else
                {
                    dp[u][2] = dp[u][0];
                }
            }
        };

        std::set<int> destroyed;

        auto find = [&](const auto& self, int u, int fa, int c) -> void
        {
            if (c == 1)
            {
                destroyed.insert(u);
            }

            for (int i : e[u] | std::views::filter([fa](int i) -> bool { return i != fa; }))
            {
                self(self, i, u, from[i][c]);
            }
        };

        dfs(dfs, 1, 0);
        find(find, 1, 0, dp[1][1] < dp[1][2] ? 1 : 2);

        std::cout << std::min(dp[1][1], dp[1][2]) + n << '\n';

        for (int i : destroyed)
        {
            std::cout << 2 << ' ' << i << '\n';
        }

        std::vector<int> spoints;
        spoints.reserve(n);

        for (int i = 1; i <= n; ++i)
        {
            int cnt = 0;

            if (not destroyed.contains(i))
            {
                for (int u : e[i])
                {
                    cnt += not destroyed.contains(u);
                }
            }

            if (cnt <= 1)
            {
                spoints.push_back(i);
            }
        }

        std::vector<bool> vis(n + 1);

        auto output = [&](const auto& self, int u, int fa) -> void
        {
            vis[u] = true;
            std::cout << 1 << ' ' << u << '\n';

            for (int i : e[u] | std::views::filter([&](int i) -> bool { return i != fa and not destroyed.contains(i); }))
            {
                self(self, i, u);
            }
        };

        for (int i : spoints)
        {
            if (not vis[i])
            {
                if (destroyed.contains(i))
                {
                    std::cout << 1 << ' ' << i << '\n';
                }
                else
                {
                    output(output, i, 0);
                }
            }
        }
    }

    return 0;
}
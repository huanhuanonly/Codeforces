/**
 * ContestTitle
 * 
 * => P12136 [蓝桥杯 2025 省 B] 生产车间 ( @c 普及+/提高 )
 * 
 * -> https://www.luogu.com.cn/problem/P12136
 * 
 * Submissions ~> https://www.luogu.com.cn/record/215810528 By huanhuanonly
 * 
 * @b DP for @a Knapsack-Problem-On-Tree
 * 
 * ----May 03, 2025 [17h:45m:41s]----
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

    int n;
    std::cin >> n;

    std::vector<int> v(n + 1);
    
    for (auto& i : v | std::views::drop(1))
    {
        std::cin >> i;
    }

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    using bs = std::bitset<1000 + 1>;

    std::vector dp(n + 1, bs());

    auto dfs = [&](const auto& self, int u, int fa) -> void
    {
        bool has = false;

        for (const auto& next : e[u] | std::views::filter([&](int i) -> bool { return i != fa; }))
        {
            self(self, next, u);
            
            for (int i = dp[next]._Find_first(); i <= v[next]; i = dp[next]._Find_next(i))
            {
                dp[u] |= dp[u] << i;
            }
            
            dp[u] |= dp[next] & bs(std::string(v[next] + 1, '1'));

            has = true;
        }

        if (not has)
        {
            dp[u][v[u]] = true;
        }
    };

    dfs(dfs, 1, 1);

    int ans = 0;

    for (int i = dp[1]._Find_first(); i <= v[1]; i = dp[1]._Find_next(i))
    {
        ans = i;
    }

    std::cout << ans;

    return 0;
}
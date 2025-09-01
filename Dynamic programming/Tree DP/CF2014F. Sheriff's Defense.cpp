/**
 * Codeforces Round 974 (Div. 3)
 * 
 * => F. Sheriff's Defense ( @c 2000 )
 * 
 * -> https://codeforces.com/contest/2014/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/2014/submission/282773243 By huanhuanonly
 * 
 * @b Tree-DP
 * 
 * ----September 26, 2024 [20h:47m:52s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        llong n, c;
        std::cin >> n >> c;

        std::vector<llong> v(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
        }

        std::vector<std::vector<int>> e(n + 1);

        for (int i = 1; i <= n - 1; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            e[u].push_back(v);
            e[v].push_back(u);
        }

        std::vector<std::vector<llong>> dp(n + 1, std::vector<llong>(2));

        auto dfs = [&](auto& self, int now, int fa) -> void
        {
            dp[now][1] = v[now];
            
            for (const auto& i : e[now])
            {
                if (i == fa)
                {
                    continue;
                }

                self(self, i, now);

                dp[now][0] += std::max(dp[i][0], dp[i][1]);
                dp[now][1] += std::max(dp[i][0], dp[i][1] - c - c);
            }
        };

        dfs(dfs, 1, 0);

        std::cout << std::max(dp[1][0], dp[1][1]) << '\n';
    }

    return 0;
}
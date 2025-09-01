/**
 * Codeforces Round 1029 (Div. 3)
 * 
 * => F. Wildflower ( @c 1800 )
 * 
 * -> https://codeforces.com/contest/2117/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/2117/submission/323854434 By huanhuanonly
 * 
 * @b Classification-discussion, @b Combinatorics and @b Dfs
 * 
 * ----June 11, 2025 [14h:17m:38s]----
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

        std::vector<int> t(n + 1);

        auto dfs = [&](const auto& self, int u, int fa, int depth) -> void
        {
            ++t[depth];

            for (int i : e[u] | std::views::filter([&](int i) -> bool { return i != fa; }))
            {
                self(self, i, u, depth + 1);
            }
        };

        dfs(dfs, 1, 0, 1);

        constexpr uint64 mod = 1e9 + 7;

        std::vector<uint64> dp(n + 1);

        dp[0] = 1;
        dp[1] = 2;

        uint64 last = dp[1];

        bool yes = (std::count_if(e.begin() + 2, e.end(), [](const auto& es) -> bool { return es.size() == 1; }) <= 2);

        uint64 ans = 0;

        for (int i = 2; i <= n; ++i)
        {
            if (t[i] == 0)
            {
                ans = dp[i - 1];
                break;
            }

            if (t[i - 1] == 1)
            {
                dp[i] = dp[i - 1] * 2 % mod;
            }
            else
            {
                dp[i] = dp[i - 1];

                if (t[i] == 1)
                {
                    dp[i] = (dp[i] * 2 + mod - last) % mod;
                }
            }

            if (t[i] == 1)
            {
                last = dp[i];
            }
        }

        if (yes)
            std::cout << std::max(ans, dp.back()) << '\n';
        else
            std::cout << 0 << '\n';
    }

    return 0;
}
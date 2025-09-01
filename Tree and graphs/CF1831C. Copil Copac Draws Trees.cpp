/**
 * Codeforces Round 875 (Div. 2)
 * 
 * => C. Copil Copac Draws Trees ( @c 1400 )
 * 
 * -> https://codeforces.com/problemset/problem/1831/C
 * 
 * Submissions ~> https://codeforces.com/contest/1831/submission/323773033 By huanhuanonly
 * 
 * @b Dfs
 * 
 * ----June 10, 2025 [20h:54m:07s]----
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

        struct edge
        {
            int to, num;
        };
        std::vector<std::vector<edge>> e(n + 1);

        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            e[u].push_back({v, i});
            e[v].push_back({u, i});
        }

        int ans = 0;

        auto dfs = [&](const auto& self, int u, int fa, int last, int sum) -> void
        {
            ans = std::max(ans, sum);

            for (auto& [i, num] : e[u])
            {
                if (i == fa)
                {
                    continue;
                }

                self(self, i, u, num, sum + (num < last));
            }
        };

        dfs(dfs, 1, 0, 0, 1);

        std::cout << ans << '\n';
    }

    return 0;
}
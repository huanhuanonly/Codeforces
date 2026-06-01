/**
 * 2025 National Invitational of CCPC (Fujian), The 12th Fujian Collegiate Programming Contest
 *
 * => K. VERTeX
 *
 * -> https://codeforces.com/gym/105977/problem/K
 *
 * Submissions ~> https://codeforces.com/gym/105977/submission/372714615 By huanhuanonly
 *
 * @b Constructive and @b Trees
 *
 * ----April 28, 2026 [00h:11m:50s]----
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

#if defined(__SIZEOF_INT128__)
using int128 = __int128;
using uint128 = unsigned __int128;
#endif

using real32 = float;
using real64 = double;

#if defined(__SIZEOF_FLOAT80__)
using real80 = __float80;
#endif

#if defined(__SIZEOF_FLOAT128__)
using real128 = __float128;
#endif

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n;
    std::cin >> n;

    std::vector<std::vector<std::pair<int64, int64>>> e(n + 1);

    for (int i = 1; i <= n - 1; ++i)
    {
        int64 u, v, w;
        std::cin >> u >> v >> w;

        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }

    std::array<std::vector<std::pair<int64, int64>>, 2> d;

    auto dfs = [&](const auto& self, int u, int fa, int lay, int64 val) -> void
    {
        d[lay].emplace_back(u, val);

        for (const auto& [v, w] : e[u])
        {
            if (v != fa)
            {
                self(self, v, u, not lay, w - val);
            }
        }
    };

    dfs(dfs, 1, 0, 0, 0);

    std::vector<int64> ans(n + 1);

    int64 min0 = std::ranges::min_element(d[0], {}, &std::pair<int64, int64>::second)->second;
    int64 min1 = std::ranges::min_element(d[1], {}, &std::pair<int64, int64>::second)->second;

    int64 add0 = 0, add1 = 0;

    if (min0 > 1)
    {
        add0 -= min0 - 1;
        add1 += min0 - 1;
    }
    else if (min1 > 1)
    {
        add1 -= min1 - 1;
        add0 += min1 - 1;
    }

    if (min0 + add0 <= 0 or min1 + add1 <= 0)
    {
        std::cout << "NO\n";
        return 0;
    }

    std::cout << "YES\n";

    for (const auto& u : d[0])
    {
        ans[u.first] = u.second + add0;
    }

    for (const auto& u : d[1])
    {
        ans[u.first] = u.second + add1;
    }

    for (int i = 1; i <= n; ++i)
    {
        std::cout << ans[i] << ' ';
    }

    return 0;
}
/**
 * Helvetic Coding Contest 2016 online mirror (teams, unrated)
 * 
 * => C2. Brain Network (medium) ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/690/problem/C2
 * 
 * Submissions ~> https://codeforces.com/contest/690/submission/327392822 By huanhuanonly
 * 
 * @b Dfs to find @a Tree-diameter
 * 
 * ----July 04, 2025 [21h:58m:23s]----
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

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    auto dfs = [&](const auto& self, int u, int fa, int dis) -> std::pair<int, int>
    {
        auto max = std::make_pair(dis, u);

        for (int i : e[u] | std::views::filter([&](int i) -> bool { return i != fa; }))
        {
            max = std::max(max, self(self, i, u, dis + 1));
        }
        
        return max;
    };

    std::cout << dfs(dfs, dfs(dfs, 1, 0, 0).second, 0, 0).first;

    return 0;
}
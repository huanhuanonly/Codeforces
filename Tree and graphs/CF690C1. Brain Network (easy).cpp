/**
 * Helvetic Coding Contest 2016 online mirror (teams, unrated)
 * 
 * => C1. Brain Network (easy) ( @c 1300 )
 * 
 * -> https://codeforces.com/contest/690/problem/C1
 * 
 * Submissions ~> https://codeforces.com/contest/690/submission/327394401 By huanhuanonly
 * 
 * @b Dfs to check whether the graph is a tree
 * 
 * ----July 04, 2025 [22h:08m:39s]----
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

    std::vector<bool> vis(n + 1);

    auto dfs = [&](const auto& self, int u, int fa) -> bool
    {
        if (vis[u])
        {
            return false;
        }

        vis[u] = true;

        for (int i : e[u] | std::views::filter([&](int i) -> bool { return i != fa; }))
        {
            if (not self(self, i, u))
            {
                return false;
            }
        }

        return true;
    };

    std::cout << (dfs(dfs, 1, 0) and std::ranges::count(vis | std::views::drop(1), false) == 0 ? "yes" : "no");

    return 0;
}
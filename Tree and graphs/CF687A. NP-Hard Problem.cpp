/**
 * Codeforces Round 360 (Div. 1)
 * 
 * => A. NP-Hard Problem ( @c 1500 )
 * 
 * -> https://codeforces.com/problemset/problem/687/A
 * 
 * Submissions ~> https://codeforces.com/contest/687/submission/319355797 By huanhuanonly
 * 
 * @b Dfs
 * 
 * ----May 12, 2025 [17h:40m:58s]----
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

    std::vector<bool> color(n + 1);
    std::vector<bool> vis(n + 1);

    bool yes = true;

    auto dfs = [&](const auto& self, int u, bool c)
    {
        if (vis[u])
        {
            yes = yes and color[u] == c;
            return;
        }

        vis[u] = true;
        color[u] = c;

        for (int i : e[u])
        {
            self(self, i, not c);
        }
    };

    for (int i = 1; i <= n; ++i)
    {
        if (not vis[i])
        {
            dfs(dfs, i, false);
        }
    }

    if (yes)
    {
        std::vector<int> ans;

        for (int i = 1; i <= n; ++i)
        {
            if (color[i] == false)
            {
                ans.push_back(i);
            }
        }

        std::cout << ans.size() << '\n';
        std::ranges::for_each(ans, [](int i) { std::cout << i << ' '; });
        std::cout.put('\n');

        ans.clear();

        for (int i = 1; i <= n; ++i)
        {
            if (color[i] == true)
            {
                ans.push_back(i);
            }
        }

        std::cout << ans.size() << '\n';
        std::ranges::for_each(ans, [](int i) { std::cout << i << ' '; });
        std::cout.put('\n');
    }
    else
    {
        std::cout << -1 << '\n';
    }

    return 0;
}
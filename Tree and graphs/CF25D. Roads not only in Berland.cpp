/**
 * Codeforces Beta Round 25 (Div. 2 Only)
 * 
 * => D. Roads not only in Berland ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/25/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/25/submission/351538886 By huanhuanonly
 * 
 * @b Dfs on ( @a Graphs | @a Trees )
 * 
 * ----December 02, 2025 [11h:00m:33s]----
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

    std::vector<bool> vis(n + 1);

    std::set<std::pair<int, int>> removed, inserted;

    auto dfs = [&](const auto& self, int u, int fa) -> void
    {
        vis[u] = true;

        for (const int i : e[u] | std::views::filter([fa](int i) -> bool { return i != fa; }))
        {
            if (vis[i])
            {
                removed.insert(std::minmax(u, i));
            }
            else
            {
                self(self, i, u);
            }
        }
    };

    for (int i = 1; i <= n; ++i)
    {
        if (not vis[i])
        {
            dfs(dfs, i, 0);
            
            if (i != 1)
            {
                inserted.emplace(1, i);
            }
        }
    }

    assert(removed.size() == inserted.size());

    std::cout << removed.size() << '\n';

    for (auto it1 = removed.begin(), it2 = inserted.begin(); it1 != removed.end(); ++it1, ++it2)
    {
        const auto& [i, j] = *it1;
        const auto& [u, v] = *it2;

        std::cout << i << ' ' << j << ' ' << u << ' ' << v << '\n';
    }

    return 0;
}
/**
 * Codeforces Beta Round 83 (Div. 1 Only)
 * 
 * => A. Dorm Water Supply ( @c 1400 )
 * 
 * -> https://codeforces.com/contest/107/problem/A
 * 
 * Submissions ~> https://codeforces.com/contest/107/submission/327340428 By huanhuanonly
 * 
 * @b Dfs
 * 
 * ----July 04, 2025 [15h:27m:44s]----
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

    struct edge
    {
        int to, w;
    };

    std::vector<std::vector<edge>> e(n + 1);

    std::vector<int> in(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        std::cin >> u >> v >> w;

        e[u].push_back({v, w});
        ++in[v];
    }

    auto dfs = [&](const auto& self, int u, int* const endpoint) -> int
    {
        if (e[u].empty())
        {
            *endpoint = u;
            return std::numeric_limits<int>::max();
        }
        else for (const auto& [i, w] : e[u])
        {
            return std::min(self(self, i, endpoint), w);
        }

        return std::numeric_limits<int>::max();
    };

    std::vector<std::tuple<int, int, int>> ans;

    for (int i = 1; i <= n; ++i)
    {
        if (in[i] == 0 and e[i].size() == 1)
        {
            int to;
            int min = dfs(dfs, i, &to);

            ans.push_back({i, to, min});
        }
    }

    std::cout << ans.size() << '\n';

    for (const auto& [s, t, min] : ans)
    {
        std::cout << s << ' ' << t << ' ' << min << '\n';
    }

    return 0;
}
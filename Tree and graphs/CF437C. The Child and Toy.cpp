/**
 * Codeforces Round 250 (Div. 2)
 * 
 * => C. The Child and Toy ( @c 1400 )
 * 
 * -> https://codeforces.com/contest/437/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/437/submission/338929295 By huanhuanonly
 * 
 * @b Graphs
 * 
 * ----September 16, 2025 [21h:44m:36s]----
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

    std::vector<int> v(n + 1);
    std::vector<std::pair<int, int>> s(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
        s[i] = {v[i], i};
    }

    std::vector<std::vector<int>> e(n + 1);
    std::vector<bool> vis(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    uint64 sum = 0;

    std::ranges::sort(s | std::views::drop(1), std::ranges::greater());

    for (int i = 1; i <= n; ++i)
    {
        vis[s[i].second] = true;

        for (int u : e[s[i].second] | std::views::filter([&](int u) -> bool { return not vis[u]; }))
        {
            sum += v[u];
        }
    }

    std::cout << sum;

    return 0;
}
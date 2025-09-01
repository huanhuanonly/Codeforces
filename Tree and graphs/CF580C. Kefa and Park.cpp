/**
 * Codeforces Round 321 (Div. 2)
 * 
 * => C. Kefa and Park ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/580/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/580/submission/329164044 By huanhuanonly
 * 
 * @b Dfs
 * 
 * ----July 16, 2025 [16h:41m:12s]----
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

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
    }

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    int ans = 0;

    auto dfs = [&](const auto& self, int u, int fa, int cnt) -> int
    {
        if ((v[u] ? ++cnt : cnt = 0) > m)
        {
            return 0;
        }

        if (u != 1 and e[u].size() == 1)
        {
            return 1;
        }

        int sum = 0;

        for (int i : e[u] | std::views::filter([fa](int i) -> bool { return i != fa; }))
        {
            sum += self(self, i, u, cnt);
        }

        return sum;
    };

    std::cout << dfs(dfs, 1, 0, 0);

    return 0;
}
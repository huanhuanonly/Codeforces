/**
 * Технокубок 2017 - Финал (только для онсайт-финалистов)
 * 
 * => C. Andryusha and Colored Balloons ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/780/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/780/submission/328801340 By huanhuanonly
 * 
 * @b Dfs
 * 
 * ----July 13, 2025 [23h:55m:49s]----
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

    std::vector<int> colors(n + 1);

    auto dfs = [&](const auto& self, int u, int fa) -> void
    {
        int color = 0;

        for (int i : e[u] | std::views::filter([fa](int i) -> bool { return i != fa; }))
        {
            while (++color == colors[fa] or color == colors[u]);

            colors[i] = color;

            self(self, i, u);
        }
    };

    colors[1] = 1;
    dfs(dfs, 1, 0);

    std::cout << *std::ranges::max_element(colors) << '\n';
    std::ranges::for_each(colors | std::views::drop(1), [](int i) -> void { std::cout << i << ' '; });

    return 0;
}
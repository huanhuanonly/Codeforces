/**
 * Codeforces Round 428 (Div. 2)
 * 
 * => C. Journey ( @c 1500 )
 * 
 * -> https://codeforces.com/problemset/problem/839/C
 * 
 * Submissions ~> https://codeforces.com/contest/839/submission/319389079 By huanhuanonly
 * 
 * @b Dfs
 * 
 * ----May 12, 2025 [22h:11m:00s]----
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

    real128 ans = 0;

    auto dfs = [&](const auto& self, int u, int fa, int d, real128 r) -> void
    {
        for (int i : e[u] | std::views::filter([&](int i) -> bool { return i != fa; }))
        {
            self(self, i, u, d + 1, r / (e[u].size() - (u != 1)));
        }

        if (e[u].size() == (u != 1))
        {
            ans += r * d;
        }
    };

    dfs(dfs, 1, 0, 0, 1);
    
    std::cout << std::fixed << std::setprecision(12) << ans << '\n';

    return 0;
}
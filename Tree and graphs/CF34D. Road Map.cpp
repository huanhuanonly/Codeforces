/**
 * Codeforces Beta Round 34 (Div. 2)
 * 
 * => D. Road Map ( @c 1600 )
 * 
 * -> https://codeforces.com/problemset/problem/34/D
 * 
 * Submissions ~> https://codeforces.com/contest/34/submission/319277730 By huanhuanonly
 * 
 * @b Dfs
 * 
 * ----May 12, 2025 [00h:27m:06s]----
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

    int n, r1, r2;
    std::cin >> n >> r1 >> r2;

    std::vector<std::vector<int>> e(n + 1);

    for (int i : std::views::iota(1, n + 1) | std::views::filter([&](int i) -> bool { return i != r1; }))
    {
        int u;
        std::cin >> u;

        e[i].push_back(u);
        e[u].push_back(i);
    }

    std::vector<int> ans(n + 1);

    auto dfs = [&](const auto& self, int u, int fa) -> void
    {
        for (int i : e[u] | std::views::filter([&](int i) -> bool { return i != fa; }))
        {
            ans[i] = u;
            self(self, i, u);
        }
    };

    dfs(dfs, r2, 0);

    for (int i = 1; i <= n; ++i)
    {
        if (i != r2)
        {
            std::cout << ans[i] << ' ';
        }
    }

    return 0;
}
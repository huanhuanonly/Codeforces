/**
 * Codeforces Round 1027 (Div. 3)
 * 
 * => E. Kirei Attacks the Estate ( @c 1400 )
 * 
 * -> https://codeforces.com/contest/2114/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2114/submission/321481278 By huanhuanonly
 * 
 * @b Dfs
 * 
 * ----May 27, 2025 [01h:16m:12s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        std::vector<int64> a(n + 1);

        for (int64& i : a | std::views::drop(1))
        {
            std::cin >> i;
        }

        std::vector<std::vector<int>> e(n + 1);

        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            e[u].push_back(v);
            e[v].push_back(u);
        }

        std::vector<int64> ans(n + 1);

        auto dfs = [&](const auto& self, int u, int fa, int lay, std::array<int64, 2> val) -> void
        {
            val[lay] += a[u];
            val[not lay]  -= a[u];

            val[not lay] = std::max(val[not lay], 0LL);

            ans[u] = val[lay];

            for (int i : e[u] | std::views::filter([&](int i) -> bool { return i != fa; }))
            {
                self(self, i, u, not lay, val);
            }
        };

        dfs(dfs, 1, 0, 0, {0, 0});

        for (int i = 1; i <= n; ++i)
        {
            std::cout << ans[i] << " \n"[i == n];
        }
    }

    return 0;
}
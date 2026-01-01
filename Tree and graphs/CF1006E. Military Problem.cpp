/**
 * Codeforces Round 498 (Div. 3)
 * 
 * => E. Military Problem ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/1006/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/1006/submission/347423388 By huanhuanonly
 * 
 * @b Dfs on @a Trees
 * 
 * ----November 04, 2025 [23h:18m:06s]----
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

    int n, q;
    std::cin >> n >> q;

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 2, u; i <= n; ++i)
    {
        std::cin >> u;
        e[u].push_back(i);
    }

    for (int i = 1; i <= n; ++i)
    {
        std::ranges::sort(e[i]);
    }

    std::vector<int> sizes(n + 1);
    std::vector<int> list(n + 1);
    std::vector<int> pos(n + 1);

    auto dfs = [&, idx = 0](auto& self, int u) mutable -> void
    {
        sizes[u] = 1;
        list[++idx] = u;
        pos[u] = idx;

        for (int i : e[u])
        {
            self(self, i);
            sizes[u] += sizes[i];
        }
    };

    dfs(dfs, 1);

    while (q--)
    {
        int u, k;
        std::cin >> u >> k;

        if (sizes[u] < k)
        {
            std::cout << -1 << '\n';
        }
        else
        {
            std::cout << list[pos[u] + k - 1] << '\n';
        }
    }

    return 0;
}
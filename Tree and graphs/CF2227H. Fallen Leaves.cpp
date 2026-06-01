/**
 * Codeforces Round 1096 (Div. 3)
 *
 * => H. Fallen Leaves ( @c 2100 )
 *
 * -> https://codeforces.com/contest/2227/problem/H
 *
 * Submissions ~> https://codeforces.com/contest/2227/submission/373531420 By huanhuanonly
 *
 * @b Dfs on @a Trees
 *
 * ----May 05, 2026 [01h:13m:54s]----
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

#if defined(__SIZEOF_INT128__)
using int128 = __int128;
using uint128 = unsigned __int128;
#endif

using real32 = float;
using real64 = double;

#if defined(__SIZEOF_FLOAT80__)
using real80 = __float80;
#endif

#if defined(__SIZEOF_FLOAT128__)
using real128 = __float128;
#endif

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

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

        std::vector<std::vector<int>> e(n + 1);

        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            e[u].push_back(v);
            e[v].push_back(u);
        }

        std::vector<int> cnt(n + 1);
        int sum = 0;

        auto dfs = [&](const auto& self, int u, int fa) -> void
        {
            if (e[u].size() == 1)
            {
                cnt[u] = 1;
                return;
            }

            for (const auto& v : e[u])
            {
                if (v != fa)
                {
                    self(self, v, u);
                    sum += cnt[v] & 1;
                    cnt[u] += cnt[v];
                }
            }

            return;
        };

        const int root = std::ranges::find_if(e, [](const auto& i) -> bool { return i.size() > 1; }) - e.begin();

        if (dfs(dfs, root, 0); cnt[root] & 1 ^ 1)
        {
            std::cout << sum << '\n';
            continue;
        }

        int ans = sum;

        auto dfs2 = [&](const auto& self, int u, int fa, int add = 0) -> void
        {
            if (e[u].size() == 1)
            {
                ans = std::min(ans, sum + add);
                return;
            }

            for (const auto& v : e[u])
            {
                if (v != fa)
                {
                    self(self, v, u, add + (cnt[v] & 1 ? -1 : +1));
                }
            }
        };

        dfs2(dfs2, root, 0);
        std::cout << ans << '\n';
    }

    return 0;
}
/**
 * 牛客周赛 Round 144
 *
 * => F-牛魔！ ( @c 2000 )
 *
 * -> https://ac.nowcoder.com/acm/contest/134957/F
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83650624 By huanhuanonly
 *
 * @b Dfs on @a Trees
 * @b Greedy
 *
 * ----May 20, 2026 [15h:40m:28s]----
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

    int n;
    std::cin >> n;

    std::vector<int> w(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> w[i];
    }

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    std::vector<int> fa(n + 1);

    auto dfs = [&](const auto& self, int u, int depth) -> void
    {
        for (const auto& v : e[u])
        {
            if (v != fa[u])
            {
                fa[v] = u;
                self(self, v, depth + 1);
            }
        }

        if (w[u] == 0 and depth >= 2)
        {
            w[u] ^= 1;
            w[fa[u]] ^= 1;
            w[fa[fa[u]]] ^= 1;
        }
    };

    dfs(dfs, 1, 0);

    if (w[1] == 0)
    {
        for (const auto& u : e[1])
        {
            if (w[u] == 0 and e[u].size() > 1)
            {
                const auto& v = e[u][e[u][0] == 1];

                w[v] ^= 1;
                w[u] ^= 1;
                w[1] ^= 1;

                break;
            }
        }
    }

    std::cout << *std::ranges::fold_left_first(w, std::plus{}) << '\n';

    return 0;
}
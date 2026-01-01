/**
 * Educational Codeforces Round 22
 * 
 * => C. The Tag Game ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/813/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/813/submission/346556666 By huanhuanonly
 * 
 * @b Dfs on @a Trees and @b Game-theory
 * 
 * ----October 30, 2025 [11h:07m:11s]----
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

    int n, x;
    std::cin >> n >> x;

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    struct node
    {
        int parent;
        int depth, max_depth;
    };

    std::vector<node> tree(n + 1);

    auto dfs = [&](const auto& self, int u) -> void
    {
        for (int i : e[u])
        {
            if (i == tree[u].parent)
            {
                continue;
            }

            tree[i].parent = u;
            tree[i].depth = tree[i].max_depth = tree[u].depth + 1;

            self(self, i);

            tree[u].max_depth = std::max(tree[u].max_depth, tree[i].max_depth);
        }
    };

    dfs(dfs, 1);

    int ans = tree[x].max_depth;

    for (int t = x, i = 0; t != 1; t = tree[t].parent, ++i)
    {
        if (i < tree[t].depth)
        {
            ans = std::max(ans, tree[t].max_depth);
        }
    }

    std::cout << ans * 2;

    return 0;
}
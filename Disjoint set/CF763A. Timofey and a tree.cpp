/**
 * Codeforces Round 395 (Div. 1)
 * 
 * => A. Timofey and a tree ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/763/problem/A
 * 
 * Submissions ~> https://codeforces.com/contest/763/submission/351537746 By huanhuanonly
 * 
 * @b Trees and @b Disjoint-set
 * 
 * ----December 02, 2025 [10h:34m:28s]----
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

class DisjointSet
{
public:
    std::vector<int> tree, sizes;

    explicit DisjointSet(std::size_t n)
        : tree(n), sizes(n, 1)
    {
        std::iota(tree.begin(), tree.end(), 0);
    }

    int find(int u)
    {
        return tree[u] == u ? u : tree[u] = find(tree[u]);
    }

    void merge(int u, int v)
    {
        if (const int fv = find(v), fu = find(u); fv != fu)
        {
            sizes[fu] += sizes[fv];
            tree[fv] = fu;
        }
    }

    int size_of(int u)
    {
        return sizes[find(u)];
    }
};

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

    std::vector<int> c(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> c[i];
    }

    DisjointSet dsu(n + 1);

    auto dfs = [&](const auto& self, int u, int fa) -> void
    {
        for (const int i : e[u] | std::views::filter([&](int i) -> bool { return i != fa and c[i] == c[u]; }))
        {
            dsu.merge(u, i);
            self(self, i, u);
        }
    };

    for (int i = 1; i <= n; ++i)
    {
        if (dsu.size_of(i) == 1)
        {
            dfs(dfs, i, 0);
        }
    }

    bool yes = false;

    for (int u = 1; u <= n; ++u)
    {
        int cnt = dsu.size_of(u);

        for (const int i : e[u] | std::views::filter([&](int i) -> bool { return c[i] != c[u]; }))
        {
            cnt += dsu.size_of(i);
        }

        if (cnt == n)
        {
            yes = true;
            std::cout << "YES\n" << u << '\n';
            break;
        }
    }

    if (not yes)
    {
        std::cout << "NO\n";
    }

    return 0;
}
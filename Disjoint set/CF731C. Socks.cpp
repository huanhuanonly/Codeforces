/**
 * Codeforces Round 376 (Div. 2)
 * 
 * => C. Socks ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/731/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/731/submission/345433961 By huanhuanonly
 * 
 * @b Disjoint-set
 * 
 * ----October 24, 2025 [10h:54m:20s]----
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
    std::vector<int> tree;

    explicit DisjointSet(std::size_t n)
        : tree(n)
    {
        std::iota(tree.begin(), tree.end(), 0);
    }

    int find(int u)
    {
        return tree[u] == u ? u : tree[u] = find(tree[u]);
    }

    void merge(int u, int v)
    {
        tree[find(v)] = find(u);
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

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> c(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> c[i];
    }

    DisjointSet dsu(n + 1);

    for (int i = 1; i <= m; ++i)
    {
        int l, r;
        std::cin >> l >> r;

        dsu.merge(l, r);
    }

    std::map<int, std::map<int, int>> mp;

    for (int i = 1; i <= n; ++i)
    {
        ++mp[dsu.find(i)][c[i]];
    }

    int cnt = 0;

    for (const auto& [key, values] : mp)
    {
        int sum = 0;
        int max = 0;

        for (const auto& [color, count] : values)
        {
            sum += count;
            max = std::max(max, count);
        }

        cnt += sum - max;
    }

    std::cout << cnt;

    return 0;
}
/**
 * Codeforces Round 250 (Div. 2)
 * 
 * => D. The Child and Zoo ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/437/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/437/submission/339034516 By huanhuanonly
 * 
 * @b Graphs and @b Disjoint-set and @b Combinatorics
 * 
 * ----September 17, 2025 [14h:39m:00s]----
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
    std::vector<int> size;

    explicit DisjointSet(std::size_t n)
        : tree(n), size(n, 1)
    {
        std::iota(tree.begin(), tree.end(), 0);
    }

    int find(int u)
    {
        return tree[u] == u ? u : tree[u] = find(tree[u]);
    }

    void merge(int u, int v)
    {
        int fv = find(v), fu = find(u);

        if (fv == fu)
        {
            return;
        }

        size[fu] += size[fv];

        tree[fv] = fu;
    }

    int size_of(int u)
    {
        return size[find(u)];
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

    int n, m;
    std::cin >> n >> m;

    std::vector<int> v(n + 1);
    std::vector<std::pair<int, int>> s(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
        s[i] = {v[i], i};
    }

    std::ranges::sort(s, std::ranges::greater());

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    std::vector<bool> vis(n + 1);

    auto filter = std::views::filter([&](int i) -> bool { return vis[i]; });
    auto $ = [](uint64 n) -> uint64 { return n * (n - 1) / 2; };

    DisjointSet dsu(n + 1);

    uint64 sum = 0;

    for (const auto& [w, u] : s)
    {
        uint64 cnt = 1;

        std::set<int> set;

        for (int i : e[u] | filter)
        {
            if (not set.contains(dsu.find(i)))
            {
                set.insert(dsu.find(i));
                cnt += dsu.size_of(i);
            }
        }

        cnt = $(cnt) * w;

        for (int i : set)
        {
            cnt -= $(dsu.size_of(i)) * w;
            dsu.merge(u, i);
        }

        sum += cnt;

        vis[u] = true;
    }

    std::cout << std::fixed << std::setprecision(12) << static_cast<double>(sum) / $(n);

    return 0;
}
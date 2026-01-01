/**
 * Codeforces Round 479 (Div. 3)
 * 
 * => E. Cyclic Components ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/977/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/977/submission/340300929 By huanhuanonly
 * 
 * @b Disjoint-set and @b Graphs
 * 
 * ----September 25, 2025 [14h:39m:46s]----
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

    int n, m;
    std::cin >> n >> m;

    std::vector<int> d(n + 1);

    DisjointSet dsu(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        
        ++d[u], ++d[v];
        dsu.merge(u, v);
    }

    std::vector<bool> t(n + 1, true);
    std::set<int> st;

    for (int i = 1; i <= n; ++i)
    {
        st.insert(dsu.find(i));

        if (d[i] != 2)
        {
            t[dsu.find(i)] = false;
        }
    }

    std::cout << st.size() - std::ranges::count(t | std::views::drop(1), false);

    return 0;
}
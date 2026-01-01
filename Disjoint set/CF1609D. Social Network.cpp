/**
 * Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
 * 
 * => D. Social Network ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/1609/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/1609/submission/341127532 By huanhuanonly
 * 
 * @b Disjoint-set
 * 
 * ----September 30, 2025 [09h:18m:57s]----
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
    std::vector<int> sizes;

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
        int fv = find(v), fu = find(u);

        if (fv != fu)
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

    int n, d;
    std::cin >> n >> d;

    DisjointSet dsu(n + 1);

    std::multiset<int, std::ranges::greater> st;

    for (int i = 1; i <= n; ++i)
    {
        st.insert(1);
    }

    int cnt = 1;

    for (int i = 0; i < d; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        if (dsu.find(u) == dsu.find(v))
        {
            ++cnt;
        }
        else
        {
            st.extract(dsu.size_of(u));
            st.extract(dsu.size_of(v));

            dsu.merge(u, v);

            st.insert(dsu.size_of(u));
        }

        int sum = -1;

        for (auto [it, i] = std::tuple(st.begin(), 0); i < cnt; ++it, ++i)
        {
            sum += *it;
        }

        std::cout << sum << '\n';
    }

    return 0;
}
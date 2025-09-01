/**
 * Codeforces Round 805 (Div. 3)
 * 
 * => E. Split Into Two Sets ( @c 1600 )
 * 
 * -> https://codeforces.com/problemset/problem/1702/E
 * 
 * Submissions ~> https://codeforces.com/contest/1702/submission/264248149 By huanhuanonly
 * 
 * @b Extended-domain-Disjoint-set
 * 
 * ----June 05, 2024 [14h:06m:32s]----
*/

#include <bits/stdc++.h>

using uint    = unsigned int;
using llong   = long long int;
using ullong  = unsigned long long int;
using ldouble = long double;

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

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        bool yes = true;

        DisjointSet ds(n * 2 + 1);

        std::vector<int> cnt(n + 1);

        for (int i = 0; i < n; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            ++cnt[u];
            ++cnt[v];

            if (u == v)
                yes = false;

            if (ds.find(u) == ds.find(v))
                yes = false;
            else
            {
                ds.merge(u, n + v);
                ds.merge(v, n + u);
            }
        }

        std::cout << (yes and std::count(cnt.begin(), cnt.end(), 2) == n ? "YES\n" : "NO\n");
    }

    return 0;
}
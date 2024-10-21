/**
 * UNIQUE VISION Programming Contest 2024 Autumn (AtCoder Beginner Contest 372)
 * 
 * => E - K-th Largest Connected Components
 * 
 * -> https://atcoder.jp/contests/abc372/tasks/abc372_e
 * 
 * @b Disjoint-set
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

    int n, q;
    std::cin >> n >> q;

    DisjointSet ds(n + 1);

    std::vector<std::vector<int>> set(n + 1);
    
    for (int i = 1; i <= n; ++i)
    {
        set[i].push_back(i);
    }

    while (q--)
    {
        int opt, u, v;
        std::cin >> opt >> u >> v;

        if (opt == 1)
        {
            if (ds.find(u) != ds.find(v))
            {
                std::vector<int> buf;
                buf.reserve(20);

                std::merge(set[ds.find(u)].begin(), set[ds.find(u)].end(),
                    set[ds.find(v)].begin(), set[ds.find(v)].end(),
                    std::back_inserter(buf), std::greater<int>());
                
                ds.merge(u, v);

                if (buf.size() > 10)
                    buf.resize(10);

                set[ds.find(u)] = std::move(buf);
            }
        }
        else
        {
            if (set[ds.find(u)].size() >= v)
                std::cout << set[ds.find(u)][v - 1] << '\n';
            else
                std::cout << -1 << '\n';
        }
    }

    return 0;
}
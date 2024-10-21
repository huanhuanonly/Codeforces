/**
 * AtCoder Beginner Contest 350
 * 
 * => G - Mediator
 * 
 * -> AtCoder Beginner Contest 350
 * 
 * @b Dsu-on-tree with @b Disjoint-set
*/

#include <bits/stdc++.h>

using uint    = unsigned int;
using llong   = long long int;
using ullong  = unsigned long long int;
using ldouble = long double;

class DisjointSet
{
public:
    
    std::vector<int> v;

    std::vector<int> size;

    explicit DisjointSet(int n) : v(n + 1), size(n + 1, 1) { std::iota(v.begin(), v.end(), 0); }

    int find(int x)
    {
        return v[x] == x ? x : v[x] = find(v[x]);
    }

    void merge(int x, int y)
    {
        size[find(x)] += size[find(y)];

        v[find(y)] = find(x);
    }
};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
    ::freopen("Input.txt", "r", stdin);
    ::freopen("Output.txt", "w", stdout);
#endif

    int n, q;
    std::cin >> n >> q;

    DisjointSet ds(n + 1);

    int last = 0;

    constexpr const int mod = 998244353;

    std::vector<std::vector<int>> e(n + 1);

    std::vector<int> fa(n + 1);

    std::function<void(int, int)> dfs = [&](int u, int last) -> void
    {
        fa[u] = last;

        for (const auto& i : e[u])
        {
            if (i == last)
                continue;
            
            dfs(i, u);
        }
    };

    while (q--)
    {
        ullong opt, u, v;
        std::cin >> opt >> u >> v;

        opt = 1ull + (((opt * (1 + last)) % mod) % 2);
        u = 1ull + (((u * (1 + last)) % mod) % n);
        v = 1ull + (((v * (1 + last)) % mod) % n);

        if (opt == 1)
        {
            e[u].push_back(v);
            e[v].push_back(u);

            if (ds.find(u) == u)
            {
                ds.merge(v, u);
                fa[u] = v;
            }
            else if (ds.find(v) == v)
            {
                ds.merge(u, v);
                fa[v] = u;
            }
            else
            {
                if (ds.size[ds.find(u)] < ds.size[ds.find(v)])
                {
                    dfs(u, v);
                    ds.merge(v, u);
                }
                else
                {
                    dfs(v, u);
                    ds.merge(u, v);
                }
            }
        }
        else
        {
            if (fa[u] == fa[v] and fa[u] != 0)
                std::cout << (last = fa[u]) << '\n';
                
            else if (fa[fa[u]] == v)
                std::cout << (last = fa[u]) << '\n';

            else if (fa[fa[v]] == u)
                std::cout << (last = fa[v]) << '\n';

            else
                std::cout << (last = 0) << '\n';
        }
    }

    return 0;
}
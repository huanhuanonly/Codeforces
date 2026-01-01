/**
 * Codeforces Round 888 (Div. 3)
 * 
 * => G. Vlad and the Mountains ( @c 2000 )
 * 
 * -> https://codeforces.com/contest/1851/problem/G
 * 
 * Submissions ~> https://codeforces.com/contest/1851/submission/339216634 By huanhuanonly
 * 
 * @b Graphs
 * @b Disjoint-set
 * @b Offline
 * 
 * ----September 18, 2025 [15h:11m:22s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, m;
        std::cin >> n >> m;

        std::vector<int> h(n + 1);
        std::vector<std::pair<int, int>> sh(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> h[i];
            sh[i] = {h[i], i};
        }

        std::ranges::sort(sh | std::views::drop(1));

        std::vector<std::vector<int>> e(n + 1);

        for (int i = 0; i < m; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            e[u].push_back(v);
            e[v].push_back(u);
        }

        struct query
        {
            int s, t, e;

            int i;
            bool answer;
        };

        int q;
        std::cin >> q;

        std::vector<query> qs(q);

        for (int i = 0; i < q; ++i)
        {
            std::cin >> qs[i].s >> qs[i].t >> qs[i].e;
            qs[i].i = i;
        }

        std::ranges::sort(qs, {}, [&](const query& v) -> int {
            return v.e + h[v.s];
        });

        DisjointSet dsu(n + 1);

        int pos = 0;

        std::vector<bool> vis(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            for (; pos < q; ++pos)
            {
                if (qs[pos].e + h[qs[pos].s] < sh[i].first)
                {
                    if (dsu.find(qs[pos].s) == dsu.find(qs[pos].t))
                    {
                        qs[pos].answer = true;
                    }
                }
                else
                {
                    break;
                }
            }

            for (int u : e[sh[i].second])
            {
                if (vis[u])
                {
                    dsu.merge(sh[i].second, u);
                }
            }

            vis[sh[i].second] = true;
        }

        for (; pos < q; ++pos)
        {
            if (dsu.find(qs[pos].s) == dsu.find(qs[pos].t))
            {
                qs[pos].answer = true;
            }
        }

        std::ranges::sort(qs, {}, &query::i);

        for (int i = 0; i < q; ++i)
        {
            if (qs[i].answer)
            {
                std::cout << "YES\n";
            }
            else
            {
                std::cout << "NO\n";
            }
        }
    }

    return 0;
}
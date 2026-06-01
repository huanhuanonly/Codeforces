/**
 * 2026 年山东省大学生程序设计竞赛
 *
 * => K. 最小生成树
 *
 * -> https://qoj.ac/contest/3767/problem/18317
 *
 * Submissions ~> https://qoj.ac/submission/2446070 By huanhuanonly
 *
 * @b Kruskal’s-algorithm
 *
 * ----May 26, 2026 [19h:37m:34s]----
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

#if defined(__SIZEOF_INT128__)
using int128 = __int128;
using uint128 = unsigned __int128;
#endif

using real32 = float;
using real64 = double;

#if defined(__SIZEOF_FLOAT80__)
using real80 = __float80;
#endif

#if defined(__SIZEOF_FLOAT128__)
using real128 = __float128;
#endif

inline namespace huanhuanonly {
    inline namespace data_structure
{
class DisjointSet
{
public:

    using size_type = int;

    explicit
    DisjointSet(size_type __n)
        : _M_parent(__n)
    { reset(); }

    [[nodiscard]] size_type
    find(size_type u)
    { return _M_parent[u] == u ? u : _M_parent[u] = find(_M_parent[u]); }

    bool
    unite(size_type u, size_type v)
    {
        const size_type fu = find(u);
        const size_type fv = find(v);

        if (fu != fv)
        {
            _M_parent[fv] = fu;
            return true;
        }
        else
        {
            return false;
        }
    }

    [[nodiscard]] bool
    connected(size_type u, size_type v)
    { return find(u) == find(v); }

    void
    expand(size_type __n)
    {
        const size_type size = static_cast<size_type>(_M_parent.size());
        _M_parent.resize(size + __n);
        std::iota(_M_parent.begin() + size, _M_parent.end(), size);
    }

    void
    reset()
    { std::iota(_M_parent.begin(), _M_parent.end(), 0); }

    [[nodiscard]] size_type
    size()
    { return static_cast<size_type>(_M_parent.size()); }

private:

    std::vector<size_type> _M_parent;
};
}} // namespace huanhuanonly::data_structure

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, m, k;
        std::cin >> n >> m >> k;

        std::vector<int> set(k);

        for (int i = 0; i < k; ++i)
        {
            std::cin >> set[i];
        }

        std::ranges::sort(set);

        struct edge
        {
            int u, v, w;
        };

        std::vector<edge> e1, e2;

        for (int i = 0; i < m; ++i)
        {
            int u, v, w;
            std::cin >> u >> v >> w;

            const bool iu = std::ranges::binary_search(set, u);
            const bool iv = std::ranges::binary_search(set, v);

            if (iu or iv)
            {
                if (iu and iv and n != 2)
                {
                    continue;
                }

                e2.emplace_back(u, v, w);
            }
            else
            {
                e1.emplace_back(u, v, w);
            }
        }

        std::ranges::sort(e1, {}, &edge::w);
        std::ranges::sort(e2, {}, &edge::w);

        DisjointSet dsu(n + 1);
        std::vector<int> cnt(n + 1);

        uint64 sum = 0;

        for (const auto& [u, v, w] : e1)
        {
            if (dsu.unite(u, v))
            {
                sum += w;

                ++cnt[u];
                ++cnt[v];
            }
        }

        for (const auto& [u, v, w] : e2)
        {
            if (std::ranges::binary_search(set, u) and cnt[u] == 1)
            {
                continue;
            }

            if (std::ranges::binary_search(set, v) and cnt[v] == 1)
            {
                continue;
            }

            if (dsu.unite(u, v))
            {
                sum += w;

                ++cnt[u];
                ++cnt[v];
            }
        }

        bool yes = true;

        for (int i = 2; i <= n; ++i)
        {
            if (dsu.find(i) != dsu.find(1))
            {
                yes = false;
            }
        }

        if (yes)
        {
            std::cout << sum << '\n';
        }
        else
        {
            std::cout << "-1\n";
        }
    }

    return 0;
}
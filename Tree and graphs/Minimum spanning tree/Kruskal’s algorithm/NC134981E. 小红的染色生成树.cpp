/**
 * 牛客周赛 Round 145
 *
 * => E-小红的染色生成树 ( @c 1600 )
 *
 * -> https://ac.nowcoder.com/acm/contest/134981/E
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83710022 By huanhuanonly
 *
 * @b Kruskal’s-algorithm
 *
 * ----May 27, 2026 [20h:17m:22s]----
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

    int n, m;
    std::cin >> n >> m;

    struct edge
    {
        int u, v, c;
    };

    std::vector<edge> e(m);

    for (auto& [u, v, c] : e)
    {
        std::cin >> u >> v >> c;
    }

    auto test = [&](int c1, int c2) -> bool
    {
        DisjointSet dsu(n + 1);

        std::vector<std::pair<int, int>> ans;
        ans.reserve(n - 1);

        int flag = 0;

        for (const auto& [u, v, c] : e)
        {
            if (c == c1 and dsu.unite(u, v))
            {
                flag |= 1;
                ans.emplace_back(u, v);
                break;
            }
        }

        for (const auto& [u, v, c] : e)
        {
            if (c == c2 and dsu.unite(u, v))
            {
                flag |= 2;
                ans.emplace_back(u, v);
            }
        }

        for (const auto& [u, v, c] : e)
        {
            if (c == c1 and dsu.unite(u, v))
            {
                ans.emplace_back(u, v);
            }
        }

        if (flag == 3 and ans.size() == n - 1)
        {
            for (const auto& [u, v] : ans)
            {
                std::cout << u << ' ' << v << '\n';
            }

            return true;
        }
        else
        {
            return false;
        }
    };

    if (not (test(0, 1) or test(0, 2) or test(1, 2)))
    {
        std::cout << "-1\n";
    }

    return 0;
}
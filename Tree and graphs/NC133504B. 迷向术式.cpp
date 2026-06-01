/**
 * 华中地区高校第十九届程序设计邀请赛（同步赛）
 *
 * => B-迷向术式
 *
 * -> https://ac.nowcoder.com/acm/contest/133504/B
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83393169 By huanhuanonly
 *
 * @b Graphs
 * @b Game-theory
 * @b Disjoint-set
 * @b Bipartite-graph
 *
 * ----April 25, 2026 [18h:25m:02s]----
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

    int n, m, k, q;
    std::cin >> n >> m >> k >> q;

    DisjointSet dsu(n + 1);
    std::vector<std::vector<int>> e(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);

        dsu.unite(u, v);
    }

    std::vector<bool> vis(n + 1);
    std::vector<bool> color(n + 1);
    std::vector<std::shared_ptr<bool>> is(n + 1);

    auto dfs = [&](const auto& self, int u, const std::shared_ptr<bool>& ptr) -> void
    {
        is[u] = ptr;

        for (const auto& i : e[u])
        {
            if (not vis[i])
            {
                vis[i] = true;
                color[i] = not color[u];
                self(self, i, ptr);
            }
            else if (color[i] != not color[u])
            {
                *ptr = false;
            }
        }
    };

    for (int i = 1; i <= n; ++i)
    {
        if (not vis[i])
        {
            vis[i] = true;
            dfs(dfs, i, std::make_shared<bool>(true));
        }
    }

    std::vector<int> a(k + 1);

    for (int i = 1; i <= k; ++i)
    {
        std::cin >> a[i];
    }

    std::vector<int> next(k + 1, k + 1);

    for (int i = 1; i <= k; ++i)
    {
        for (int j = i + 1; j <= k; ++j)
        {
            if (dsu.connected(a[i], a[j]) and (not *is[a[i]] or (j - i & 1) == (color[a[i]] != color[a[j]])))
            {
                next[i] = j;
                break;
            }
        }
    }

    while (q--)
    {
        int l, r;
        std::cin >> l >> r;

        if (next[l] <= r)
        {
            std::cout << "Fern\n";
        }
        else
        {
            std::cout << "Stark\n";
        }
    }

    return 0;
}
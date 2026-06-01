/**
 * 哈尔滨华德学院第十七届程序设计竞赛（同步赛）
 *
 * => L-五彩斑斓的最小生成树
 *
 * -> https://ac.nowcoder.com/acm/contest/132781/L
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83582122 By huanhuanonly
 *
 * @b Kruskal’s-algorithm
 * @b Disjoint-set-with-rollback
 *
 * ----May 13, 2026 [14h:21m:19s]----
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

    struct node
    {
        size_type parent;
        size_type size;
    };

    struct change_record
    {
        std::pair<size_type&, size_type> parent;
        std::pair<size_type&, size_type> size;
    };

    explicit
    DisjointSet(size_type __n)
        : _M_tree(__n)
    { reset(); }

    [[nodiscard]] size_type
    find(size_type u) const
    { return is_root(u) ? u : find(_M_tree[u].parent); }

    bool
    unite(size_type u, size_type v)
    {
        size_type fu = find(u);
        size_type fv = find(v);

        if (fu == fv)
        {
            return false;
        }

        if (_M_tree[fu].size < _M_tree[fv].size)
        {
            std::swap(fu, fv);
        }

        _M_history.emplace(change_record{
                {_M_tree[fv].parent, _M_tree[fv].parent},
                {_M_tree[fu].size,   _M_tree[fu].size  }});

        _M_tree[fv].parent = fu;
        _M_tree[fu].size += _M_tree[fv].size;

        return true;
    }

    [[nodiscard]] bool
    is_root(size_type u) const
    { return _M_tree[u].parent == u; }

    [[nodiscard]] bool
    connected(size_type u, size_type v) const
    { return find(u) == find(v); }

    void
    expand(size_type __n)
    {
        const size_type old_size = size();
        _M_tree.resize(old_size + __n);

        for (size_type i = old_size; i < old_size + __n; ++i)
        {
            _M_tree[i].parent = i;
            _M_tree[i].size = 1;
        }
    }

    void
    reset()
    {
        for (size_type i = 0; i < size(); ++i)
        {
            _M_tree[i].parent = i;
            _M_tree[i].size = 1;
        }
    }

    [[nodiscard]] size_type
    size() const
    { return static_cast<size_type>(_M_tree.size()); }

    [[nodiscard]] size_type
    component_size(size_type u) const
    { return _M_tree[find(u)].size; }

    [[nodiscard]] size_type
    checkpoint() const
    { return static_cast<size_type>(_M_history.size()); }

    void
    undo()
    {
        if (not _M_history.empty())
        {
            const auto& rec = _M_history.top();

            rec.parent.first = rec.parent.second;
            rec.size.first = rec.size.second;

            _M_history.pop();
        }
    }

    void
    rollback(size_type __cp)
    { for (; checkpoint() > __cp; undo()); }

private:

    std::vector<node> _M_tree;
    std::stack<change_record, std::vector<change_record>> _M_history;
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

    std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> map;

    std::map<int, int> ans;

    for (int i = 0; i < m; ++i)
    {
        int u, v, w, c;
        std::cin >> u >> v >> w >> c;

        ans[c];
        map[{w, c}].emplace_back(u, v);
    }

    DisjointSet dsu(n + 1);

    for (auto it = map.begin(); it != map.end(); ++it)
    {
        const auto cp = dsu.checkpoint();

        bool ok = true;

        for (const auto& [u, v] : it->second)
        {
            if (not dsu.unite(u, v))
            {
                ok = false;
            }
        }

        if (ok)
        {
            ++ans[it->first.second];
        }

        if (auto nit = std::next(it); nit != map.end() and nit->first.first == it->first.first)
        {
            dsu.rollback(cp);
        }
        else if (it != map.begin())
        {
            for (auto pit = std::prev(it); pit->first.first == it->first.first; --pit)
            {
                for (const auto& [u, v] : pit->second)
                {
                    dsu.unite(u, v);
                }

                if (pit == map.begin())
                {
                    break;
                }
            }
        }
    }

    for (const auto& [key, value] : ans)
    {
        std::cout << key << ' ' << value << '\n';
    }

    return 0;
}
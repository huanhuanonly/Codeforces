/**
 * 牛客周赛 Round 140
 *
 * => G-小红的生成树构造 ( @c 1800 )
 *
 * -> https://ac.nowcoder.com/acm/contest/132940/G
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83330915 By huanhuanonly
 *
 * @b Kruskal’s-algorithm and @b Constructive
 *
 * ----April 19, 2026 [20h:23m:26s]----
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

    std::string s;
    std::cin >> s;

    std::vector<std::pair<int, int>> es(m);

    for (auto& [u, v] : es)
    {
        std::cin >> u >> v;
    }

    auto $ = [&s](const std::pair<int, int>& e)
    {
        const auto t = std::minmax(s[e.first - 1], s[e.second - 1]);

        if (t.first == 'A' and t.second == 'B')
        {
            return 0;
        }
        else if (t.first == 'C' and t.second == 'D')
        {
            return 1;
        }
        else if (t.first == t.second)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    };

    std::ranges::sort(es, {}, $);

    DisjointSet dsu(n + 1);

    std::vector<std::pair<int, int>> ans;
    ans.reserve(n - 1);

    bool yes = true;
    bool first = true;

    for (const auto& c : es)
    {
        if (first and $(c) == 3)
        {
            first = false;

            std::map<int, std::set<char>> map;

            for (int i = 1; i <= n; ++i)
            {
                map[dsu.find(i)].insert(s[i - 1]);
            }

            for (const auto& [key, value] : map)
            {
                if (value.size() == 1)
                {
                    yes = false;
                    break;
                }
            }
        }

        if (dsu.unite(c.first, c.second))
        {
            ans.push_back(c);
        }
    }

    if (yes)
    {
        std::cout << "Yes\n";

        for (const auto& [u, v] : ans)
        {
            std::cout << u << ' ' << v << '\n';
        }
    }
    else
    {
        std::cout << "No\n";
    }

    return 0;
}
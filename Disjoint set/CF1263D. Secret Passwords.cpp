/**
 * Codeforces Round 603 (Div. 2)
 * 
 * => D. Secret Passwords ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/1263/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/1263/submission/327477799 By huanhuanonly
 * 
 * @b Disjoint-set
 * 
 * ----July 05, 2025 [14h:55m:26s]----
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

    int n;
    std::cin >> n;

    DisjointSet dsu(n);

    std::array<std::vector<int>, 26> arr;

    std::string s;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> s;

        std::array<int, 26> cnt{};

        for (const char c : s)
        {
            ++cnt[c - 'a'];
        }

        for (int j = 0; j < cnt.size(); ++j)
        {
            if (cnt[j])
            {
                arr[j].push_back(i);
            }
        }
    }

    for (const auto& a : arr)
    {
        for (int i = 1; i < a.size(); ++i)
        {
            if (dsu.find(a[i - 1]) != dsu.find(a[i]))
            {
                dsu.merge(a[i - 1], a[i]);
            }
        }
    }

    std::ranges::for_each(std::views::iota(0, n), [&](int i) -> void { dsu.find(i); });
    std::ranges::sort(dsu.tree);
    std::cout << std::ranges::unique(dsu.tree).begin() - dsu.tree.begin();

    return 0;
}
/**
 * Good Bye 2014
 * 
 * => B. New Year Permutation ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/500/problem/B
 * 
 * Submissions ~> https://codeforces.com/contest/500/submission/345521584 By huanhuanonly
 * 
 * @b Disjoint-set
 * 
 * ----October 24, 2025 [22h:23m:13s]----
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

    std::vector<int> v(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
    }

    std::vector<std::string> matrix(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> matrix[i];
    }

    DisjointSet dsu(n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == '1')
            {
                dsu.merge(i, j);
            }
        }
    }

    std::map<int, std::vector<int>> sets;
    std::map<int, std::vector<int>> pos;

    for (int i = 0; i < n; ++i)
    {
        sets[dsu.find(i)].push_back(v[i]);
        pos[dsu.find(i)].push_back(i);
    }

    for (auto& [key, values] : sets)
    {
        std::ranges::sort(values);
    }

    for (auto [sit, pit] = std::tuple(sets.begin(), pos.begin()); sit != sets.end(); ++sit, ++pit)
    {
        for (int i = 0; i < sit->second.size(); ++i)
        {
            v[pit->second[i]] = sit->second[i];
        }
    }

    for (int i : v)
    {
        std::cout << i << ' ';
    }

    return 0;
}
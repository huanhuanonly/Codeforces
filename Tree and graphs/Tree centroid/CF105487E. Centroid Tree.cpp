/**
 * 2024 China Collegiate Programming Contest (CCPC) Female Onsite (2024年中国大学生程序设计竞赛女生专场)
 * 
 * => E. Centroid Tree
 * 
 * -> https://codeforces.com/gym/105487/problem/E
 * 
 * Submissions ~> https://codeforces.com/gym/105487/submission/344882140 By huanhuanonly
 * 
 * @b Disjoint-set and @b Tree-centroid
 * 
 * ----October 20, 2025 [21h:51m:59s]----
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
        int n;
        std::cin >> n;

        std::vector<std::vector<int>> centroid(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            int size;
            std::cin >> size;

            centroid[i].resize(size);

            for (int j = 0; j < size; ++j)
            {
                std::cin >> centroid[i][j];
            }
        }

        DisjointSet dsu(n + 1);

        std::vector<std::pair<int, int>> ans;

        for (int u = n; u >= 1; --u)
        {
            for (int v : centroid[u])
            {
                const auto [min, max] = std::minmax(u, dsu.find(v));
                ans.emplace_back(min, max);

                dsu.merge(min, max);
            }
        }

        for (const auto& [u, v] : ans)
        {
            std::cout << u << ' ' << v << '\n';
        }
    }

    return 0;
}
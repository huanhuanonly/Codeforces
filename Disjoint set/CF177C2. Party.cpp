/**
 * ABBYY Cup 2.0 - Easy
 * 
 * => C2. Party ( @c 1500 )
 * 
 * -> https://codeforces.com/problemset/problem/177/C2
 * 
 * Submissions ~> https://codeforces.com/contest/177/submission/319351233 By huanhuanonly
 * 
 * @b Disjoint-set
 * 
 * ----May 12, 2025 [16h:54m:44s]----
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

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n, k;
    std::cin >> n >> k;

    DisjointSet like(n + 1);
    std::map<int, std::vector<int>> dislike;

    for (int i = 0; i < k; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        like.merge(u, v);
    }
    
    int m;
    std::cin >> m;
    
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        dislike[u].push_back(v);
    }
    
    std::map<int, std::vector<int>> mp;

    for (int i = 1; i <= n; ++i)
    {
        mp[like.find(i)].push_back(i);
    }

    int ans = 0;

    for (auto& [unused, friends] : mp)
    {
        std::ranges::sort(friends);
        bool can = true;

        for (int i : friends)
        {
            if (std::ranges::find_if(dislike[i], [&](int i) -> bool {
                    return std::ranges::binary_search(friends, i); }) != dislike[i].end())
            {
                can = false;
                break;
            }
        }

        if (can)
        {
            ans = std::max<int>(ans, friends.size());
        }
    }

    std::cout << ans << '\n';

    return 0;
}
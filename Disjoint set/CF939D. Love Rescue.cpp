/**
 * Codeforces Round 464 (Div. 2)
 * 
 * => D. Love Rescue ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/939/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/939/submission/339404169 By huanhuanonly
 * 
 * @b Disjoint-set
 * 
 * ----September 19, 2025 [23h:31m:49s]----
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

    std::string s, t;
    std::cin >> s >> t;

    DisjointSet dsu(26);

    for (int i = 0; i < n; ++i)
    {
        if (dsu.find(s[i] - 'a') != dsu.find(t[i] - 'a'))
        {
            dsu.merge(s[i] - 'a', t[i] - 'a');
        }
    }

    std::map<int, std::vector<char>> sets;

    int cnt = 0;

    for (int i = 0; i < 26; ++i)
    {
        sets[dsu.find(i)].push_back('a' + i);
    }

    for (const auto& [key, values] : sets)
    {
        cnt += values.size() - 1;
    }

    std::cout << cnt << '\n';

    for (const auto& [key, values] : sets)
    {
        for (int i = 1; i < values.size(); ++i)
        {
            std::cout << values[i - 1] << ' ' << values[i] << '\n';
        }
    }

    return 0;
}
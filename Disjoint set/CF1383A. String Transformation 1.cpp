/**
 * Codeforces Round 659 (Div. 1)
 * 
 * => A. String Transformation 1 ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/1383/problem/A
 * 
 * Submissions ~> https://codeforces.com/contest/1383/submission/341202966 By huanhuanonly
 * 
 * @b Disjoint-set
 * 
 * ----September 30, 2025 [21h:52m:50s]----
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
    std::vector<int> sizes;

    explicit DisjointSet(std::size_t n)
        : tree(n), sizes(n, 1)
    {
        std::iota(tree.begin(), tree.end(), 0);
    }

    int find(int u)
    {
        return tree[u] == u ? u : tree[u] = find(tree[u]);
    }

    void merge(int u, int v)
    {
        int fv = find(v), fu = find(u);

        if (fv != fu)
        {
            sizes[fu] += sizes[fv];
            tree[fv] = fu;
        }
    }

    int size_of(int u)
    {
        return sizes[find(u)];
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

        std::string s, t;
        std::cin >> s >> t;

        DisjointSet dsu(20);

        bool yes = true;

        for (int i = 0; i < n; ++i)
        {
            if (s[i] > t[i])
            {
                yes = false;
                break;
            }
            else if (s[i] != t[i])
            {
                dsu.merge(s[i] - 'a', t[i] - 'a');
            }
        }

        if (not yes)
        {
            std::cout << -1 << '\n';
            continue;
        }

        std::map<int, int> mp;

        for (int i = 0; i < 20; ++i)
        {
            mp[dsu.find(i)] = dsu.size_of(i);
        }

        int sum = 0;

        for (const auto& [key, value] : mp)
        {
            sum += value - 1;
        }

        std::cout << sum << '\n';
    }

    return 0;
}
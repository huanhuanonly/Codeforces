/**
 * Codeforces Round 1065 (Div. 3)
 * 
 * => D. Rae Taylor and Trees (easy version) ( @c 1400 )
 * 
 * -> https://codeforces.com/contest/2171/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2171/submission/349940444 By huanhuanonly
 * 
 * @b Trees and @b Disjoint-set
 * 
 * ----November 21, 2025 [00h:05m:30s]----
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
        int min = find(u), max = find(v);
        
        if (min > max)
        {
            std::swap(min, max);
        }

        tree[max] = min;
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

        std::vector<int> v(n);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i];
            --v[i];
        }

        DisjointSet dsu(n);

        std::set<int> set;

        for (int i = 0; i < n; ++i)
        {
            for (auto it = set.begin(); it != set.end() and *it < v[i]; it = set.erase(it))
            {
                dsu.merge(*it, v[i]);
            }

            set.insert(dsu.find(v[i]));
        }

        if (set.size() == 1)
        {
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
    }

    return 0;
}
/**
 * Educational Codeforces Round 103 (Rated for Div. 2)
 * 
 * => D. Journey ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/1476/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/1476/submission/329752728 By huanhuanonly
 * 
 * @b Disjoint-set
 * 
 * ----July 19, 2025 [18h:01m:25s]----
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

private:

    std::vector<int> sizes;

public:

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
        if (int fu = find(u), fv = find(v); fu != fv)
        {
            tree[fv] = fu;
            sizes[fu] += sizes[fv];
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

        std::string s;
        std::cin >> s;

        DisjointSet dsu(n);

        for (int i = 0; i < n - 1; ++i)
        {
            if (s[i] != s[i + 1])
            {
                dsu.merge(i, i + 1);
            }
        }

        for (int i = 0; i <= n; ++i)
        {
            int cnt = 1;

            if (i > 0 and s[i - 1] == 'L')
            {
                cnt += dsu.size_of(i - 1);
            }
            else if (i < n and s[i] == 'R')
            {
                cnt += dsu.size_of(i);
            }

            std::cout << cnt << " \n"[i == n];
        }
    }

    return 0;
}
/**
 * Codeforces Round 548 (Div. 2)
 * 
 * => C. Edgy Trees ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/1139/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/1139/submission/329033125 By huanhuanonly
 * 
 * @b Combinatorics and @b Disjoint-set
 * 
 * ----July 15, 2025 [17h:13m:03s]----
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

template<typename _Tp>
_Tp binary_exponentiation(_Tp __fv, _Tp __sv, _Tp __mod)
{
    __fv %= __mod;

    _Tp ans = 1;
    for (; __sv; __fv = (__fv * __fv) % __mod, __sv >>= 1)
        if (__sv & 1)
            ans = (ans * __fv) % __mod;
    return ans;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    uint64 n, k;
    std::cin >> n >> k;

    DisjointSet dsu(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, c;
        std::cin >> u >> v >> c;

        if (c == 0)
        {
            dsu.merge(u, v);
        }
    }

    std::map<int, uint64> count;

    for (int i = 1; i <= n; ++i)
    {
        ++count[dsu.find(i)];
    }

    constexpr uint64 mod = 1e9 + 7;

    uint64 sum = binary_exponentiation(n, k, mod);

    for (const auto& [key, value] : count)
    {
        sum = (sum + mod - binary_exponentiation(value, k, mod)) % mod;
    }

    std::cout << sum;

    return 0;
}
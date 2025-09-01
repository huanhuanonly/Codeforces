/**
 * Testing Round 12
 * 
 * => C. Subsequences ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/597/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/597/submission/329049020 By huanhuanonly
 * 
 * @b DP with @b Binary-indexed-tree
 * 
 * ----July 15, 2025 [19h:28m:05s]----
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

// Fenwick Tree
template<typename _ValueType>
class BinaryIndexedTree
{
public:
    using value_type = _ValueType;

    explicit BinaryIndexedTree(std::size_t n) : arr(n) { }

    static constexpr inline std::size_t lowbit(std::size_t p) { return p & -p; }

    void add(std::size_t p, value_type value)
    {
        while (p < arr.size())
        {
            arr[p] += value;
            p += lowbit(p);
        }
    }

    value_type sum(std::size_t p)
    {
        value_type ans{};
        while (p)
        {
            ans += arr[p];
            p -= lowbit(p);
        }
        return ans;
    }

private:
    std::vector<value_type> arr;
};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n, k;
    std::cin >> n >> k;

    std::vector<int> v(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
    }

    std::array dp{
        std::vector<int64>(n + 1, 1),
        std::vector<int64>(n + 1)
    };

    int i = 1;
    for (; k--; i = not i)
    {
        BinaryIndexedTree<int64> bit(n + 1);

        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = bit.sum(v[j] - 1);
            bit.add(v[j], dp[not i][j]);
        }
    }
    
    i = not i;
    std::cout << std::reduce(dp[i].begin() + 1, dp[i].end());

    return 0;
}
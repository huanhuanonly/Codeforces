/**
 * Educational Codeforces Round 185 (Rated for Div. 2)
 * 
 * => E. Binary Strings and Blocks ( @c 2100 )
 * 
 * -> https://codeforces.com/contest/2170/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2170/submission/351703094 By huanhuanonly
 * 
 * @b Counting-DP
 * 
 * ----December 03, 2025 [17h:18m:52s]----
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
        int n, m;
        std::cin >> n >> m;

        constexpr uint64 mod = 998244353;

        std::vector<int> maxl(n + 1);

        for (int i = 0; i < m; ++i)
        {
            int l, r;
            std::cin >> l >> r;

            maxl[r] = std::max(maxl[r], l);
        }

        std::partial_sum(maxl.begin(), maxl.end(), maxl.begin(), std::ranges::max);

        std::vector<uint64> dp(n + 2);
        std::vector<uint64> presum(n + 2);
        
        dp[1] = presum[1] = 2;

        for (int i = 2; i <= n + 1; ++i)
        {
            dp[i] = (presum[i - 1] + mod - presum[maxl[i - 1] + 1 - 1]) % mod;
            presum[i] = (presum[i - 1] + dp[i]) % mod;
        }

        std::cout << dp[n + 1] << '\n';
    }

    return 0;
}
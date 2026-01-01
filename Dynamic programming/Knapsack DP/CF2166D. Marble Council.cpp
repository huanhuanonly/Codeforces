/**
 * Codeforces Round 1064 (Div. 2)
 * 
 * => D. Marble Council ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/2166/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2166/submission/354036374 By huanhuanonly
 * 
 * @b Knapsack-DP ( @a 0/1-knapsack-problem )
 * 
 * ----December 19, 2025 [11h:07m:30s]----
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
        uint64 n;
        std::cin >> n;

        constexpr uint64 mod = 998244353;

        std::vector<uint64> cnt(n + 1);

        for (int i = 0, v; i < n; ++i)
        {
            std::cin >> v;
            ++cnt[v];
        }

        std::vector dp(n + 1, uint64{});
        dp[0] = 1;

        for (int i = 1; i <= n; ++i)
        {
            if (cnt[i])
            {
                for (int j = n; j >= cnt[i]; --j)
                {
                    (dp[j] += dp[j - cnt[i]] * cnt[i] % mod) %= mod;
                }
            }
        }

        std::cout << std::reduce(dp.begin() + *std::ranges::max_element(cnt), dp.end()) % mod << '\n';
    }

    return 0;
}
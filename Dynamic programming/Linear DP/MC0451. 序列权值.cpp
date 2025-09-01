/**
 * 2025年码蹄杯 职业院校赛道 & 青少年挑战赛道入门组国赛
 * 
 * => MC0451 序列权值 ( @c 钻石 )
 * 
 * -> https://www.matiji.net/exam/brushquestion/51/4693/305EE97B0D5E361DE6A28CD18C929AF0
 * 
 * Submissions ~> https://www.matiji.net/exam/oj/submit-detail/15237020/51/4693/305EE97B0D5E361DE6A28CD18C929AF0 By huanhuanonly
 * 
 * @b Linear-DP
 * 
 * ----August 29, 2025 [15h:29m:14s]----
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

        std::vector<uint64> v(n + 1);

        for (uint64 i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
        }

        constexpr uint64 mod = 998244353;

        std::vector<uint64> dp(n + 1);

        std::map<uint64, uint64> sum;

        for (uint64 i = 1, cnt = 1; i <= n; ++i, cnt = cnt * 2 % mod)
        {
            dp[i] = (dp[i - 1] + mod + cnt - sum[v[i]]) % mod;

            (sum[v[i]] += cnt) %= mod;

            (dp[i] += dp[i - 1]) %= mod;
        }

        std::cout << dp[n] << '\n';
    }

    return 0;
}
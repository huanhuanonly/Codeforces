/**
 * Educational Codeforces Round 136 (Rated for Div. 2)
 * 
 * => E. Cleaning Robot ( @c 2400 )
 * 
 * -> https://codeforces.com/contest/1739/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/1739/submission/340784685 By huanhuanonly
 * 
 * @b Linear-DP and @b Classification-discussion
 * 
 * ----September 27, 2025 [23h:16m:41s]----
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

    for (int n; std::cin >> n; )
    {
        std::array<std::string, 2> mp;
        std::cin >> mp[0] >> mp[1];

        mp[0].insert(mp[0].begin(), '0');
        mp[1].insert(mp[1].begin(), '0');

        const int count = std::ranges::count(mp[0], '1') + std::ranges::count(mp[1], '1');
    
        std::vector dp(2, std::vector<int>(n + 2));
    
        for (int i = n - 1; i >= 0; --i)
        {
            for (int lay = 0; lay <= 1; ++lay)
            {
                if (mp[lay ^ 1][i] == '0')
                {
                    dp[lay][i] = dp[lay][i + 1];
                }
                else if (mp[lay][i + 1] == '0')
                {
                    dp[lay][i] = std::min(dp[lay][i + 1] + 1, dp[lay ^ 1][i + 1]);
                }
                else if (mp[lay ^ 1][i + 1] == '0')
                {
                    dp[lay][i] = std::min(dp[lay][i + 1] + 1, dp[lay ^ 1][i + 2] + 1);
                }
                else if (mp[lay ^ 1][i + 1] == '1')
                {
                    dp[lay][i] = std::min(dp[lay][i + 2] + 2, dp[lay ^ 1][i + 2] + 1);
                }
            }
        }
        
        std::cout << count - dp[0][0] << '\n';
    }

    return 0;
}
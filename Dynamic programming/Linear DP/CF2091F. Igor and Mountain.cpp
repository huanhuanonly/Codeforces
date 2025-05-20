/**
 * Codeforces Round 1013 (Div. 3)
 * 
 * => F. Igor and Mountain ( @c 1800 )
 * 
 * -> https://codeforces.com/contest/2091/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/2091/submission/315988298 By huanhuanonly
 * 
 * @b Linear-DP with @b Prefix-sum
 * 
 * ----April 18, 2025 [00h:20m:39s]----
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

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int _;
    std::cin >> _;

    while (_--)
    {
        static constexpr uint64 MOD = 998244353;

        uint64 n, m, d;
        std::cin >> n >> m >> d;

        std::vector<std::vector<char>> mp(n + 1, std::vector<char>(m + 1));

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                std::cin >> mp[i][j];
            }
        }

        std::vector<std::vector<std::vector<uint64>>> dp(2, std::vector<std::vector<uint64>>(n + 1, std::vector<uint64>(m + 1)));

        auto sum = [](const std::vector<uint64>& v, int l, int r) -> uint64
        {
            if (l <= 0)         l = 1;
            if (r >= v.size())  r = v.size() - 1;

            return (v[r] % MOD + MOD - v[l - 1] % MOD) % MOD;
        };

        for (int i = 1; i <= m; ++i)
        {
            dp[0][n][i] += dp[0][n][i - 1] + (mp[n][i] == 'X');
            dp[0][n][i] %= MOD;
        }
        
        for (int i = 1; i <= m; ++i)
        {
            dp[1][n][i] += dp[1][n][i - 1] + (mp[n][i] == 'X' ? sum(dp[0][n], i - d, i + d) + MOD - sum(dp[0][n], i, i) : 0);
            dp[1][n][i] %= MOD;
        }

        for (int i = n - 1; i >= 1; --i)
        {
            for (int j = 1; j <= m; ++j)
            {
                dp[0][i][j] = dp[0][i][j - 1];

                if (mp[i][j] == 'X')
                {
                    dp[0][i][j] += sum(dp[0][i + 1], j - d + 1, j + d - 1) + sum(dp[1][i + 1], j - d + 1, j + d - 1);
                    dp[0][i][j] %= MOD;
                }
            }
            
            for (int j = 1; j <= m; ++j)
            {
                dp[1][i][j] = dp[1][i][j - 1];

                if (mp[i][j] == 'X')
                {
                    dp[1][i][j] += sum(dp[0][i], j - d, j + d) + MOD - sum(dp[0][i], j, j);
                    dp[1][i][j] %= MOD;
                }
            }
        }

        std::cout << (dp[0][1].back() + dp[1][1].back()) % MOD << '\n';
    }

    return 0;
}
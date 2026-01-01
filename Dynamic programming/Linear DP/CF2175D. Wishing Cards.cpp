/**
 * Codeforces Round 1069 (Div. 2)
 * 
 * => D. Wishing Cards ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/2175/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2175/submission/352567274 By huanhuanonly
 * 
 * @b Linear-DP
 * 
 * ----December 08, 2025 [22h:19m:47s]----
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

constexpr void chmax(auto& lhs, const auto& rhs) noexcept
{
    if (lhs < rhs)
    {
        lhs = rhs;
    }
}

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
        uint64 n, k;
        std::cin >> n >> k;

        std::vector<uint64> v(n + 1);
        std::vector<bool> inque(n + 1);

        for (int i = 1, j = 0; i <= n; ++i)
        {
            std::cin >> v[i];

            if (v[j] < v[i])
            {
                j = i;
                inque[i] = true;
            }
        }

        std::vector dp(2, std::vector(k + 1, std::vector(k + 1, uint64{})));

        for (int i = 1, j = 0; i <= n; ++i)
        {
            if (not inque[i])
            {
                continue;
            }

            for (; j <= v[i]; ++j)
            {
                for (int r = 0; r <= k; ++r)
                {
                    for (int j2 = 0; j2 <= j and r + j <= k; ++j2)
                    {
                        chmax(dp[1][j][r], dp[0][j2][r + j] + (j - j2) * (n - i + 1));
                    }
                }
            }

            dp[0] = dp[1];
        }

        uint64 ans = 0;

        for (int j = 0; j <= k; ++j)
        {
            for (int r = 0; r <= k; ++r)
            {
                chmax(ans, dp[1][j][r]);
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}
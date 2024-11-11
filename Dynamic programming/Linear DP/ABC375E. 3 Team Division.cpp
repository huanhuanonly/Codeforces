/**
 * Panasonic Programming Contest 2024（AtCoder Beginner Contest 375）
 * 
 * => E - 3 Team Division
 * 
 * -> https://atcoder.jp/contests/abc375/tasks/abc375_e ( @c 450 )
 * 
 * Submissions ~> https://atcoder.jp/contests/abc375/submissions/59312487 By huanhuanonly
 * 
 * @b Linear-DP
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

    uint32 n;
    std::cin >> n;

    uint32 sum = 0;

    std::vector<std::pair<uint32, uint32>> v(n + 1);

    for (auto& [i, j] : v | std::views::drop(1))
    {
        std::cin >> i >> j;
        sum += j;
    }

    if (sum % 3)
    {
        std::cout << -1;
        return 0;
    }

    uint32 inf = std::numeric_limits<decltype(inf)>::max() - 1;

    uint32 avg = sum / 3;

    // [i][x][y]
    std::vector<std::vector<std::vector<uint32>>> dp(n + 1, std::vector<std::vector<uint32>>(avg + 1, std::vector<uint32>(avg + 1, inf)));

    dp[0][0][0] = 0;

    for (uint32 i = 1; i <= n; ++i)
    {
        for (uint32 x = 0; x <= avg; ++x)
        {
            for (uint32 y = 0; y <= avg; ++y)
            {
                if (x + v[i].second <= avg)
                {
                    dp[i][x + v[i].second][y] = std::min(dp[i][x + v[i].second][y], dp[i - 1][x][y] + (v[i].first != 1));
                }

                if (y + v[i].second <= avg)
                {
                    dp[i][x][y + v[i].second] = std::min(dp[i][x][y + v[i].second], dp[i - 1][x][y] + (v[i].first != 2));
                }

                
                dp[i][x][y] = std::min(dp[i][x][y], dp[i - 1][x][y] + (v[i].first != 3));
            }
        }
    }

    if (dp[n][avg][avg] != inf)
        std::cout << dp[n][avg][avg];
    else
        std::cout << -1;

    return 0;
}
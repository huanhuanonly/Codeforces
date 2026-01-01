/**
 * => P1833 樱花 ( @c 普及/提高− )
 * 
 * -> https://www.luogu.com.cn/problem/P1833
 * 
 * Submissions ~> https://www.luogu.com.cn/record/215705094 By huanhuanonly
 * 
 * @b Knapsack-DP ( @a mixed-knapsack-problem )
 * 
 * ----May 02, 2025 [20h:50m:01s]----
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
#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int tsh, tsm, teh, tem, n;
    scanf("%d:%d %d:%d %d", &tsh, &tsm, &teh, &tem, &n);

    int T = (teh * 60 + tem) - (tsh * 60 + tsm);

    std::vector<std::tuple<int, int, int>> v(n + 1);

    for (auto& [t, val, cnt] : v | std::views::drop(1))
    {
        std::cin >> t >> val >> cnt;
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(T + 1));

    for (int i = 1; i <= n; ++i)
    {
        const auto& [t, val, cnt] = v[i];

        if (cnt)
        {
            dp[i] = dp[i - 1];

            for (int c = 0; c < cnt; ++c)
            {
                for (int j = T; j >= t; --j)
                {
                    dp[i][j] = std::max(dp[i][j], dp[i][j - t] + val);
                }
            }
        }
        else for (int j = 1; j <= T; ++j)
        {
            if (j >= t)
                dp[i][j] = std::max({dp[i][j], dp[i - 1][j], dp[i][j - t] + val});
            else
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
        }
    }

    std::cout << *std::ranges::max_element(dp.back());

    return 0;
}
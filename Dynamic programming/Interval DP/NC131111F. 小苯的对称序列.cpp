/**
 * 牛客周赛 Round 138
 *
 * => F-小苯的对称序列 ( @c 1900 )
 *
 * -> https://ac.nowcoder.com/acm/contest/131111/F
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83172942 By huanhuanonly
 *
 * @b Interval-DP
 *
 * ----April 06, 2026 [18h:24m:32s]----
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

#if defined(__SIZEOF_INT128__)
using int128 = __int128;
using uint128 = unsigned __int128;
#endif

using real32 = float;
using real64 = double;

#if defined(__SIZEOF_FLOAT80__)
using real80 = __float80;
#endif

#if defined(__SIZEOF_FLOAT128__)
using real128 = __float128;
#endif

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        std::vector<int> v(n);

        std::vector<std::vector<int>> pos(1000 + 1);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i];
            pos[v[i]].push_back(i);
        }

        std::vector dp(n, std::vector(n, 0));

        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = 1;

            for (int j = i + 1; j < n; ++j)
            {
                dp[i][j] = 2;
            }
        }

        for (int k = 2; k < n; ++k)
        {
            for (int l = 0, r = k; r < n; ++l, ++r)
            {
                for (int i = l + 1; i <= r - 1; ++i)
                {
                    if (const int diff = v[l] + v[r] - v[i]; diff > 0 and diff < pos.size())
                    {
                        if (const auto it = std::ranges::upper_bound(pos[diff] | std::views::reverse, r, std::ranges::greater{}); it != pos[diff].rend() and l < *it)
                        {
                            dp[l][r] = std::max(dp[l][r], dp[i][*it] + 2);
                        }
                    }
                }
            }
        }

        int max = 0;

        for (int l = 0; l < n; ++l)
        {
            for (int r = l; r < n; ++r)
            {
                max = std::max(max, dp[l][r]);
            }
        }

        std::cout << max << '\n';
    }

    return 0;
}
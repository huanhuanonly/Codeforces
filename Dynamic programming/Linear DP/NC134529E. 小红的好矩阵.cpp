/**
 * 牛客周赛 Round 143
 *
 * => E-小红的好矩阵 ( @c 1700 )
 *
 * -> https://ac.nowcoder.com/acm/contest/134529/E
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83547039 By huanhuanonly
 *
 * @b Linear-DP
 *
 * ----May 10, 2026 [20h:31m:45s]----
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

    int n;
    std::cin >> n;

    std::vector<std::array<char, 2>> s(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> s[i][0];
    }

    for (int i = 0; i < n; ++i)
    {
        std::cin >> s[i][1];
    }

    if (n % 3)
    {
        std::cout << "-1\n";
        return 0;
    }

    auto $ = [&](int i, int type) -> int
    {
        switch (type)
        {
        case 0: return
            (s[i][0] != '1') + (s[i + 1][0] != '1') + (s[i + 2][0] != '0') +
            (s[i][1] != '1') + (s[i + 1][1] != '0') + (s[i + 2][1] != '0');
        case 1: return
            (s[i][0] != '0') + (s[i + 1][0] != '0') + (s[i + 2][0] != '1') +
            (s[i][1] != '0') + (s[i + 1][1] != '1') + (s[i + 2][1] != '1');
        case 2: return
            (s[i][0] != '1') + (s[i + 1][0] != '1') + (s[i + 2][0] != '1') +
            (s[i][1] != '0') + (s[i + 1][1] != '0') + (s[i + 2][1] != '0');
        case 3: return
            (s[i][0] != '0') + (s[i + 1][0] != '0') + (s[i + 2][0] != '0') +
            (s[i][1] != '1') + (s[i + 1][1] != '1') + (s[i + 2][1] != '1');
        case 4: return
            (s[i][0] != '1') + (s[i + 1][0] != '0') + (s[i + 2][0] != '0') +
            (s[i][1] != '1') + (s[i + 1][1] != '1') + (s[i + 2][1] != '0');
        case 5: return
            (s[i][0] != '0') + (s[i + 1][0] != '1') + (s[i + 2][0] != '1') +
            (s[i][1] != '0') + (s[i + 1][1] != '0') + (s[i + 2][1] != '1');
        default: return
            assert(false), std::numeric_limits<int>::max();
        }
    };

    std::vector<std::array<int, 6>> dp(n);

    for (int i = 0; i < 6; ++i)
    {
        dp[0][i] = $(0, i);
    }

    for (int i = 3; i < n; i += 3)
    {
        dp[i][0] = std::min(dp[i - 3][0], dp[i - 3][4]) + $(i, 0);
        dp[i][1] = std::min(dp[i - 3][1], dp[i - 3][5]) + $(i, 1);
        dp[i][2] = dp[i - 3][3] + $(i, 2);
        dp[i][3] = dp[i - 3][2] + $(i, 3);
        dp[i][4] = std::min(dp[i - 3][4], dp[i - 3][0]) + $(i, 4);
        dp[i][5] = std::min(dp[i - 3][5], dp[i - 3][1]) + $(i, 5);
    }

    std::cout << std::ranges::min(dp[n - 3]) << '\n';

    return 0;
}
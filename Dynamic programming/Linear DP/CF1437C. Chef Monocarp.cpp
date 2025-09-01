/**
 * Educational Codeforces Round 97 (Rated for Div. 2)
 * 
 * => C. Chef Monocarp ( @c 1800 )
 * 
 * -> https://codeforces.com/contest/1437/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/1437/submission/330851977 By huanhuanonly
 * 
 * @b Linear-DP
 * 
 * ----July 26, 2025 [01h:19m:15s]----
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
        int n;
        std::cin >> n;

        std::vector<int> v(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
        }

        std::ranges::sort(v);

        constexpr int inf = std::numeric_limits<int>::max() / 2;
        std::vector dp(n * 2 + 1, std::vector<int>(n + 1, inf));

        for (int i = 0; i < dp.size(); ++i)
        {
            dp[i][0] = 0;
        }

        for (int i = 1; i < dp.size(); ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][j - 1] + std::abs(v[j] - i));
            }
        }

        std::cout << dp.back().back() << '\n';
    }

    return 0;
}
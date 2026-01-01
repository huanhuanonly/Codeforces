/**
 * Codeforces Round 901 (Div. 2)
 * 
 * => D. Jellyfish and Mex ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/1875/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/1875/submission/341580372 By huanhuanonly
 * 
 * @b Linear-DP
 * 
 * ----October 03, 2025 [11h:41m:16s]----
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

        std::vector<int64> cnt(n + 1);

        for (int i = 1, v; i <= n; ++i)
        {
            std::cin >> v;
            
            if (v < cnt.size())
            {
                ++cnt[v];
            }
        }

        constexpr auto inf = std::numeric_limits<int64>::max() / 2;
        std::vector dp(n + 1, std::vector(n + 1, inf));

        const int MEX = std::ranges::find(cnt, 0) - cnt.begin();

        for (int mex = 0; mex <= n; ++mex)
        {
            dp[mex][0] = mex * cnt[0];
            
            for (int i = 1; i <= n; ++i)
            {
                dp[mex][i] = std::min(dp[mex][i - 1], dp[i][i - 1] + mex * cnt[i]);
            }
        }

        auto min = inf;

        for (int i = 1; i <= n; ++i)
        {
            min = std::min(min, dp[i][i - 1] + MEX * (cnt[i] - 1));
        }

        std::cout << min << '\n';
    }

    return 0;
}
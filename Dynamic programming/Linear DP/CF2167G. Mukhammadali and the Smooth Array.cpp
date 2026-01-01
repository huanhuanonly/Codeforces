/**
 * Codeforces Round 1062 (Div. 4)
 * 
 * => G. Mukhammadali and the Smooth Array ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/2167/problem/G
 * 
 * Submissions ~> https://codeforces.com/contest/2167/submission/346344596 By huanhuanonly
 * 
 * @b Linear-DP
 * 
 * ----October 29, 2025 [00h:48m:23s]----
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

        std::vector<int64> v(n + 1);
        std::vector<int64> c(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
        }

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> c[i];
        }

        auto s = v;
        std::ranges::sort(s);
        s.erase(std::ranges::unique(s).begin(), s.end());

        std::ranges::transform(v, v.begin(), [&](int64 i) -> int64
        {
            return std::ranges::lower_bound(s, i) - s.begin();
        });

        std::vector dp(n + 1, 0LL);

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[j] = dp[j] + (v[i] != j ? c[i] : 0);
            }

            for (int j = 2; j <= n; ++j)
            {
                dp[j] = std::min(dp[j], dp[j - 1]);
            }
        }

        std::cout << dp[n] << '\n';
    }

    return 0;
}
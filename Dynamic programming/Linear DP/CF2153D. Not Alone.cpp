/**
 * Codeforces Round 1057 (Div. 2)
 * 
 * => D. Not Alone ( @c 1800 )
 * 
 * -> https://codeforces.com/contest/2153/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2153/submission/343010921 By huanhuanonly
 * 
 * @b Linear-DP
 * 
 * ----October 11, 2025 [10h:41m:36s]----
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

        std::vector<int64> v(n + n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
            v[i + n] = v[i];
        }

        auto get = [&](const std::vector<int64>& arr) -> int64
        {
            if (arr.size() == 2)
            {
                return std::abs(arr[0] - arr[1]);
            }
            else
            {
                return std::max({arr[0], arr[1], arr[2]}) - std::min({arr[0], arr[1], arr[2]});
            }
        };

        constexpr int64 inf = std::numeric_limits<int64>::max() / 2;
        std::vector<int64> dp(n + 1);

        auto calc = [&](const auto& c) -> int64
        {
            dp[0] = 0;
            dp[1] = inf;
            
            for (int i = 2; i <= n; ++i)
            {
                dp[i] = dp[i - 2] + get({c[i], c[i - 1]});

                if (i - 3 >= 0)
                {
                    dp[i] = std::min(dp[i], dp[i - 3] + get({c[i], c[i - 1], c[i - 2]}));
                }
            }

            return dp[n];
        };

        int64 min = inf;

        min = std::min(min, calc(v));
        min = std::min(min, calc(v | std::views::drop(1)));
        min = std::min(min, calc(v | std::views::drop(2)));

        std::cout << min << '\n';
    }

    return 0;
}
/**
 * Codeforces Round 1046 (Div. 2)
 * 
 * => C. Against the Difference ( @c 1200 )
 * 
 * -> https://codeforces.com/contest/2136/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2136/submission/335974893 By huanhuanonly
 * 
 * @b Linear-DP
 * 
 * ----August 29, 2025 [01h:23m:54s]----
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

        std::vector<std::vector<int>> pos(n + 1);
        std::vector<int> cnt(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
            pos[v[i]].push_back(i);
        }

        std::vector<int> dp(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            dp[i] = dp[i - 1];

            if (cnt[v[i]] - v[i] + 1 >= 0)
            {
                dp[i] = std::max(dp[i], dp[pos[v[i]][cnt[v[i]] - v[i] + 1] - 1] + v[i]);
            }

            ++cnt[v[i]];
        }

        std::cout << dp[n] << '\n';
    }

    return 0;
}
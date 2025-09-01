/**
 * Codeforces Round 318 [RussianCodeCup Thanks-Round] (Div. 2)
 * 
 * => D. Bear and Blocks ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/574/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/574/submission/328516702 By huanhuanonly
 * 
 * @b Linear-DP
 * 
 * ----July 11, 2025 [19h:35m:30s]----
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

    int n;
    std::cin >> n;

    std::vector<int> dp(n + 2);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> dp[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        dp[i] = std::min(dp[i], dp[i - 1] + 1);
    }

    for (int i = n; i >= 1; --i)
    {
        dp[i] = std::min(dp[i], dp[i + 1] + 1);
    }

    std::cout << *std::ranges::max_element(dp);

    return 0;
}
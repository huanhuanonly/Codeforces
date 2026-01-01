/**
 * Codeforces Round 940 (Div. 2) and CodeCraft-23
 * 
 * => C. How Does the Rook Move? ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/1957/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/1957/submission/318828606 By huanhuanonly
 * 
 * @b Combinatorics and @b Counting-DP
 * 
 * ----May 08, 2025 [21h:00m:50s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, k;
        std::cin >> n >> k;

        std::vector<bool> marks(n + 1);

        for (int i = 0, value; i < k * 2; ++i)
        {
            std::cin >> value;
            marks[value] = true;
        }

        constexpr uint64 MOD = 1e9 + 7;

        std::vector<uint64> dp(std::count(marks.begin() + 1, marks.end(), false) + 1);
        dp[0] = 1;

        if (dp.size() > 1)
        {
            dp[1] = 1;
        }

        for (std::size_t i = 2; i < dp.size(); ++i)
        {
            dp[i] = (dp[i - 1] + 2 * (i - 1) * dp[i - 2]) % MOD;
        }

        std::cout << dp.back() << '\n';
    }

    return 0;
}
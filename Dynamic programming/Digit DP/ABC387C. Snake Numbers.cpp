/**
 * AtCoder Beginner Contest 387
 * 
 * => C - Snake Numbers ( @c 350 )
 * 
 * -> https://atcoder.jp/contests/abc387/tasks/abc387_c
 * 
 * Submissions ~> https://atcoder.jp/contests/abc387/submissions/61611682 By huanhuanonly
 * 
 * @b Digit-DP
 * 
 * ----January 11, 2025 [23h:35m:06s]----
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

    uint64 l, r;
    std::cin >> l >> r;

    auto eval = [&](uint64 n) -> uint64
    {
        if (n < 10)
        {
            return 0;
        }

        std::string upper_limit = std::to_string(n);

        constexpr uint64 inf = std::numeric_limits<uint64>::max();
        std::vector<std::vector<uint64>> dp(upper_limit.size(), std::vector<uint64>(10, inf));

        auto dfs = [&](const auto& dfs, int32 pos, int8 first, bool limit, bool lead) -> uint64
        {
            if (pos == upper_limit.size())
                return 1;

            if (not limit and not lead and dp[pos][first] != inf)
                return dp[pos][first];
            
            uint64 cnt = 0;

            for (int32 i = (lead and pos == upper_limit.size() - 2), up = std::min(limit ? upper_limit[pos] - '0' : 9, lead ? 9 : first - 1); i <= up; ++i)
            {
                /// @note that's not `limit and i == up`
                cnt += dfs(dfs, pos + 1, lead and i != 0 ? i : first, limit and i == (limit ? upper_limit[pos] - '0' : 9), lead and i == 0);
            }

            if (not limit and not lead)
                dp[pos][first] = cnt;
            
            return cnt;
        };

        return dfs(dfs, 0, 0, true, true);
    };

    std::cout << eval(r) - eval(l - 1);

    return 0;
}
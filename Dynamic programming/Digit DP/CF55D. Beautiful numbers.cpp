/**
 * Codeforces Beta Round 51
 * 
 * => D. Beautiful numbers ( @c 2500 )
 * 
 * -> https://codeforces.com/contest/55/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/55/submission/369306054 By huanhuanonly
 * 
 * @b Digit-DP and @b Number-theory ( @a least-common-multiple )
 * 
 * ----April 02, 2026 [11h:41m:40s]----
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

    constexpr auto maxlen = 19;
    constexpr auto maxlcm = *std::ranges::fold_left_first(std::views::iota(1, 10), std::lcm<int, int>);

    auto set = std::views::iota(1, 10) | std::ranges::to<std::set<int>>();

    for (int i = 2; i < 10; ++i)
    {
        for (const int& j : set)
        {
            set.insert(std::lcm(i, j));
        }
    }

    std::vector<int> $(maxlcm + 1);

    for (auto [it, i] = std::tuple(set.begin(), 0); it != set.end(); ++it, ++i)
    {
        $[*it] = i;
    }

    std::vector dp(maxlen, std::vector(maxlcm, std::vector(set.size(), ~0ULL)));
    
    int _;
    std::cin >> _;
    
    while (_--)
    {
        uint64 l, r;
        std::cin >> l >> r;

        auto dfs = [&](
            const auto& self,
            const std::string& s, int pos = 0,
            int num = 0, int lcm = 1,
            bool limit = true) -> uint64
        {
            if (pos == s.size())
            {
                return num % lcm == 0;
            }

            const auto dppos = maxlen - (int(s.size()) - pos);

            if (not limit and ~dp[dppos][num][$[lcm]])
            {
                return dp[dppos][num][$[lcm]];
            }

            uint64 sum = 0;

            for (int i = 0, j = limit ? s[pos] - '0' : 9; i <= j; ++i)
            {
                sum += self(
                    self, s, pos + 1,
                    (num * 10 + i) % maxlcm,
                    i ? std::lcm(lcm, i) : lcm,
                    limit and i == j);
            }

            if (not limit)
            {
                dp[dppos][num][$[lcm]] = sum;
            }

            return sum;
        };

        std::cout << dfs(dfs, std::to_string(r)) - dfs(dfs, std::to_string(l - 1)) << '\n';
    }

    return 0;
}
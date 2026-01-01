/**
 * Educational Codeforces Round 185 (Rated for Div. 2)
 * 
 * => F. Build XOR on a Segment ( @c 2600 )
 * 
 * -> https://codeforces.com/contest/2170/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/2170/submission/351875111 By huanhuanonly
 * 
 * @b Bitmask-DP and @b Offline
 * @b Bitwise-XOR
 * 
 * ----December 04, 2025 [22h:13m:16s]----
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

    constexpr auto bitcnt = uint32(12U);
    constexpr auto maxval = uint32(1U << bitcnt) - 1;

    uint32 n;
    std::cin >> n;

    std::vector<uint32> v(n + 1);

    for (uint32 i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
    }

    std::vector dp(2, std::vector(maxval + 1, std::vector(bitcnt + 1, uint32{})));

    uint32 cpos = 0;

    auto calc = [&]() -> void
    {
        const auto& r = ++cpos;

        for (uint32 x = 1; x <= maxval; ++x)
        {
            for (uint32 c = 1; c <= bitcnt; ++c)
            {
                dp[1][x][c] = std::max(dp[0][x][c], dp[0][x ^ v[r]][c - 1]);
            }
        }

        dp[1][v[r]][1] = r;

        std::ranges::swap(dp[0], dp[1]);
    };

    uint32 q;
    std::cin >> q;

    struct question
    {
        uint32 l, r, x, i;
    };
 
    std::vector<question> queries(q);
    std::vector<uint32> ans(q);
 
    for (uint32 i = 0; i < q; ++i)
    {
        auto& [l, r, x, idx] = queries[i];
        
        std::cin >> l >> r >> x;
        idx = i;
    }
 
    std::ranges::sort(queries, {}, &question::r);

    for (const auto& [l, r, x, i] : queries)
    {
        for (; cpos < r; calc());

        ans[i] = std::ranges::find_if(dp[0][x], [l](uint32 i) -> bool {
            return l <= i;
        }) - dp[0][x].begin();

        if (ans[i] == dp[0][x].size())
        {
            ans[i] = 0;
        }
    }

    for (uint32 i : ans)
    {
        std::cout << i << ' ';
    }

    return 0;
}
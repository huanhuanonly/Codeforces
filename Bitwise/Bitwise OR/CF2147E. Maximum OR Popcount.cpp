/**
 * Codeforces Global Round 29 (Div. 1 + Div. 2)
 * 
 * => E. Maximum OR Popcount ( @c 2300 )
 * 
 * -> https://codeforces.com/contest/2147/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2147/submission/349517601 By huanhuanonly
 * 
 * @b Bitwise-OR and @b Greedy
 * 
 * ----November 18, 2025 [10h:49m:00s]----
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
        uint64 n, q;
        std::cin >> n >> q;

        constexpr auto bitcount = 32ULL;

        std::array<uint64, bitcount> ans{};

        constexpr auto inf = std::numeric_limits<uint64>::max() / 2;
        
        std::vector<uint64> v(n);

        uint64 mask = 0;

        for (uint64 i = 0; i < n; ++i)
        {
            std::cin >> v[i];
            mask |= v[i];
        }

        uint64 sum = 0;
        
        for (uint64 c = std::popcount(mask) + 1; c < bitcount; ++c)
        {
            const uint64 lowbit = ~mask & -~mask;
            const uint64 crz    = std::countr_zero(lowbit);

            for (uint64 b = crz + 1; b--; )
            {
                const auto proj = [b](uint64 x) -> uint64
                {
                    return x & (1ULL << b + 1) - 1;
                };

                const auto it = std::ranges::max_element(v, {}, proj);

                if (*it & (1ULL << b))
                {
                    continue;
                }

                sum += (1ULL << b) - proj(*it);
                *it += (1ULL << b) - proj(*it);
            }

            ans[c] = sum;
            mask |= lowbit;
        }

        while (q--)
        {
            uint64 c;
            std::cin >> c;

            std::cout << std::ranges::upper_bound(ans, c) - 1 - ans.begin() << '\n';
        }
    }

    return 0;
}
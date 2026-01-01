/**
 * Codeforces Round 871 (Div. 4)
 * 
 * => H. Don't Blame Me ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/1829/problem/H
 * 
 * Submissions ~> https://codeforces.com/contest/1829/submission/339078790 By huanhuanonly
 * 
 * @b Bitmask-DP and @b Combinatorics and @b Bitwise-AND
 * 
 * ----September 17, 2025 [21h:14m:23s]----
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

template<typename _Tp>
_Tp binary_exponentiation(_Tp __fv, _Tp __sv, _Tp __mod)
{
    __fv %= __mod;

    _Tp ans = 1;
    for (; __sv; __fv = (__fv * __fv) % __mod, __sv >>= 1)
        if (__sv & 1)
            ans = (ans * __fv) % __mod;
    return ans;
}

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
        uint32 n, k;
        std::cin >> n >> k;

        constexpr uint32 maxk = 6U;
        constexpr uint32 maxv = (1U << maxk) - 1U;
        constexpr uint64 mod = 1e9 + 7;

        std::vector dp(maxv + 1, 0ULL);

        for (uint32 i = 0, v; i < n; ++i)
        {
            std::cin >> v;
            ++dp[v];
        }

        std::ranges::transform(dp, dp.begin(), [](uint64 v) -> uint64 {
            return binary_exponentiation(2ULL, v, mod) - 1;
        });

        for (uint32 l = 0; l <= maxv; ++l)
        {
            for (uint32 r = 0; r < l; ++r)
            {
                (dp[l & r] += dp[l] * dp[r] % mod) %= mod;
            }
        }

        uint64 sum = 0;

        for (uint32 v = 0; v <= maxv; ++v)
        {
            if (std::popcount(v) == k)
            {
                (sum += dp[v]) %= mod;
            }
        }

        std::cout << sum << '\n';
    }

    return 0;
}
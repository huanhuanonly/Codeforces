/**
 * Educational Codeforces Round 177 (Rated for Div. 2)
 * 
 * => D. Even String ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/2086/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2086/submission/317729930 By huanhuanonly
 * 
 * @b Combinatorics and @b Linear-DP
 * 
 * ----April 29, 2025 [19h:29m:21s]----
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

inline namespace huanhuanonly
{
template<typename _Tp, typename _Mt>
_Tp fast_power(_Tp __fv, _Tp __sv, _Mt __mod)
{
    __fv %= __mod;

    _Tp ans = 1;
    for (; __sv; __fv = (__fv * __fv) % __mod, __sv >>= 1)
        if (__sv & 1)
            ans = (ans * __fv) % __mod;
    return ans;
}
}

inline namespace huanhuanonly {
    inline namespace combinatorics
{
template<std::size_t _Mod = std::numeric_limits<std::size_t>::max()>
constexpr std::size_t P(std::size_t n, std::size_t k)
{
    std::size_t sum = 1;

    for (std::size_t i = n - k + 1; i <= n; ++i)
    {
        (sum *= i) %= _Mod;
    }

    return sum;
}

template<std::size_t _Mod = std::numeric_limits<std::size_t>::max()>
constexpr std::size_t P(std::size_t n)
{ return P<_Mod>(n, n); }

template<std::size_t _Mod = std::numeric_limits<std::size_t>::max()>
constexpr std::size_t A(std::size_t n, std::size_t k)
{ return P<_Mod>(n, k); }

template<std::size_t _Mod = std::numeric_limits<std::size_t>::max()>
constexpr std::size_t A(std::size_t n)
{ return P<_Mod>(n, n); }

template<std::size_t _Mod = std::numeric_limits<std::size_t>::max()>
constexpr std::size_t C(std::size_t n, std::size_t k)
{
    static_assert(_Mod >= 2);
    return P<_Mod>(n, k) * fast_power(P<_Mod>(k), _Mod - 2, _Mod) % _Mod;
}
}}

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
        constexpr uint64 MOD = 998'244'353;

        std::array<uint64, 26> v;
        
        for (auto& i : v)
        {
            std::cin >> i;
        }

        uint64 n = std::reduce(v.begin(), v.end());
        
        uint64 odd = n / 2 + n % 2, even = n / 2;

        std::vector<uint64> dp(odd + 1);
        dp[0] = 1;

        auto condition = std::bind(
            &std::greater_equal<uint64>::operator(),
            static_cast<std::greater_equal<uint64>*>(nullptr),
            std::placeholders::_1,
            1);
        
        for (auto i : v | std::views::filter(condition))
        {
            for (int j = int(dp.size()) - i; j-- > 0; )
            {
                (dp[j + i] += dp[j]) %= MOD;
            }
        }

        uint64 ans = dp[odd] * P<MOD>(odd) % MOD * P<MOD>(even) % MOD;

        for (auto i : v | std::views::filter(condition))
        {
            (ans *= fast_power<uint64>(P<MOD>(i), MOD - 2, MOD) % MOD) %= MOD;
        }

        std::cout << ans << '\n';
    }

    return 0;
}
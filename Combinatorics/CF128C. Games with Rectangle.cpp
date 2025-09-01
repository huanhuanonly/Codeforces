/**
 * Codeforces Beta Round 94 (Div. 1 Only)
 * 
 * => C. Games with Rectangle ( @c 2000 )
 * 
 * -> https://codeforces.com/contest/128/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/128/submission/329220611 By huanhuanonly
 * 
 * @b Combinatorics
 * 
 * ----July 17, 2025 [00h:27m:28s]----
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

inline namespace huanhuanonly {
    inline namespace combinatorics
{
template<std::size_t _Mod = std::numeric_limits<std::size_t>::max()>
constexpr std::size_t P(std::size_t n, std::size_t k)
{
    std::size_t sum = 1;

    for (std::size_t i = n - k + 1; i <= n; ++i)
    {
        if constexpr (_Mod != std::numeric_limits<std::size_t>::max())
        {
            (sum *= i) %= _Mod;
        }
        else
        {
            sum *= i;
        }
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

    if constexpr (_Mod != std::numeric_limits<std::size_t>::max())
    {
        return P<_Mod>(n, k) * binary_exponentiation(P<_Mod>(k), _Mod - 2, _Mod) % _Mod;
    }
    else
    {
        return P<_Mod>(n, k) / P<_Mod>(k);
    }
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

    int n, m, k;
    std::cin >> n >> m >> k;

    if (k >= (std::min(n, m) + 1) / 2)
    {
        std::cout << 0;
    }
    else
    {
        constexpr uint64 mod = 1e9 + 7;
        
        std::cout << C<mod>(n + 1 - 2, 2 * k) * C<mod>(m + 1 - 2, 2 * k) % mod;
    }

    return 0;
}
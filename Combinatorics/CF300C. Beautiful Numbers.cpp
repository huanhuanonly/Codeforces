/**
 * Codeforces Round 181 (Div. 2)
 * 
 * => C. Beautiful Numbers ( @c 1800 )
 * 
 * -> https://codeforces.com/contest/300/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/300/submission/329298991 By huanhuanonly
 * 
 * @b Combinatorics
 * 
 * ----July 17, 2025 [16h:08m:06s]----
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
constexpr auto factorial_max_length = static_cast<std::size_t>(1e6 + 1);

template<auto _Mod>
static auto factorial{ []() constexpr
{
    std::array<std::size_t, factorial_max_length> a{1};

    for (std::size_t i = 1; i < a.size(); ++i)
    {
        a[i] = a[i - 1] * i % _Mod;
    }

    return a;
}() };

template<std::size_t _Mod = std::numeric_limits<std::size_t>::max()>
constexpr std::size_t P(std::size_t n, std::size_t k)
{
    assert (k <= n);
    assert (std::max(n, k) < factorial_max_length);

    if constexpr (_Mod != std::numeric_limits<std::size_t>::max())
    {
        return factorial<_Mod>[n] * binary_exponentiation(factorial<_Mod>[n - k], _Mod - 2, _Mod) % _Mod;
    }
    else
    {
        return factorial<_Mod>[n] / factorial<_Mod>[n - k];
    }
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

    uint64 a, b, n;
    std::cin >> a >> b >> n;

    constexpr uint64 mod = 1e9 + 7;

    uint64 sum = a * n;

    uint64 diff = b - a;

    auto check = [a, b](uint64 x) -> bool
    {
        for (; x; x /= 10)
        {
            if (uint64 value = x % 10; value != a and value != b)
            {
                return false;
            }
        }

        return true;
    };

    uint64 ans = 0;

    for (uint64 i = 0; i <= n; ++i)
    {
        if (check(sum))
        {
            (ans += C<mod>(n, i)) %= mod;
        }

        sum += diff;
    }

    std::cout << ans;

    return 0;
}
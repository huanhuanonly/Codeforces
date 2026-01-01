/**
 * Codeforces Round 964 (Div. 4)
 * 
 * => F. Expected Median ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/1999/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/1999/submission/345274166 By huanhuanonly
 * 
 * @b Combinatorics
 * 
 * ----October 23, 2025 [11h:06m:08s]----
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
constexpr auto factorial_max_length = static_cast<std::size_t>(2e5 + 1);

template<auto _Mod>
constexpr auto factorial{ []() constexpr
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
    if (not (k <= n))
    {
        return 0;
    }

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

    int _;
    std::cin >> _;

    while (_--)
    {
        uint64 n, k;
        std::cin >> n >> k;

        std::array<uint64, 2> cnt{};

        for (int i = 0, v; i < n; ++i)
        {
            std::cin >> v;
            ++cnt[v];
        }

        constexpr uint64 mod = 1e9 + 7;

        uint64 sum = 0;

        for (uint64 i = k / 2 + 1; i <= cnt[1]; ++i)
        {
            if (k >= i)
            {
                sum += C<mod>(cnt[1], i) * C<mod>(cnt[0], k - i) % mod;
                sum %= mod;
            }
        }

        std::cout << sum << '\n';
    }

    return 0;
}
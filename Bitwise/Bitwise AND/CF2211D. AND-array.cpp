/**
 * Nebius Round 2 (Codeforces Round 1088, Div. 1 + Div. 2)
 *
 * => D. AND-array ( @c 1900 )
 *
 * -> https://codeforces.com/contest/2211/problem/D
 *
 * Submissions ~> https://codeforces.com/contest/2211/submission/369025454 By huanhuanonly
 *
 * @b Bitwise-AND and @b Combinatorics
 *
 * ----April 01, 2026 [01h:11m:21s]----
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

inline namespace huanhuanonly {
    inline namespace math
{
template<typename _Tp>
[[nodiscard]] constexpr _Tp binary_exponentiation(_Tp __lhs, _Tp __rhs, _Tp __mod)
{
    auto res = static_cast<_Tp>(1);

    for (__lhs %= __mod; __rhs; __lhs = (__lhs * __lhs) % __mod, __rhs >>= 1)
    {
        if (__rhs & 1)
        {
            res = (res * __lhs) % __mod;
        }
    }

    return res;
}
}} // namespace huanhuanonly::math

inline namespace huanhuanonly {
    inline namespace math {
        inline namespace combinatorics
{
using comb_value_type = uint64;

constexpr auto comb_nmod = static_cast<comb_value_type>(0);

constexpr auto factorial_max_length = static_cast<std::size_t>(2e5 + 1);

template<comb_value_type _Mod = comb_nmod>
constexpr auto factorial{ []() constexpr
{
    std::array<comb_value_type, factorial_max_length> a{1};

    for (std::size_t i = 1; i < a.size(); ++i)
    {
        if constexpr (_Mod != comb_nmod)
        {
            a[i] = a[i - 1] * i % _Mod;
        }
        else
        {
            a[i] = a[i - 1] * i;
        }
    }

    return a;
}() };

template<comb_value_type _Mod = comb_nmod>
[[nodiscard]] constexpr comb_value_type C(comb_value_type n, comb_value_type k)
{
    if (n < k)
    {
        return 0;
    }

    if constexpr (_Mod != comb_nmod)
    {
        return factorial<_Mod>[n] * binary_exponentiation(factorial<_Mod>[n - k] * factorial<_Mod>[k] % _Mod, _Mod - 2, _Mod) % _Mod;
    }
    else
    {
        return factorial<_Mod>[n] / (factorial<_Mod>[n - k] * factorial<_Mod>[k]);
    }
}

template<comb_value_type _Mod>
[[nodiscard]] constexpr comb_value_type lucas(comb_value_type n, comb_value_type k)
{
    static_assert(_Mod != comb_nmod and _Mod > 1, "_Mod is required and must be a prime number.");

    if (k == 0)
    {
        return 1;
    }
    else
    {
        return C<_Mod>(n % _Mod, k % _Mod) * lucas<_Mod>(n / _Mod, k / _Mod) % _Mod;
    }
}

template<comb_value_type _Mod = comb_nmod>
[[nodiscard]] constexpr comb_value_type P(comb_value_type n, comb_value_type k)
{
    if (n < k)
    {
        return 0;
    }

    if constexpr (_Mod != comb_nmod)
    {
        assert(n < factorial_max_length);
        return factorial<_Mod>[n] * binary_exponentiation(factorial<_Mod>[n - k], _Mod - 2, _Mod) % _Mod;
    }
    else
    {
        assert(n < factorial_max_length);
        return factorial<_Mod>[n] / factorial<_Mod>[n - k];
    }
}

template<comb_value_type _Mod = comb_nmod>
[[nodiscard]] constexpr comb_value_type P(comb_value_type n)
{ return P<_Mod>(n, n); }

template<comb_value_type _Mod = comb_nmod>
[[nodiscard]] constexpr comb_value_type A(comb_value_type n, comb_value_type k)
{ return P<_Mod>(n, k); }

template<comb_value_type _Mod = comb_nmod>
[[nodiscard]] constexpr comb_value_type A(comb_value_type n)
{ return P<_Mod>(n, n); }

template<comb_value_type _MaxN, comb_value_type _MaxK, comb_value_type _Mod = comb_nmod>
[[nodiscard]] constexpr auto comb_table() noexcept
{
    using table_type = std::array<std::array<comb_value_type, _MaxK>, _MaxN>;

    constexpr table_type table{ []() constexpr
        {
            table_type a{};

            for (std::size_t i = 0; i < a.size(); ++i)
            {
                a[i][0] = a[i][i] = 1;

                for (std::size_t j = 1; j < i; ++j)
                {
                    if constexpr (_Mod != comb_nmod)
                    {
                        a[i][j] = (a[i - 1][j] + a[i - 1][j - 1]) % _Mod;
                    }
                    else
                    {
                        a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
                    }
                }
            }

            return a;
        }()
    };

    return [&table](comb_value_type n, comb_value_type k) constexpr -> comb_value_type { return table[n][k]; };
}
}}} // namespace huanhuanonly::math::combinatorics

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        std::vector<uint64> b(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> b[i];
        }

        constexpr uint64 mod = 1e9 + 7;
        constexpr int bitcnt = 29;

        std::array<uint64, bitcnt> cnt{};

        for (int k = n; k >= 1; --k)
        {
            for (int i = 0; i < bitcnt; ++i)
            {
                if (b[k] & (uint64{1} << i))
                {
                    cnt[i] = k;

                    for (int j = 1; j < k; ++j)
                    {
                        (b[j] += mod - (uint64{1} << i) * C<mod>(k, j) % mod) %= mod;
                    }
                }
            }
        }

        std::vector<uint64> ans(n);

        for (int i = 0; i < bitcnt; ++i)
        {
            for (int j = 0; j < cnt[i]; ++j)
            {
                ans[j] |= uint64{1} << i;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            std::cout << ans[i] << " \n"[i + 1 == n];
        }
    }

    return 0;
}
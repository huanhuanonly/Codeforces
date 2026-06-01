/**
 * 牛客周赛 Round 143
 *
 * => C-小红的因子幂和 ( @c 1200 )
 *
 * -> https://ac.nowcoder.com/acm/contest/134529/C
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83542834 By huanhuanonly
 *
 * @b Number-theory ( @a prime-factorization )
 * @b Dfs-enumeration
 *
 * ----May 10, 2026 [19h:43m:56s]----
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
template<
    typename _Tp, std::unsigned_integral _Up, typename _Mp,
    typename _MulOp = std::multiplies<_Tp>, typename _ModOp = std::modulus<void>>
requires
    requires(_MulOp __op, _Tp __x) { { __op(__x, __x) } -> std::convertible_to<_Tp>; } and
    requires(_ModOp __op, _Tp __lhs, _Mp __rhs) { { __op(__lhs, __rhs) } -> std::convertible_to<_Tp>; }
[[nodiscard]] constexpr _Tp
binary_exponentiation(_Tp __lhs, _Up __rhs, _Mp __mod, _MulOp __mul_op = {}, _ModOp __mod_op = {})
{
    auto result = static_cast<_Tp>(1);

    for (__lhs = __mod_op(__lhs, __mod); __rhs; __lhs = __mod_op(__mul_op(__lhs, __lhs), __mod), __rhs >>= 1)
    {
        if (__rhs & 1)
        {
            result = __mod_op(__mul_op(result, __lhs), __mod);
        }
    }

    return result;
}

template<typename _Tp, std::unsigned_integral _Up, typename _MulOp = std::multiplies<_Tp>>
requires requires(_MulOp __op, _Tp __x) { { __op(__x, __x) } -> std::convertible_to<_Tp>; }
[[nodiscard]] constexpr _Tp
binary_exponentiation(_Tp __lhs, _Up __rhs, _MulOp __mul_op = {})
{
    auto result = static_cast<_Tp>(1);

    for (; __rhs; __lhs = __mul_op(__lhs, __lhs), __rhs >>= 1)
    {
        if (__rhs & 1)
        {
            result = __mul_op(result, __lhs);
        }
    }

    return result;
}
}} // namespace huanhuanonly::math

inline namespace huanhuanonly {
    inline namespace math
{
template<typename _Tp>
[[nodiscard]] std::map<_Tp, int>
prime_factorization_with_exponents(_Tp __n)
{
    std::map<_Tp, int> res;

    for (_Tp i = 2; i * i <= __n; ++i)
    {
        if (__n % i == 0)
        {
            for (auto& c = res[i]; __n % i == 0; __n /= i, ++c);
        }
    }

    if (__n != 1)
    {
        ++res[__n];
    }

    return res;
}
}} // namespace huanhuanonly::math

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    uint64 x, y;
    std::cin >> x >> y;

    constexpr uint64 mod = 1e9 + 7;

    auto map = prime_factorization_with_exponents(x);

    for (const auto& [key, value] : prime_factorization_with_exponents(y))
    {
        map[key] += value;
    }

    std::vector v(map.begin(), map.end());

    uint64 ans = 0;

    auto dfs = [&](const auto& self, int p, uint64 d) -> void
    {
        if (p == v.size())
        {
            (ans += binary_exponentiation(d, d, mod)) %= mod;
            return;
        }

        self(self, p + 1, d);

        for (int i = 0; i < v[p].second; ++i)
        {
            self(self, p + 1, d *= v[p].first);
        }
    };

    dfs(dfs, 0, 1);

    std::cout << ans << '\n';

    return 0;
}
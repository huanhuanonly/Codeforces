/**
 * Tokio Marine & Nichido Fire Insurance Programming Contest 2026 (AtCoder Beginner Contest 459)
 *
 * => E - Select from Subtrees ( @c 450 )
 *
 * -> https://atcoder.jp/contests/abc459/tasks/abc459_e
 *
 * Submissions ~> https://atcoder.jp/contests/abc459/submissions/76173707 By huanhuanonly
 *
 * @b Dfs on @a Trees
 * @b Combinatorics
 *
 * ----May 27, 2026 [23h:35m:55s]----
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

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 2; i <= n; ++i)
    {
        int fa;
        std::cin >> fa;

        e[fa].push_back(i);
    }

    std::vector<uint64> c(n + 1), d(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> c[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> d[i];
    }

    constexpr uint64 mod = 998244353;

    auto C = [](uint64 n, uint64 k) -> uint64
    {
        uint64 prod = 1;

        for (uint64 i = n - k + 1; i <= n; ++i)
        {
            (prod *= i % mod) %= mod;
        }

        uint64 div = 1;

        for (uint64 i = 2; i <= k; ++i)
        {
            (div *= i) %= mod;
        }

        return prod * binary_exponentiation(div, mod - 2, mod) % mod;
    };

    uint64 ans = 1;

    auto dfs = [&](const auto& self, int u) -> uint64
    {
        uint64 cnt = c[u];

        for (int v : e[u])
        {
            cnt += self(self, v);
        }

        if (cnt >= d[u])
        {
            (ans *= C(cnt, d[u])) %= mod;
            return cnt - d[u];
        }
        else
        {
            ans = 0;
            return 0;
        }
    };

    dfs(dfs, 1);

    std::cout << ans << '\n';

    return 0;
}
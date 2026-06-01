/**
 * The 2023 ICPC Asia Xi'an Regional Contest
 *
 * => G. An Easy Math Problem
 *
 * -> https://qoj.ac/contest/1784/problem/9248/statement/en
 *
 * Submissions ~> https://qoj.ac/submission/2344782 By huanhuanonly
 *
 * @b Number-theory ( @a prime-factorization )
 *
 * ----May 09, 2026 [09h:42m:14s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        uint64 n;
        std::cin >> n;

        uint64 ans = 1;

        for (const auto& [key, cnt] : prime_factorization_with_exponents(n))
        {
            ans *= cnt * 2 + 1;
        }

        std::cout << (ans + 1) / 2 << '\n';
    }

    return 0;
}
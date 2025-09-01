/**
 * Mirrativ Programming Contest 2025 (AtCoder Beginner Contest 414)
 * 
 * => E - Count A%B=C ( @c 475 )
 * 
 * -> https://atcoder.jp/contests/abc414/tasks/abc414_e
 * 
 * Submissions ~> https://atcoder.jp/contests/abc414/submissions/67549900 By huanhuanonly
 * 
 * @b Number-theory ( @a division-based-decomposition )
 * 
 * ----July 12, 2025 [21h:40m:36s]----
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
_Tp binary_multiplication(_Tp __fv, _Tp __sv, _Tp __mod)
{
    __fv %= __mod, __sv %= __mod;

    _Tp res = 0;
    for (; __sv; __fv = (__fv + __fv) % __mod, __sv >>= 1)
        if (__sv & 1)
            res = (res + __fv) % __mod;
    return res;
}

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

    int64 n;
    std::cin >> n;

    constexpr int64 mod = 998244353;

    int64 ans = binary_multiplication(n, n + 1, mod) * binary_exponentiation(2LL, mod - 2, mod);

    int64 sum = 0;

    for (int64 l = 1, r; l <= n; l = r + 1)
    {
        r = n / (n / l);

        sum += binary_multiplication(n / l, r - l + 1, mod);
        sum %= mod;
    }

    std::cout << (ans + mod - sum) % mod;

    return 0;
}
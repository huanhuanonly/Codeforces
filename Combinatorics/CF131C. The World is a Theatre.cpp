/**
 * Codeforces Beta Round 95 (Div. 2)
 * 
 * => C. The World is a Theatre ( @c 1400 )
 * 
 * -> https://codeforces.com/contest/131/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/131/submission/345438386 By huanhuanonly
 * 
 * @b Combinatorics
 * 
 * ----October 24, 2025 [11h:55m:06s]----
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

inline namespace huanhuanonly {
    inline namespace combinatorics
{
template<uint128 _Mod = std::numeric_limits<uint128>::max()>
constexpr uint128 P(uint128 n, uint128 k)
{
    uint128 sum = 1;

    for (uint128 i = n - k + 1; i <= n; ++i)
    {
        if constexpr (_Mod != std::numeric_limits<uint128>::max())
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

template<uint128 _Mod = std::numeric_limits<uint128>::max()>
constexpr uint128 P(uint128 n)
{ return P<_Mod>(n, n); }

template<uint128 _Mod = std::numeric_limits<uint128>::max()>
constexpr uint128 A(uint128 n, uint128 k)
{ return P<_Mod>(n, k); }

template<uint128 _Mod = std::numeric_limits<uint128>::max()>
constexpr uint128 A(uint128 n)
{ return P<_Mod>(n, n); }

template<uint128 _Mod = std::numeric_limits<uint128>::max()>
constexpr uint128 C(uint128 n, uint128 k)
{
    static_assert(_Mod >= 2);

    if constexpr (_Mod != std::numeric_limits<uint128>::max())
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

    uint64 n, m, t;
    std::cin >> n >> m >> t;

    uint64 sum = 0;

    for (uint64 i = 4; i <= n and t - i >= 1; ++i)
    {
        sum += C(n, i) * C(m, t - i);
    }

    std::cout << sum;

    return 0;
}
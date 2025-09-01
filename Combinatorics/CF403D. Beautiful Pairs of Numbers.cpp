/**
 * Codeforces Round 236 (Div. 1)
 * 
 * => D. Beautiful Pairs of Numbers ( @c 2300 )
 * 
 * -> https://codeforces.com/contest/403/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/403/submission/325907478 By huanhuanonly
 * 
 * @b Combinatorics and @b Linear-DP
 * 
 * ----June 25, 2025 [01h:02m:25s]----
*/

/// @brief This is an @c interesting problem!

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
constexpr _Tp binary_exponentiation(_Tp __fv, _Tp __sv, _Tp __mod)
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
template<auto _Mod>
constexpr auto factorial{ []() constexpr
{
    std::array<std::size_t, 1000 + 1> a{1};

    for (std::size_t i = 1; i < a.size(); ++i)
    {
        a[i] = a[i - 1] * i % _Mod;
    }

    return a;
}() };

template<std::size_t _Mod = std::numeric_limits<std::size_t>::max()>
constexpr std::size_t P(std::size_t n, std::size_t k)
{
    return factorial<_Mod>[n] * binary_exponentiation(factorial<_Mod>[n - k], _Mod - 2, _Mod) % _Mod;
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
    return P<_Mod>(n, k) * binary_exponentiation(P<_Mod>(k), _Mod - 2, _Mod) % _Mod;
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

    constexpr uint64 mod = 1e9 + 7;
    constexpr uint64 N = 1000, K = 44;

    std::vector<int> sum(K + 1);
    
    for (int i = 1; i < sum.size(); ++i)
    {
        sum[i] = sum[i - 1] + i;
    }

    // [Number of intervals] [Total length of all intervals]
    std::vector dp(K + 1, std::vector(N + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= K; ++i)
    {
        for (int j = sum[i]; j <= N; ++j)
        {
            // Increase the length of every interval by one, or
            // add a new interval of length one and then proceed in the same way
            dp[i][j] = (dp[i][j - i] + dp[i - 1][j - i]) % mod;
        }
    }

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, k;
        std::cin >> n >> k;

        if (k >= sum.size() or n < sum[k])
        {
            std::cout << 0 << '\n';
        }
        else if (n - sum[k] == 0)
        {
            std::cout << A<mod>(k) << '\n';
        }
        else
        {
            int ans = 0;

            for (int i = sum[k]; i <= n; ++i)
            {
                ans += dp[k][i] * C<mod>(n - i + k + 1 - 1, k + 1 - 1) % mod;
                ans %= mod;
            }

            std::cout << A<mod>(k) * ans % mod << '\n';
        }
    }

    return 0;
}
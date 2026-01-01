/**
 * Codeforces Round 448 (Div. 2)
 * 
 * => C. Square Subsets ( @c 2000 )
 * 
 * -> https://codeforces.com/contest/895/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/895/submission/353741186 By huanhuanonly
 * 
 * @b Bitmask-DP
 * @b Counting-DP
 * @b Combinatorics
 * 
 * ----December 17, 2025 [01h:02m:25s]----
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

template<typename _Container = std::vector<int>>
[[nodiscard]] constexpr _Container primes_in_range(std::size_t __n)
{
    _Container primes;

    std::vector<bool> vis(__n + 1);

    vis[0] = vis[1] = true;

    for (std::size_t i = 2; i <= __n; ++i)
    {
        if (not vis[i])
        {
            primes.push_back(static_cast<_Container::value_type>(i));
        }

        for (const auto p : primes | std::views::take_while([__n, i](auto p) -> bool { return i * p <= __n; }))
        {
            vis[i * p] = true;

            if (i % p == 0)
            {
                break;
            }
        }
    }

    return primes;
}

template<typename _Tp>
[[nodiscard]] std::vector<_Tp> prime_factorization(_Tp __n)
{
    std::vector<_Tp> res;

    for (int i = 2; i * i <= __n; ++i)
    {
        for (; __n % i == 0; __n /= i)
        {
            res.push_back(i);
        }
    }

    if (__n != 1)
    {
        res.push_back(__n);
    }

    return res;
}

template<typename _Tp>
[[nodiscard]] constexpr _Tp binary_exponentiation(_Tp __fv, _Tp __sv, _Tp __mod)
{
    auto res = static_cast<_Tp>(1);

    for (__fv %= __mod; __sv; __fv = (__fv * __fv) % __mod, __sv >>= 1)
    {
        if (__sv & 1)
        {
            res = (res * __fv) % __mod;
        }
    }

    return res;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    constexpr uint64 maxv = 70;

    const auto primes = primes_in_range(maxv);

    std::vector<int> masks(maxv + 1);
    
    for (int i = 1; i <= maxv; ++i)
    {
        for (int p : prime_factorization(i))
        {
            masks[i] ^= 1 << std::ranges::lower_bound(primes, p) - primes.begin();
        }
    }

    int n;
    std::cin >> n;

    std::vector<int> cnt(maxv + 1);

    for (int i = 1, v; i <= n; ++i)
    {
        std::cin >> v;
        ++cnt[v];
    }

    constexpr uint64 mod = 1e9 + 7;

    std::vector dp(2, std::vector(1 << primes.size(), uint64{}));

    dp[0][0] = 1;

    for (int i = 1; i <= maxv; ++i)
    {
        if (cnt[i] == 0)
        {
            dp[1] = dp[0];
        }
        else for (int mask = 0; mask < (1 << primes.size()); ++mask)
        {
            dp[1][mask] = dp[0][mask ^ masks[i]] * binary_exponentiation<uint64>(2, cnt[i] - 1, mod) % mod;
            dp[1][mask] += dp[0][mask] * binary_exponentiation<uint64>(2, cnt[i] - 1, mod) % mod;
            
            dp[1][mask] %= mod;
        }

        std::ranges::swap(dp[0], dp[1]);
    }

    std::cout << (dp[0][0] + mod - 1) % mod;

    return 0;
}
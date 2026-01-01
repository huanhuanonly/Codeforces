/**
 * Codeforces Round 1065 (Div. 3)
 * 
 * => G. Sakura Adachi and Optimal Sequences ( @c 2000 )
 * 
 * -> https://codeforces.com/contest/2171/problem/G
 * 
 * Submissions ~> https://codeforces.com/contest/2171/submission/350514142 By huanhuanonly
 * 
 * @b Combinatorics ( @a Lucas's-theorem )
 * 
 * ----November 25, 2025 [00h:42m:45s]----
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
    auto ans = static_cast<_Tp>(1);

    for (__fv %= __mod; __sv; __fv = (__fv * __fv) % __mod, __sv >>= 1)
    {
        if (__sv & 1)
        {
            ans = (ans * __fv) % __mod;
        }
    }

    return ans;
}

inline namespace huanhuanonly {
    inline namespace combinatorics
{
constexpr auto factorial_max_length = static_cast<std::size_t>(1e6 + 3 + 1);

template<auto _Mod>
const auto factorial{ []() constexpr
{
    std::array<std::size_t, factorial_max_length> a{1};

    for (std::size_t i = 1; i < a.size(); ++i)
    {
        a[i] = a[i - 1] * i % _Mod;
    }

    return a;
}() };

template<std::size_t _Mod = std::numeric_limits<std::size_t>::max()>
constexpr std::size_t C(std::size_t n, std::size_t k)
{
    static_assert(_Mod >= 2);

    if (n < k)
    {
        return 0;
    }

    if constexpr (_Mod != std::numeric_limits<std::size_t>::max())
    {
        return factorial<_Mod>[n] * binary_exponentiation(factorial<_Mod>[n - k] * factorial<_Mod>[k] % _Mod, _Mod - 2, _Mod);
    }
    else
    {
        return factorial<_Mod>[n] / (factorial<_Mod>[n - k] * factorial<_Mod>[k]);
    }
}

template<std::size_t _Mod>
constexpr std::size_t lucas(std::size_t n, std::size_t k)
{
    if (k == 0)
    {
        return 1;
    }
    else
    {
        return C<_Mod>(n % _Mod, k % _Mod) * lucas<_Mod>(n / _Mod, k / _Mod) % _Mod;
    }
}

template<std::size_t _Mod = std::numeric_limits<std::size_t>::max()>
constexpr std::size_t P(std::size_t n, std::size_t k)
{
    if (not (k <= n))
    {
        return 0;
    }

    if constexpr (_Mod != std::numeric_limits<std::size_t>::max())
    {
        assert(k < factorial_max_length);
        return lucas<_Mod>(n, k) * factorial<_Mod>[k] % _Mod;
    }
    else
    {
        assert(n < factorial_max_length);
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
        int n;
        std::cin >> n;

        std::vector<uint64> a(n), b(n);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
        }

        for (int i = 0; i < n; ++i)
        {
            std::cin >> b[i];
        }

        constexpr auto inf = std::numeric_limits<uint64>::max();
        constexpr auto mod = uint64(1e6 + 3);

        auto mul = inf;

        for (int i = 0; i < n; ++i)
        {
            for (uint64 j = 1; ; j <<= 1)
            {
                if (a[i] * j > b[i])
                {
                    mul = std::min(mul, j >> 1);
                    break;
                }
            }
        }

        const uint64 log2 = std::countr_zero(mul);

        uint64 ans = 1;

        std::map<uint64, std::vector<uint64>> mp;

        for (int i = 0; i < n; ++i)
        {
            a[i] *= mul;

            for (uint64 bit = log2 + 1; bit--; )
            {
                if (const uint64 cnt = (b[i] - a[i]) / (1ULL << bit))
                {
                    a[i] += (1ULL << bit) * cnt;
                    mp[bit].push_back(cnt);
                }
            }
        }

        uint64 x = log2;

        for (const auto& [key, values] : mp)
        {
            uint64 sum = std::reduce(values.begin(), values.end());
            x += sum;

            for (auto i : values)
            {
                ans *= lucas<mod>(sum, i);
                ans %= mod;

                sum -= i;
            }
        }
        
        std::cout << x << ' ' << ans << '\n';
    }

    return 0;
}
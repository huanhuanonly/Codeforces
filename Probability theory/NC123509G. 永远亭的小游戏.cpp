/**
 * Cloudflare纪念赛
 * 
 * => G-永远亭的小游戏
 * 
 * -> https://ac.nowcoder.com/acm/contest/123509/G
 * 
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=80613171 By huanhuanonly
 * 
 * @b Probability-theory ( @a Expectation )
 * 
 * ----November 19, 2025 [13h:58m:53s]----
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

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    uint64 n, m, k;
    std::cin >> n >> m >> k;

    constexpr uint64 maxn = 1e6 + 1;
    constexpr uint64 mod = 1e9 + 7;

    std::vector<uint64> a(maxn), b(maxn), c(maxn);

    for (int i = 0, v; i < n; ++i)
    {
        std::cin >> v;
        ++a[v];
    }

    for (int i = 0, v; i < m; ++i)
    {
        std::cin >> v;
        ++b[v];
    }

    for (int i = 0, v; i < k; ++i)
    {
        std::cin >> v;
        ++c[v];
    }

    uint64 sa = 0, sb = 0, sc = 0;

    for (int i = 1; i <= maxn; ++i)
    {
        sa += i * a[i] % mod;
        sa %= mod;
    }

    for (int i = 1; i <= maxn; ++i)
    {
        sb += i * b[i] % mod;
        sb %= mod;
    }

    for (int i = 1; i <= maxn; ++i)
    {
        sc += i * c[i] % mod;
        sc %= mod;
    }

    sa = sa * binary_exponentiation(n, mod - 2, mod) % mod;
    sb = sb * binary_exponentiation(m, mod - 2, mod) % mod;
    sc = sc * binary_exponentiation(k, mod - 2, mod) % mod;

    std::cout << sa * sb % mod * sc % mod;

    return 0;
}
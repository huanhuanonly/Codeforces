/**
 * Codeforces Round 841 (Div. 2) and Divide by Zero 2022
 * 
 * => E. Graph Cost ( @c 2000 )
 * 
 * -> https://codeforces.com/contest/1731/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/1731/submission/343729400 By huanhuanonly
 * 
 * @b Euler-sieve for @b Euler's-totient-function
 * 
 * ----October 15, 2025 [00h:55m:21s]----
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

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    constexpr int maxn = 1e6;

    std::vector<bool>  vis(maxn + 1);
    std::vector<int64> phi(maxn + 1);

    std::vector<int64> primes;
    primes.reserve(78498);

    for (int i = 2; i <= maxn; ++i)
    {
        if (not vis[i])
        {
            phi[i] = i - 1;
            primes.push_back(i);
        }

        for (int64 p : primes)
        {
            if (i * p > maxn)
            {
                break;
            }

            vis[i * p] = true;

            if (i % p == 0)
            {
                phi[i * p] = phi[i] * p;
                break;
            }
            else
            {
                phi[i * p] = phi[i] * (p - 1);
            }
        }
    }

    std::partial_sum(phi.begin(), phi.end(), phi.begin());

    int _;
    std::cin >> _;

    while (_--)
    {
        int64 n, m;
        std::cin >> n >> m;

        int64 sum = 0;

        for (int64 d = n; d >= 2; --d)
        {
            const int64 cnt = std::min(m, phi[n / d]) / (d - 1);

            m -= cnt * (d - 1);
            sum += cnt * d;
        }

        if (m)
        {
            std::cout << -1 << '\n';
        }
        else
        {
            std::cout << sum << '\n';
        }
    }

    return 0;
}
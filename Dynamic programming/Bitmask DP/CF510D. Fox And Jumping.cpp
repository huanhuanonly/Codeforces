/**
 * Codeforces Round 290 (Div. 2)
 * 
 * => D. Fox And Jumping ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/510/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/510/submission/346486976 By huanhuanonly
 * 
 * @b Bitmask-DP
 * @b Number-theory ( @a greatest-common-divisor | @a prime-factorization )
 * 
 * ----October 29, 2025 [23h:26m:56s]----
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

void chmin(auto& a, const auto& b)
{
    a = std::min(a, b);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n;
    std::cin >> n;

    std::vector<uint32> l(n);
    std::vector<uint64> c(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> l[i];
    }

    for (int i = 0; i < n; ++i)
    {
        std::cin >> c[i];
    }

    if (std::reduce(l.begin(), l.end(), 0U, std::gcd<uint32, uint32>) != 1)
    {
        std::cout << -1;
    }
    else
    {
        constexpr auto inf = std::numeric_limits<uint64>::max() / 2;

        uint64 ans = inf;

        for (int i = 0; i < n; ++i)
        {
            std::vector<int> p;

            int t = l[i];

            for (int j = 2; j * j <= t; ++j)
            {
                if (t % j == 0)
                {
                    p.push_back(j);
                }

                for (; t % j == 0; t /= j);
            }

            if (t > 1)
            {
                p.push_back(t);
            }

            std::vector<uint32> masks(n);

            for (int j = 0; j < n; ++j)
            {
                for (int k = 0; k < p.size(); ++k)
                {
                    if (l[j] % p[k] == 0)
                    {
                        masks[j] |= 1U << k;
                    }
                }
            }

            std::vector<uint64> dp(1U << p.size(), inf);

            dp[(1U << p.size()) - 1] = c[i];

            for (int j = 0; j < n; ++j)
            {
                for (int k = (1U << p.size()) - 1; k >= 0; --k)
                {
                    chmin(dp[k & masks[j]], dp[k] + c[j]);
                }
            }

            chmin(ans, dp[0]);
        }

        std::cout << ans;
    }

    return 0;
}
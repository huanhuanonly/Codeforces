/**
 * Codeforces Round 304 (Div. 2)
 * 
 * => D. Soldier and Number Game ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/546/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/546/submission/346424621 By huanhuanonly
 * 
 * @b Number-theory ( @a prime-factorization )
 * @b Euler-sieve and @b Linear-DP
 * @b Prefix-sum
 * 
 * ----October 29, 2025 [15h:21m:30s]----
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

    constexpr int maxn = 5'000'000;

    std::vector<bool> vis(maxn + 1);
    std::vector<int> primes;

    std::vector<int> dp(maxn + 1);

    for (int i = 2; i <= maxn; ++i)
    {
        if (not vis[i])
        {
            primes.push_back(i);
            dp[i] = 1;
        }

        for (const int p : primes)
        {
            if (i * p > maxn)
            {
                break;
            }

            vis[i * p] = true;
            dp[i * p] = dp[i] + dp[p];

            if (i % p == 0)
            {
                break;
            }
        }
    }

    std::partial_sum(dp.begin(), dp.end(), dp.begin());

    int _;
    std::cin >> _;

    while (_--)
    {
        int l, r;
        std::cin >> r >> l;

        std::cout << dp[r] - dp[l] << '\n';
    }

    return 0;
}
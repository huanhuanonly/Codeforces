/**
 * Codeforces Round 321 (Div. 2)
 * 
 * => D. Kefa and Dishes ( @c 1800 )
 * 
 * -> https://codeforces.com/contest/580/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/580/submission/329612932 By huanhuanonly
 * 
 * @b State-compression-DP
 * 
 * ----July 18, 2025 [18h:40m:42s]----
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

    uint64 n, m, k;
    std::cin >> n >> m >> k;

    std::vector<uint64> v(n);

    for (uint64& i : v)
    {
        std::cin >> i;
    }

    std::vector add(n, std::vector<uint64>(n));

    for (uint64 i = 0; i < k; ++i)
    {
        uint64 x, y, c;
        std::cin >> x >> y >> c;

        add[--x][--y] = c;
    }

    std::vector dp(1ULL << n, std::vector(n, 0ULL));

    std::vector<std::vector<uint64>> list(n + 1);

    for (uint64 s = 1; s < (1ULL << n); ++s)
    {
        list[std::popcount(s)].push_back(s);
    }

    for (uint64 i = 0; i < n; ++i)
    {
        dp[1ULL << i][i] = v[i];
    }

    for (uint64 i = 1; i < m; ++i)
    {
        for (uint64 s : list[i])
        {
            for (uint64 cur = 0; cur < n; ++cur)
            {
                if (s & (1ULL << cur))
                {
                    continue;
                }
                
                for (uint64 last = 0; last < n; ++last)
                {
                    if ((s & (1ULL << last)) == 0)
                    {
                        continue;
                    }

                    dp[s | (1ULL << cur)][cur] = std::max(dp[s | (1ULL << cur)][cur], dp[s][last] + v[cur] + add[last][cur]);
                }
            }
        }
    }

    uint64 ans = 0;

    for (uint64 s : list[m])
    {
        ans = std::max(ans, *std::ranges::max_element(dp[s]));
    }

    std::cout << ans;

    return 0;
}
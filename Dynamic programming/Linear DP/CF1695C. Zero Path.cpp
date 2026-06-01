/**
 * Codeforces Round 801 (Div. 2) and EPIC Institute of Technology Round
 * 
 * => C. Zero Path ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/1695/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/1695/submission/367604655 By huanhuanonly
 * 
 * @b Linear-DP ( @a with-bitset-optimization )
 * @b Graphs
 * 
 * ----March 21, 2026 [22h:13m:53s]----
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

#if defined(__SIZEOF_INT128__)
using int128 = __int128;
using uint128 = unsigned __int128;
#endif

using real32 = float;
using real64 = double;

#if defined(__SIZEOF_FLOAT80__)
using real80 = __float80;
#endif

#if defined(__SIZEOF_FLOAT128__)
using real128 = __float128;
#endif

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, m;
        std::cin >> n >> m;

        std::vector map(n, std::vector<int>(m));

        for (auto& i : map)
        {
            for (auto& j : i)
            {
                std::cin >> j;
            }
        }

        std::vector dp(n, std::vector(m, std::bitset<2001>{}));

        static auto $ = [](int i) -> int
        {
            return 1000 + i;
        };

        dp[0][0].set($(map[0][0]));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (i)
                {
                    dp[i][j] = map[i][j] == 1 ? dp[i - 1][j] << 1 : dp[i - 1][j] >> 1;
                }
                
                if (j)
                {
                    dp[i][j] |= map[i][j] == 1 ? dp[i][j - 1] << 1 : dp[i][j - 1] >> 1;
                }
            }
        }

        if (dp.back().back().test($(0)))
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}
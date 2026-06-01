/**
 * The 2026 ICPC China Shenzhen Invitational Contest
 * 
 * => L. Critical Strike
 * 
 * -> https://qoj.ac/contest/3587/problem/17764
 * 
 * Submissions ~> https://qoj.ac/submission/2292864 By huanhuanonly
 * 
 * @b Expectation-DP
 * 
 * ----April 28, 2026 [13h:44m:40s]----
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

        struct item
        {
            real80 p, v, w;
        };

        std::vector<item> objs(n + 1);

        for (auto& [p, v, w] : objs | std::views::drop(1))
        {
            std::cin >> p >> v >> w;
        }

        std::ranges::sort(objs | std::views::drop(1), {}, &item::v);

        std::vector dp(n + 1, std::vector(m + 1, real80{}));

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);

                if (j - objs[i].w >= 0)
                {
                    dp[i][j] = std::max(dp[i][j], objs[i].p / 100 * objs[i].v + (100 - objs[i].p) / 100 * dp[i - 1][j - objs[i].w]);
                }
            }
        }

        std::cout << std::fixed << std::setprecision(12) << dp.back().back() << '\n';
    }

    return 0;
}
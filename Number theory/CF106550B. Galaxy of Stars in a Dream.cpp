/**
 * The 2026 Jiangsu Collegiate Programming Contest, The 2026 Guangdong Provincial Collegiate Programming Contest
 *
 * => B. Galaxy of Stars in a Dream
 *
 * -> https://codeforces.com/gym/106550/problem/B
 *
 * Submissions ~> https://codeforces.com/gym/106550/submission/376440508 By huanhuanonly
 *
 * @b Number-theory ( @a quadratic-equation )
 *
 * ----May 29, 2026 [01h:37m:52s]----
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
        int64 n;
        std::cin >> n;

        if (n == 0)
        {
            std::cout << "0\n";
            continue;
        }

        constexpr auto inf = std::numeric_limits<int64>::max();

        int64 ans = inf;

        auto calc = [n](int64 a, int64 b, int64 c) -> int64
        {
            if (a >= 0 and b >= 0 and c >= 0)
            {
                const auto [min, max] = std::ranges::minmax({a, b, c});
                return max - min;
            }
            else
            {
                return inf;
            }
        };

        for (int64 d = 0; d < ans and d <= 500; ++d)
        {
            const int64 center = (std::sqrt(real64(d + 1) * (d + 1) + real64(4) * n) - real64(d + 1)) / 2;

            for (int64 a = std::max(center - 3, int64{}); a <= center + 3; ++a)
            {
                ans = std::min(ans, calc(a, a + d, n - a * (a + d)));
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}
/**
 * 2026 年山东省大学生程序设计竞赛
 *
 * => C. 会议日程
 *
 * -> https://qoj.ac/contest/3767/problem/18309
 *
 * Submissions ~> https://qoj.ac/submission/2447760 By huanhuanonly
 *
 * @b Ternary-search
 *
 * ----May 27, 2026 [00h:54m:37s]----
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
        int n;
        std::cin >> n;

        std::vector<std::pair<int, int>> v(n);

        for (auto& [l, r] : v)
        {
            std::cin >> l >> r;
        }

        auto calc = [&](int mid) -> int64
        {
            int64 sum = 0;

            for (const auto& [l, r] : v)
            {
                if (r < mid)
                {
                    sum += int64(mid - r) * (mid - r);
                }
                else if (mid < l)
                {
                    sum += int64(l - mid) * (l - mid);
                }
            }

            return sum;
        };

        int l = 0, r = 1e6, mid;

        while (l < r)
        {
            mid = l + r >> 1;

            if (calc(mid) > calc(mid + 1))
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }

        std::cout << calc(l) << '\n';
    }

    return 0;
}
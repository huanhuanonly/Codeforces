/**
 * The 2025 ICPC Asia Xi'an Regional Contest
 *
 * => L. Let's Make a Convex!
 *
 * -> https://qoj.ac/contest/2562/problem/14692
 *
 * Submissions ~> https://qoj.ac/submission/2299516 By huanhuanonly
 *
 * @b Geometry
 * @b Prefix-sum
 * @b Binary-search
 *
 * ----April 29, 2026 [21h:36m:07s]----
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

        std::vector<int64> v(n + 1);

        for (int64 i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
        }

        std::ranges::sort(v | std::views::drop(1), std::ranges::greater{});
        std::partial_sum(v.begin(), v.end(), v.begin());

        std::vector<int64> ans(n + 1);
        int64 pos = n;

        for (int64 i = 1; i <= n; ++i)
        {
            auto cpos = std::ranges::upper_bound(v, v[i] + v[i] - v[i - 1]) - v.begin();

            if (cpos != v.size())
            {
                for (pos = std::min(pos, n - i + 1); pos >= cpos - i + 1; --pos)
                {
                    ans[pos] = v[i + pos - 1] - v[i - 1];
                }
            }
        }

        for (int64 i = 1; i <= n; ++i)
        {
            std::cout << (i >= 3 ? ans[i] : 0) << " \n"[i == n];
        }
    }

    return 0;
}
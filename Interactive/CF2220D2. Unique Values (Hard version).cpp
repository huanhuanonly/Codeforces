/**
 * Codeforces Round 1093 (Div. 2)
 *
 * => D2. Unique Values (Hard version) ( @c 2000 )
 *
 * -> https://codeforces.com/contest/2220/problem/D2
 *
 * Submissions ~> https://codeforces.com/contest/2220/submission/371066110 By huanhuanonly
 *
 * @b Interactive and @b Binary-search
 *
 * ----April 14, 2026 [08h:54m:01s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        static auto query = [](const auto& set) -> int
        {
            std::cout << "? " << set.size() << ' ';

            for (const auto& i : set)
            {
                std::cout << i << ' ';
            }

            std::cout << std::endl;

            int res;
            std::cin >> res;

            return res;
        };

        static auto answer = [](int x, int y, int z) -> void
        {
            std::cout << "! " << x << ' ' << y << ' ' << z << std::endl;
        };

        int l = 1, r = 2 * n + 1, mid;

        while (r - l > 1)
        {
            mid = l + r >> 1;

            if ((mid - query(std::views::iota(1, mid + 1))) & 1)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }

        const int R = r;

        l = 1;

        while (r - l > 1)
        {
            mid = l + r >> 1;

            if (((R - mid + 1) - query(std::views::iota(mid, R + 1))) & 1)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }

        const int L = l;

        r = R - 1;

        while (r - l > 1)
        {
            mid = l + r >> 1;

            auto set = std::views::iota(L, mid + 1) | std::ranges::to<std::vector>();
            set.push_back(R);

            if (((mid - L + 2) - query(set)) & 1)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }

        answer(L, r, R);
    }

    return 0;
}
/**
 * Forethought Future Cup - Elimination Round
 * 
 * => C. Tree Diameter ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/1146/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/1146/submission/346123858 By huanhuanonly
 * 
 * @b Interactive
 * @b Tree-diameter
 * @b Binary-grouping
 * 
 * ----October 28, 2025 [15h:18m:56s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        auto query = [n](auto a, auto b) -> int
        {
            const int len = std::ranges::distance(a);
            std::cout << len << ' ' << n - len << ' ';

            for (auto i : a)
            {
                std::cout << i << ' ';
            }

            for (auto i : b)
            {
                std::cout << i << ' ';
            }

            std::cout << std::endl;

            int res;
            std::cin >> res;

            return res;
        };

        static auto answer = [](int d) -> void
        {
            std::cout << "-1 " << d << std::endl;
        };
        
        int ans = 0;

        for (int mask = 1; mask <= n; mask <<= 1)
        {
            auto condition = [&](int i) -> bool { return i & mask; };

            ans = std::max(
                ans,
                query(
                    std::views::iota(1, n + 1) | std::views::filter(condition),
                    std::views::iota(1, n + 1) | std::views::filter(std::not_fn(condition))));
        }

        answer(ans);
    }

    return 0;
}
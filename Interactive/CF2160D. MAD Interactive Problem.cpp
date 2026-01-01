/**
 * Codeforces Round 1058 (Div. 2)
 * 
 * => D. MAD Interactive Problem ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/2160/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2160/submission/343392525 By huanhuanonly
 * 
 * @b Interactive
 * @b Constructive
 * @b Stack
 * 
 * ----October 13, 2025 [10h:28m:13s]----
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

        static auto answer = [](const auto& ans) -> void
        {
            std::cout << "! ";

            for (const auto& i : ans)
            {
                std::cout << i << ' ';
            }

            std::cout << std::endl;
        };

        std::vector<int> ans(n * 2 + 1);

        std::vector<int> set1, set2;
        set1.reserve(n * 2);
        set2.reserve(n * 2);

        for (int i = 1; i <= n * 2; ++i)
        {
            set1.push_back(i);

            const int mad = query(set1);

            if (mad)
            {
                ans[i] = mad;
                set1.pop_back();
                set2.push_back(i);
            }
        }

        for (int i : set1)
        {
            set2.push_back(i);

            const int mad = query(set2);

            ans[i] = mad;
            set2.pop_back();
        }

        answer(ans | std::views::drop(1));
    }

    return 0;
}
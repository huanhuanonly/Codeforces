/**
 * Squarepoint Challenge (Codeforces Round 1055, Div. 1 + Div. 2)
 * 
 * => E. Monotone Subsequence ( @c 2100 )
 * 
 * -> https://codeforces.com/contest/2152/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2152/submission/342893134 By huanhuanonly
 * 
 * @b Interactive
 * @b Constructive
 * @b Longest-increasing/decreasing-subsequence ( @a Dilworth's-theorem )
 * 
 * ----October 10, 2025 [19h:36m:58s]----
*/

/// @brief This is an @c interesting problem!

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

        auto query = [](const auto& set) -> std::vector<int>
        {
            std::cout << "? " << set.size() << ' ';

            for (const auto& i : set)
            {
                std::cout << i << ' ';
            }

            std::cout << std::endl;

            
            int k;
            std::cin >> k;
            
            std::vector<int> res(k);

            for (int& i : res)
            {
                std::cin >> i;
            }

            return res;
        };

        auto answer = [n](const auto& set) -> void
        {
            std::cout << "! ";

            for (const auto& i : set | std::views::take(n + 1))
            {
                std::cout << i << ' ';
            }

            std::cout << std::endl;
        };

        const auto gen = std::views::iota(1, n * n + 1 + 1);
        std::set<int> set(gen.begin(), gen.end());

        std::vector<std::vector<int>> sets;

        for (int i = 0; not set.empty() and i < n; ++i)
        {
            sets.push_back(query(set));

            for (int i : sets.back())
            {
                set.erase(i);
            }
        }

        bool found = false;

        for (const auto& i : sets)
        {
            if (i.size() >= n + 1)
            {
                answer(i);
                found = true;
                break;
            }
        }

        if (not found)
        {
            std::vector<int> ans;
            ans.reserve(n + 1);

            ans.push_back(*set.rbegin());

            for (const auto& i : sets | std::views::reverse)
            {
                ans.push_back(*std::ranges::upper_bound(i  | std::views::reverse, ans.back(), std::ranges::greater()));
            }

            answer(ans | std::views::reverse);
            found = true;
        }

        assert(found);
    }

    return 0;
}
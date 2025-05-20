/**
 * Codeforces Round 1017 (Div. 4)
 * 
 * => E. Boneca Ambalabu ( @c Rating )
 * 
 * -> https://codeforces.com/contest/2094/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2094/submission/315706878 By huanhuanonly
 * 
 * @b Bitwise-XOR
 * 
 * ----April 15, 2025 [20h:40m:06s]----
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

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        std::vector<int> v(n);

        std::array<int64, 30> cnt{};

        for (auto& i : v)
        {
            std::cin >> i;

            for (const auto& j : std::views::iota(0, 30))
            {
                cnt[j] += i >> j & 1;
            }
        }

        std::map<int64, int> mp;

        for (const auto& i : v)
        {
            int64 sum = 0;

            for (const auto& j : std::views::iota(0, 30))
            {
                int p = i >> j & 1;

                if (p)
                {
                    sum += int64(n - cnt[j]) * (1 << j);
                    sum -= cnt[j] * (1 << j);
                }
            }

            mp[sum] = i;
        }

        int ans = mp.rbegin()->second;

        auto range = v | std::views::transform([&](int value) -> int { return value ^ ans; });
        std::cout << std::accumulate(range.begin(), range.end(), 0ULL) << '\n';
    }

    return 0;
}
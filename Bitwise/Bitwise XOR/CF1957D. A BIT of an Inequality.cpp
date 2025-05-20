/**
 * Codeforces Round 940 (Div. 2) and CodeCraft-23
 * 
 * => D. A BIT of an Inequality ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/1957/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/1957/submission/318906012 By huanhuanonly
 * 
 * @b Bitwise-XOR
 * 
 * ----May 09, 2025 [14h:47m:05s]----
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

        std::vector<uint32> v(n);

        for (auto& i : v)
        {
            std::cin >> i;
        }

        uint64 ans = 0;
        
        for (uint32 bitmask = 1; bitmask <= (1 << 30); bitmask <<= 1)
        {
            std::vector<std::pair<int, uint32>> pre, suf;

            static auto compare = [](const auto& lv, const auto& rv) -> bool
            {
                return lv.first < rv.first;
            };

            for (int i = 0, sum = 0; i < n; ++i)
            {
                ++sum;

                if (v[i] & bitmask)
                {
                    pre.emplace_back(i, sum + (pre.size() >= 2 ? pre[pre.size() - 2].second : 0));
                    sum = 0;
                }
            }

            for (int i = n - 1, sum = 0; i >= 0; --i)
            {
                ++sum;

                if (v[i] & bitmask)
                {
                    suf.emplace_back(i, sum + (suf.size() >= 2 ? suf[suf.size() - 2].second : 0));
                    sum = 0;
                }
            }

            std::ranges::reverse(suf);

            for (int i = 0; i < n; ++i)
            {
                if (std::bit_floor(v[i]) == bitmask)
                {
                    auto pre_it = std::ranges::lower_bound(pre, std::make_pair(i, 0), compare);
                    auto suf_it = std::ranges::lower_bound(suf, std::make_pair(i, 0), compare);

                    if (suf_it + 1 != suf.end())
                    {
                        ans += pre_it->second * (suf_it + 1)->second;
                    }

                    if (pre_it != pre.begin())
                    {
                        ans += (pre_it - 1)->second * suf_it->second;
                    }
                }
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}
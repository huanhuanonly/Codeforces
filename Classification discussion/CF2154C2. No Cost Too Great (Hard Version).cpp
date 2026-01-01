/**
 * Codeforces Round 1060 (Div. 2)
 * 
 * => C2. No Cost Too Great (Hard Version) ( @c 2000 )
 * 
 * -> https://codeforces.com/contest/2154/problem/C2
 * 
 * Submissions ~> https://codeforces.com/contest/2154/submission/345138781 By huanhuanonly
 * 
 * @b Classification-discussion and @b Number-theory ( @a greatest-common-divisor )
 * 
 * ----October 22, 2025 [15h:29m:30s]----
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

        std::vector<std::pair<uint64, uint64>> v(n);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i].first;
        }

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i].second;
        }

        std::ranges::sort(v, {}, &decltype(v)::value_type::second);

        std::set<uint64> set;

        bool found = false;

        for (uint64 i = 0; i < n and not found; ++i)
        {
            auto t = v[i].first;
            for (uint64 j = 2; j <= t / j; ++j)
            {
                if (t % j == 0)
                {
                    if (set.contains(j))
                    {
                        found = true;
                        break;
                    }
                    else
                    {
                        set.insert(j);
                    }
                }

                for (; t % j == 0; t /= j);
            }

            if (t > 1)
            {
                if (set.contains(t))
                {
                    found = true;
                }
                else
                {
                    set.insert(t);
                }
            }
        }

        if (found)
        {
            std::cout << 0 << '\n';
            continue;
        }

        auto ans = std::numeric_limits<uint64>::max();

        auto odd = v | std::views::filter([](const auto& pair) -> bool
        {
            return pair.first & 1;
        });

        if (auto it1 = odd.begin(), it2 = std::next(it1); it2 != odd.end())
        {
            ans = std::min(ans, it1->second + it2->second);
        }

        for (int i = 0; i < n; ++i)
        {
            auto t = v[i].first + 1;
            for (uint64 j = 2; j <= t / j; ++j)
            {
                if (t % j == 0)
                {
                    if (set.contains(j))
                    {
                        ans = std::min(ans, v[i].second);
                        break;
                    }
                }

                for (; t % j == 0; t /= j);
            }

            if (t > 1 and set.contains(t))
            {
                ans = std::min(ans, v[i].second);
            }
        }

        auto t = v.front().first;
        for (uint64 j = 2; j <= t / j; ++j)
        {
            if (t % j == 0)
            {
                set.erase(j);
            }

            for (; t % j == 0; t /= j);
        }

        if (t > 1)
        {
            set.erase(t);
        }

        for (const auto x : set)
        {
            const auto k = (v.front().first + x - 1) / x;
            
            ans = std::min(ans, (x * k - v.front().first) * v.front().second);
        }

        std::cout << ans << '\n';
    }

    return 0;
}
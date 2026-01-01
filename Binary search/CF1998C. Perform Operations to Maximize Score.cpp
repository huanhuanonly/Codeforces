/**
 * Codeforces Round 965 (Div. 2)
 * 
 * => C. Perform Operations to Maximize Score ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/1998/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/1998/submission/343495140 By huanhuanonly
 * 
 * @b Binary-search and @b Classification-discussion
 * 
 * ----October 13, 2025 [16h:53m:50s]----
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
        int64 n, k;
        std::cin >> n >> k;

        std::vector<std::pair<int64, int64>> v(n);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i].first;
        }

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i].second;
        }

        std::ranges::sort(v);

        int64 ans = 0;

        if (auto it = std::ranges::find(v | std::views::reverse, 1, &decltype(v)::value_type::second); it != v.rend())
        {
            int64 pos = n / 2 - 1;

            if (it->first <= v[pos].first)
            {
                ++pos;
            }

            ans = std::max(ans, it->first + k + v[pos].first);
        }

        const int64 max_value = v.back().first;
        v.pop_back();

        auto check = [&](int64 mid) -> bool
        {
            int64 cnt = (n + 1) / 2;
            int64 remain = k;

            for (int i = v.size() - 1; i >= 0 and cnt; --i)
            {
                if (v[i].first >= mid)
                {
                    --cnt;
                }
                else if (v[i].second)
                {
                    if ((remain -= mid - v[i].first) < 0)
                    {
                        break;
                    }

                    --cnt;
                }
            }

            return not cnt;
        };

        int64 l = 0, r = 2e9 + 1, mid;

        while (r - l > 1)
        {
            mid = l + r >> 1;

            if (check(mid))
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        
        ans = std::max(ans, max_value + l);

        std::cout << ans << '\n';
    }

    return 0;
}
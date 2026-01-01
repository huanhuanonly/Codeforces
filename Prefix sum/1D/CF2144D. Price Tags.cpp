/**
 * Educational Codeforces Round 182 (Rated for Div. 2)
 * 
 * => D. Price Tags ( @c 1800 )
 * 
 * -> https://codeforces.com/contest/2144/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2144/submission/341080310 By huanhuanonly
 * 
 * @b Prefix-sum
 * 
 * ----September 29, 2025 [23h:15m:20s]----
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
        int64 n, b;
        std::cin >> n >> b;

        constexpr int64 maxv = 2e5;

        std::vector<int64> cnt(maxv + 1);

        for (int64 i = 0, v; i < n; ++i)
        {
            std::cin >> v;
            ++cnt[v];
        }

        std::partial_sum(cnt.begin(), cnt.end(), cnt.begin());

        auto get = [&](int64 l, int64 r) -> int64
        {
            return cnt[std::min(r, maxv)] - cnt[l - 1];
        };

        int64 ans = std::numeric_limits<int64>::min();

        for (int64 x = 2; x <= maxv; ++x)
        {
            int64 sum = 0;
            int64 cost = n * b;

            for (int64 y = 1; x * (y - 1) + 1 <= maxv; ++y)
            {
                if (const int64 c = get(x * (y - 1) + 1, x * y); c)
                {
                    sum += c * y;
                    cost -= std::min(c, get(y, y)) * b;
                }
            }

            ans = std::max(ans, sum - cost);
        }

        std::cout << ans << '\n';
    }

    return 0;
}
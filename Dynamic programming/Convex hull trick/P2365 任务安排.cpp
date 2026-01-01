/**
 * => P2365 任务安排 ( @c 普及+/提高 )
 * 
 * -> https://www.luogu.com.cn/problem/P2365
 * 
 * Submissions ~> https://www.luogu.com.cn/record/246753525 By huanhuanonly
 * 
 * @b DP with @b Convex-hull-trick
 * @b Prefix-sum
 * @b Monotonic-queue
 * 
 * ----November 12, 2025 [00h:03m:07s]----
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

    int64 n, s;
    std::cin >> n >> s;

    std::vector<int64> t(n + 1), f(n + 1);

    for (int64 i = 1; i <= n; ++i)
    {
        std::cin >> t[i] >> f[i];
    }

    std::partial_sum(t.begin(), t.end(), t.begin());
    std::partial_sum(f.begin(), f.end(), f.begin());

    struct point
    {
        int64 x, y;
        
        point operator-(const point& other) const noexcept
        {
            return {x - other.x, y - other.y};
        }

        int operator*(const point& other) const noexcept
        {
            return (x * other.y) - (y * other.x);
        }
    };

    constexpr auto inf = std::numeric_limits<int64>::max() / 2;

    std::vector dp(n + 1, inf);
    dp[0] = 0;

    std::deque<point> que;
    que.emplace_back(f[0], dp[0]);

    for (int64 i = 1; i <= n; ++i)
    {
        auto $ = [&](const point& c) -> int64
        {
            return (c.y - (t[i] + s) * c.x) + (t[i] * f[i] + s * f[n]);
        };

        for (; que.size() >= 2 and $(que[0]) >= $(que[1]); que.pop_front());

        dp[i] = $(que.front());

        const point c{f[i], dp[i]};

        for (; que.size() >= 2 and (que[que.size() - 2] - que.back()) * (c - que.back()) > 0; que.pop_back());
        que.push_back(c);
    }

    std::cout << dp[n];

    return 0;
}
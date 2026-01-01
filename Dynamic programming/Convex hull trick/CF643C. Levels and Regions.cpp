/**
 * VK Cup 2016 - Round 3
 * 
 * => C. Levels and Regions ( @c 2400 )
 * 
 * -> https://codeforces.com/contest/643/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/643/submission/348640970 By huanhuanonly
 * 
 * @b DP with @b Convex-hull-trick
 * @b Prefix-sum
 * @b Monotonic-queue
 * @b Probability-theory ( @a Expectation and @a Geometric-distribution )
 * 
 * ----November 12, 2025 [23h:56m:43s]----
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

    int n, m;
    std::cin >> n >> m;

    std::vector<int64> t(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> t[i];
    }

    auto s = t;
    std::partial_sum(s.begin(), s.end(), s.begin());

    std::vector<real64> x(n + 1), y(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        x[i] = x[i - 1] + (real64(s[i]) / t[i]);
        y[i] = y[i - 1] + (1.0 / t[i]);
    }

    struct point
    {
        real64 x, y;

        point operator-(const point& other) const noexcept
        {
            return {x - other.x, y - other.y};
        }

        real64 operator*(const point& other) const noexcept
        {
            return (x * other.y) - (y * other.x);
        }
    };

    const auto inf = std::numeric_limits<real64>::max();

    std::vector dp(m + 1, std::vector(n + 1, inf));
    
    for (int i = 0; i <= m; ++i)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= m; ++i)
    {
        std::deque<point> que;
        que.emplace_back(s[0], dp[i - 1][0] - x[0] + y[0] * s[0]);

        for (int j = 1; j <= n; ++j)
        {
            auto $ = [&](const point& c) -> real64
            {
                return (c.y - y[j] * c.x) + x[j];
            };

            for (; que.size() >= 2 and $(que[0]) >= $(que[1]); que.pop_front());

            dp[i][j] = $(que.front());

            const point c{real64(s[j]), dp[i - 1][j] - x[j] + y[j] * s[j]};

            for (; que.size() >= 2 and (que[que.size() - 2] - que.back()) * (c - que.back()) > 0; que.pop_back());
            que.push_back(c);
        }
    }

    std::cout << std::fixed << std::setprecision(12) << dp[m][n];

    return 0;
}
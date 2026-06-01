/**
 * Codeforces Round 219 (Div. 1)
 * 
 * => C. Watching Fireworks is Fun ( @c 2100 )
 * 
 * -> https://codeforces.com/contest/372/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/372/submission/372144577 By huanhuanonly
 * 
 * @b DP with @b Monotonic-queue
 * 
 * ----April 22, 2026 [22h:16m:57s]----
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

#if defined(__SIZEOF_INT128__)
using int128 = __int128;
using uint128 = unsigned __int128;
#endif

using real32 = float;
using real64 = double;

#if defined(__SIZEOF_FLOAT80__)
using real80 = __float80;
#endif

#if defined(__SIZEOF_FLOAT128__)
using real128 = __float128;
#endif

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int64 n, m, d;
    std::cin >> n >> m >> d;

    struct item
    {
        int64 a, b, t;
    };
    
    std::vector<item> v(m);
    
    for (auto& [a, b, t] : v)
    {
        std::cin >> a >> b >> t;
        --a;
    }

    std::vector dp(2, std::vector<int64>(n));
    
    for (int64 i = 0; i < n; ++i)
    {
        dp[0][i] = v[0].b - std::abs(v[0].a - i);
    }

    for (int64 i = 1; i < m; ++i)
    {
        auto $ = [&](int64 j) -> int64
        {
            return dp[0][j] + v[i].b;
        };

        std::deque<int64> que;

        int64 l = -(v[i].t - v[i - 1].t) * d;
        int64 r = -l;

        for (int64 j = 0; j < std::min(r + 1, n); ++j)
        {
            for (; not que.empty() and $(que.back()) < $(j); que.pop_back());
            que.push_back(j);
        }

        for (int64 j = 0; j < n; ++j)
        {
            dp[1][j] = $(que.front()) - std::abs(v[i].a - j);

            if (++r < n)
            {
                for (; not que.empty() and $(que.back()) < $(r); que.pop_back());
                que.push_back(r);
            }

            if (l++ >= 0 and que.front() < l)
            {
                que.pop_front();
            }
        }

        std::swap(dp[0], dp[1]);
    }
    
    std::cout << *std::ranges::fold_left_first(dp[0], std::ranges::max) << '\n';

    return 0;
}
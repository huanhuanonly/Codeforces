/**
 * Codeforces Round 498 (Div. 3)
 * 
 * => F. Xor-Paths ( @c 2100 )
 * 
 * -> https://codeforces.com/contest/1006/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/1006/submission/347491391 By huanhuanonly
 * 
 * @b Meet-in-the-middle
 * 
 * ----November 05, 2025 [11h:44m:03s]----
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

    uint64 n, m, k;
    std::cin >> n >> m >> k;

    std::vector v(n, std::vector(m, uint64{}));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> v[i][j];
        }
    }

    std::vector dp(n, std::vector(m, std::map<uint64, uint64>{}));

    constexpr std::array d{
        std::array{std::pair{1, 0}, std::pair{0, 1}},
        std::array{std::pair{-1, 0}, std::pair{0, -1}}
    };

    uint64 ans = 0;

    auto dfs1 = [&](const auto& self, int x, int y, uint64 sum) -> void
    {
        if (x + y == (n + m) / 2 - 1)
        {
            ++dp[x][y][sum];
            return;
        }

        for (const auto& [dx, dy] : d[0])
        {
            const int nx = x + dx, ny = y + dy;

            if (not (nx < n and ny < m))
            {
                continue;
            }

            self(self, nx, ny, sum xor v[nx][ny]);
        }
    };

    auto dfs2 = [&](const auto& self, int x, int y, uint64 sum) -> void
    {
        if (x + y == (n + m) / 2 - 1)
        {
            if (auto it = dp[x][y].find(sum xor v[x][y] xor k); it != dp[x][y].end())
            {
                ans += it->second;
            }
            
            return;
        }

        for (const auto& [dx, dy] : d[1])
        {
            const int nx = x + dx, ny = y + dy;

            if (not (nx >= 0 and ny >= 0))
            {
                continue;
            }

            self(self, nx, ny, sum xor v[nx][ny]);
        }
    };

    dfs1(dfs1, 0, 0, v[0][0]);
    dfs2(dfs2, n - 1, m - 1, v[n - 1][m - 1]);

    std::cout << ans;

    return 0;
}
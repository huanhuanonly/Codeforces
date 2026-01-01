/**
 * Japan Registry Services (JPRS) Programming Contest 2025#2 (AtCoder Beginner Contest 415)
 * 
 * => E - Hungry Takahashi ( @c 450 )
 * 
 * -> https://atcoder.jp/contests/abc415/tasks/abc415_e
 * 
 * Submissions ~> https://atcoder.jp/contests/abc415/submissions/67763671 By huanhuanonly
 * 
 * @b SPFA and @b Binary-search
 * 
 * ----July 19, 2025 [22h:27m:15s]----
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

    std::vector<std::vector<int64>> v(n, std::vector<int64>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> v[i][j];
        }
    }

    std::vector<int64> p(n + m - 1);

    for (int i = 0; i < p.size(); ++i)
    {
        std::cin >> p[i];
    }

    auto bfs = [&](int64 add) -> bool
    {
        constexpr int64 inf = std::numeric_limits<int64>::max() / 2;
        std::vector dis(n, std::vector(m, inf));
        std::vector vis(n, std::vector<bool>(m));

        struct item
        {
            int x, y, i;
            int64 w;

            bool operator<(const item& other) const noexcept
            {
                return w > other.w;
            }
        };

        std::priority_queue<item> que;

        int64 init = -v[0][0] - add + p[0];
        if (init > 0)
        {
            return false;
        }

        que.push({0, 0, 1, init});
        dis[0][0] = init;
        
        while (not que.empty())
        {
            item cur = que.top();
            que.pop();
            
            if (cur.x == n - 1 and cur.y == m - 1 and dis[n - 1][m - 1] <= 0)
            {
                return true;
            }

            vis[cur.x][cur.y] = false;

            constexpr std::pair<int, int> d[]{
                {1, 0}, {0, 1}
            };

            for (const auto& [dx, dy] : d)
            {
                int nx = cur.x + dx, ny = cur.y + dy;

                if (nx >= 0 and nx < n and ny >= 0 and ny < m)
                {
                    int64 ndis = dis[cur.x][cur.y] - v[nx][ny] + p[cur.i];

                    if (ndis < dis[nx][ny] and ndis <= 0)
                    {
                        dis[nx][ny] = ndis;

                        if (not vis[nx][ny])
                        {
                            vis[nx][ny] = true;
                            que.push({nx, ny, cur.i + 1, ndis});
                        }
                    }
                }
            }
        }

        return false;
    };

    int64 l = -1, r = 1e16, mid;

    while (r - l > 1)
    {
        mid = l + r >> 1;

        if (bfs(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }

    std::cout << r;

    return 0;
}
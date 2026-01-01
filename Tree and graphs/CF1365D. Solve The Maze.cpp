/**
 * Codeforces Round 648 (Div. 2)
 * 
 * => D. Solve The Maze ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/1365/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/1365/submission/345432315 By huanhuanonly
 * 
 * @b Dfs
 * 
 * ----October 24, 2025 [10h:31m:45s]----
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
        int n, m;
        std::cin >> n >> m;

        std::vector mp(n, std::vector<char>(m));

        const std::pair<int, int> d[]{
            {1, 0}, {0, 1},
            {-1, 0}, {0, -1}
        };

        bool yes = true;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                std::cin >> mp[i][j];
            }
        }

        int cnt = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (mp[i][j] == 'B')
                {
                    for (const auto& [dx, dy] : d)
                    {
                        const int nx = i + dx, ny = j + dy;

                        if (nx >= 0 and nx < n and ny >= 0 and ny < m)
                        {
                            if (mp[nx][ny] == '.')
                            {
                                mp[nx][ny] = '#';
                            }
                            else if (mp[nx][ny] == 'G')
                            {
                                yes = false;
                            }
                        }
                    }
                }
                else if (mp[i][j] == 'G')
                {
                    ++cnt;
                }
            }
        }

        if (not yes)
        {
            std::cout << "No\n";
            continue;
        }

        std::vector vis(n, std::vector<bool>(m));

        auto dfs = [&](const auto& self, int x, int y) -> void
        {
            if (vis[x][y] or mp[x][y] == '#')
            {
                return;
            }

            vis[x][y] = true;

            if (mp[x][y] == 'G')
            {
                --cnt;
            }
            
            for (const auto& [dx, dy] : d)
            {
                const int nx = x + dx, ny = y + dy;

                if (nx >= 0 and nx < n and ny >= 0 and ny < m)
                {
                    self(self, nx, ny);
                }
            }
        };

        dfs(dfs, n - 1, m - 1);

        if (cnt == 0)
        {
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
    }

    return 0;
}
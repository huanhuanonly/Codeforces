/**
 * Codeforces Beta Round 94 (Div. 1 Only)
 * 
 * => A. Statues ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/128/problem/A
 * 
 * Submissions ~> https://codeforces.com/contest/128/submission/328806373 By huanhuanonly
 * 
 * @b Bfs
 * 
 * ----July 14, 2025 [00h:43m:19s]----
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

    std::vector<std::string> mp(8);

    for (std::string& i : mp)
    {
        std::cin >> i;
    }

    auto bfs = [&]() -> bool
    {
        std::queue<std::pair<int, int>> que;
        que.push({7, 0});

        std::vector vis(8, std::vector<bool>(8));

        auto check = [&](int nx, int ny) -> bool
        {
            return nx >= 0 and nx < 8 and ny >= 0 and ny < 8 and mp[nx][ny] != 'S';
        };

        while (not que.empty())
        {
            auto [cx, cy] = que.front();
            que.pop();

            if (cx == 0)
            {
                return true;
            }

            if (vis[cx][cy])
            {
                continue;
            }

            vis[cx][cy] = true;

            constexpr std::pair<int, int> d[]{
                {0, 1}, {1, 0}, {0, -1}, {-1, 0},
                {1, 1}, {-1, -1}, {1, -1}, {-1, 1},
                {0, 0}
            };

            for (const auto& [dx, dy] : d)
            {
                int nx = cx + dx, ny = cy + dy;

                if (check(nx, ny) and check(--nx, ny))
                {
                    que.push({nx, ny});
                }
            }
        }

        return false;
    };

    if (bfs())
    {
        std::cout << "WIN";
    }
    else
    {
        std::cout << "LOSE";
    }

    return 0;
}
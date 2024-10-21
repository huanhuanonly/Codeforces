/**
 * HDU 2nd “Vegetable-Birds Cup” Programming Open Contest	
 * 
 * => Nightmare Ⅱ
 * 
 * -> https://acm.hdu.edu.cn/showproblem.php?pid=3085
 * 
 * @b Meet-in-the-middle
*/

#include <bits/stdc++.h>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int _;
    std::cin >> _;
    while (_--)
    {
        int n, m;
        std::cin >> n >> m;

        std::vector<std::pair<int, int>> ghost;

        std::pair<int, int> me, you;

        std::vector<std::vector<char>> mp(n, std::vector<char>(m));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                std::cin >> mp[i][j];

                switch (mp[i][j])
                {
                    case 'M':
                    {
                        me = std::make_pair(i, j);
                        break;
                    }

                    case 'G':
                    {
                        you = std::make_pair(i, j);
                        break;
                    }

                    case 'Z':
                    {
                        ghost.push_back(std::make_pair(i, j));
                        break;
                    }
                }
            }
        }

        enum vis_t : char { vis_me = 1, vis_you = 2 };
        
        std::vector<std::vector<vis_t>> vis(n, std::vector<vis_t>(m));

        std::function<int()> bfs = [&]() -> int
        {
            struct node { int x, y; };
            std::queue<node> que_me, que_you;
            vis[me.first][me.second] = vis_me;
            vis[you.first][you.second] = vis_you;
            
            que_me.push({me.first, me.second});
            que_you.push({you.first, you.second});

            int ctime = 0;

            std::pair<int, int> d[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

            auto in_range = [&ctime, &ghost](int x, int y) -> bool
            {
                for (const auto& [xx, yy] : ghost)
                {
                    if (std::abs(x - xx) + std::abs(y - yy) <= ctime * 2)
                        return true;
                }
                return false;
            };

            while (not que_me.empty() or not que_you.empty())
            {
                ++ctime;

                for (int me_move = 0; me_move < 3; ++me_move)
                {
                    int size = static_cast<int>(que_me.size());
                    while (size--)
                    {
                        node ct = que_me.front();
                        que_me.pop();
                        
                        if (in_range(ct.x, ct.y)) continue;

                        for (const auto& [x, y] : d)
                        {
                            int xx = ct.x + x;
                            int yy = ct.y + y;

                            if (xx < 0 or xx >= n or yy < 0 or yy >= m) continue;

                            if (in_range(xx, yy) or mp[xx][yy] == 'X') continue;
                            if (vis[xx][yy] == vis_me)  continue;
                            if (vis[xx][yy] == vis_you) return ctime;

                            vis[xx][yy] = vis_me;
                            que_me.push({xx, yy});
                        }
                    }
                }

                int size = static_cast<int>(que_you.size());
                while (size--)
                {
                    node ct = que_you.front();
                    que_you.pop();

                    if (in_range(ct.x, ct.y)) continue;
                    
                    for (const auto& [x, y] : d)
                    {
                        int xx = ct.x + x;
                        int yy = ct.y + y;

                        if (xx < 0 or xx >= n or yy < 0 or yy >= m) continue;

                        if (in_range(xx, yy) or mp[xx][yy] == 'X') continue;
                        if (vis[xx][yy] == vis_you) continue;
                        if (vis[xx][yy] == vis_me)  return ctime;

                        vis[xx][yy] = vis_you;
                        que_you.push({xx, yy});
                    }
                }
            }
            return -1;
        };

        std::cout << bfs() << '\n';
    }
    return 0;
}
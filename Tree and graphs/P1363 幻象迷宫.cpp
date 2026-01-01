/**
 * => P1363 幻象迷宫 ( @c 普及+/提高 )
 * 
 * -> https://www.luogu.com.cn/problem/P1363
 * 
 * Submissions ~> https://www.luogu.com.cn/record/165648441 By huanhuanonly
 * 
 * @b Bfs
 * 
 * ----July 13, 2024 [10h:42m:03s]----
*/

#include <bits/stdc++.h>

using uint    = unsigned int;
using llong   = long long int;
using ullong  = unsigned long long int;
using ldouble = long double;

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
	::freopen("in", "r", stdin);
	::freopen("out", "w", stdout);
#endif

	int n, m;
	while (std::cin >> n >> m)
	{
		std::vector<std::vector<char>> mp(n, std::vector<char>(m));

		int sx, sy;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				std::cin >> mp[i][j];

				if (mp[i][j] == 'S')
					sx = i, sy = j;
			}
		}

		auto bfs = [&]() -> bool
		{
			struct point
			{
				int x, y;
				int lx, ly;
			};
			
			std::queue<point> que;
			std::vector<std::vector<bool>> vis(n, std::vector<bool>(m));
			std::vector<std::vector<int>> vis_x(n, std::vector<int>(m));
			std::vector<std::vector<int>> vis_y(n, std::vector<int>(m));

			static constexpr std::pair<int, int> d[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

			que.push({sx, sy, sx, sy});

			while (not que.empty())
			{
				auto now = que.front();
				que.pop();

				if (vis[now.x][now.y] and vis_x[now.x][now.y] == now.lx and vis_y[now.x][now.y] == now.ly)
					continue;

				if (vis[now.x][now.y] and (vis_x[now.x][now.y] != now.lx or vis_y[now.x][now.y] != now.ly))
					return true;

				vis[now.x][now.y] = true;
				vis_x[now.x][now.y] = now.lx;
				vis_y[now.x][now.y] = now.ly;

				for (const auto& [dx, dy] : d)
				{
					int nx = (dx + now.x + n) % n, ny = (dy + now.y + m) % m;
					
					if (mp[nx][ny] != '#')
					{
						que.push({nx, ny, dx + now.lx, dy + now.ly});
					}
				}
			}

			return false;
		};

		std::cout << (bfs() ? "Yes\n" : "No\n");
	}

	return 0;
}
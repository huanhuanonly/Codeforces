/**
 * Educational Codeforces Round 1
 * 
 * => D. Igor In the Museum ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/598/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/598/submission/328399962 By huanhuanonly
 * 
 * @b Bfs and @b Disjoint-set
 * 
 * ----July 11, 2025 [00h:58m:23s]----
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

class DisjointSet
{
public:
    std::vector<int> tree;

    explicit DisjointSet(std::size_t n)
        : tree(n)
    {
        std::iota(tree.begin(), tree.end(), 0);
    }

    int find(int u)
    {
        return tree[u] == u ? u : tree[u] = find(tree[u]);
    }

    void merge(int u, int v)
    {
        tree[find(v)] = find(u);
    }
};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::string> mp(n);

    for (std::string& i : mp)
    {
        std::cin >> i;
    }

    DisjointSet dsu(n * m);

    auto id = [&](int x, int y) -> int
    {
        return x * m + y;
    };

    std::vector<std::vector<bool>> vis(n, std::vector<bool>(m));

    std::map<int, int> ans;

    auto bfs = [&](int sx, int sy) -> int
    {
        int cnt = 0;

        std::queue<std::pair<int, int>> que;
        que.push(std::make_pair(sx, sy));
        vis[sx][sy] = true;

        while (not que.empty())
        {
            auto [cx, cy] = que.front();
            que.pop();

            constexpr std::pair<int, int> d[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

            for (const auto& [dx, dy] : d)
            {
                int nx = cx + dx, ny = cy + dy;

                if (nx >= 0 and nx < n and ny >= 0 and ny < m and not vis[nx][ny])
                {
                    if (mp[nx][ny] == '.')
                    {
                        vis[nx][ny] = true;
                        que.push(std::make_pair(nx, ny));
                        dsu.merge(id(cx, cy), id(nx, ny));
                    }
                    else
                    {
                        ++cnt;
                    }
                }
            }
        }

        return cnt;
    };

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (vis[i][j] or mp[i][j] == '*')
            {
                continue;
            }

            int res = bfs(i, j);
            ans[dsu.find(id(i, j))] = res;
        }
    }

    while (k--)
    {
        int x, y;
        std::cin >> x >> y;

        std::cout << ans[dsu.find(id(x - 1, y - 1))] << '\n';
    }

    return 0;
}
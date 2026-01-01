/**
 * Codeforces Round 656 (Div. 3)
 * 
 * => E. Directing Edges ( @c 2000 )
 * 
 * -> https://codeforces.com/contest/1385/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/1385/submission/343084367 By huanhuanonly
 * 
 * @b Topological-sorting on @a Graphs
 * 
 * ----October 11, 2025 [15h:09m:02s]----
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

        struct edge
        {
            int  point;
            bool undirected;

            bool operator<(const edge& other) const noexcept
            {
                return point < other.point;
            }
        };

        std::vector<std::set<edge>> e(n + 1);
        std::vector<int> indegrees(n + 1);

        for (int i = 0; i < m; ++i)
        {
            int b, u, v;
            std::cin >> b >> u >> v;

            if (b)
            {
                e[u].insert({v, false});
                ++indegrees[v];
            }
            else
            {
                e[u].insert({v, true});
                e[v].insert({u, true});
            }
        }

        std::queue<int> que;
        std::vector<bool> vis(n + 1);
        
        for (int i = 1; i <= n; ++i)
        {
            if (indegrees[i] == 0)
            {
                que.push(i);
                vis[i] = true;
            }
        }

        while (not que.empty())
        {
            const int cur = que.front();
            que.pop();

            for (const auto& i : e[cur])
            {
                if (i.undirected)
                {
                    e[i.point].erase({cur, true});
                }
                else
                {
                    --indegrees[i.point];
                }
                
                if (indegrees[i.point] == 0 and not vis[i.point])
                {
                    que.push(i.point);
                    vis[i.point] = true;
                }
            }
        }

        if (std::ranges::count(indegrees | std::views::drop(1), 0) == n)
        {
            std::cout << "YES\n";

            for (int u = 1; u <= n; ++u)
            {
                for (const auto& [v, _unused] : e[u])
                {
                    std::cout << u << ' ' << v << '\n';
                }
            }
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}
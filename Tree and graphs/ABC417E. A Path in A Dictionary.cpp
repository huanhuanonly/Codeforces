/**
 * AtCoder Beginner Contest 417
 * 
 * => E - A Path in A Dictionary ( @c 475 )
 * 
 * -> https://atcoder.jp/contests/abc417/tasks/abc417_e
 * 
 * Submissions ~> https://atcoder.jp/contests/abc417/tasks/abc417_e By huanhuanonly
 * 
 * @b Dfs on @a Graphs
 * 
 * ----August 02, 2025 [21h:44m:02s]----
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
        int n, m, x, y;
        std::cin >> n >> m >> x >> y;
    
        std::vector<std::vector<int>> e(n + 1);
    
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            std::cin >> u >> v;
    
            e[u].push_back(v);
            e[v].push_back(u);
        }
    
        for (int i = 1; i <= n; ++i)
        {
            std::ranges::sort(e[i]);
        }
    
        std::vector<bool> vis(n + 1);
        vis[x] = true;
        
        std::vector<int> path{x};
    
        auto dfs = [&](const auto& self, int u) -> bool
        {
            if (u == y)
            {
                return true;
            }
    
            for (int i : e[u])
            {
                if (vis[i] == false)
                {
                    vis[i] = true;
                    path.push_back(i);
    
                    if (self(self, i))
                    {
                        return true;
                    }
    
                    path.pop_back();
                }
            }
    
            return false;
        };
    
        dfs(dfs, x);
    
        for (int i : path)
        {
            std::cout << i << ' ';
        }
    
        std::cout << '\n';
    }

    return 0;
}
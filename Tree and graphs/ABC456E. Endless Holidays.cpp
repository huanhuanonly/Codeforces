/**
 * AtCoder Beginner Contest 456
 *
 * => E - Endless Holidays ( @c 450 )
 *
 * -> https://atcoder.jp/contests/abc456/tasks/abc456_e
 *
 * Submissions ~> https://atcoder.jp/contests/abc456/submissions/75449526 By huanhuanonly
 *
 * @b Dfs on @a Graphs
 *
 * ----May 02, 2026 [21h:05m:41s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, m;
        std::cin >> n >> m;

        std::vector<std::vector<int>> e(n + 1);

        for (int i = 0; i < m; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            e[u].push_back(v);
            e[v].push_back(u);
        }

        int w;
        std::cin >> w;

        std::vector<std::string> s(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> s[i];
        }

        std::vector vis(n + 1, std::vector(w, false));
        std::vector inq(n + 1, std::vector(w, false));

        auto dfs = [&](const auto& self, int u, int d) -> bool
        {
            if (s[u][d] == 'x')
            {
                return false;
            }

            if (inq[u][d])
            {
                return true;
            }

            if (vis[u][d])
            {
                return false;
            }

            vis[u][d] = true;
            inq[u][d] = true;

            if (self(self, u, (d + 1) % w))
            {
                inq[u][d] = false;
                return true;
            }

            for (const auto& v : e[u])
            {
                if (self(self, v, (d + 1) % w))
                {
                    inq[u][d] = false;
                    return true;
                }
            }

            inq[u][d] = false;
            return false;
        };

        bool yes = false;

        for (int i = 1; i <= n; ++i)
        {
            if (not vis[i][0])
            {
                if (dfs(dfs, i, 0))
                {
                    yes = true;
                    break;
                }
            }
        }

        if (yes)
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
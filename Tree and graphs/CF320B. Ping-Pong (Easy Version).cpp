/**
 * Codeforces Round 189 (Div. 2)
 * 
 * => B. Ping-Pong (Easy Version) ( @c 1500 )
 * 
 * -> https://codeforces.com/problemset/problem/320/B
 * 
 * Submissions ~> https://codeforces.com/contest/320/submission/319366429 By huanhuanonly
 * 
 * @b Dfs
 * 
 * ----May 12, 2025 [19h:15m:39s]----
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

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> e(n + 1);

    std::vector<std::pair<int, int>> st(1);

    int opt, x, y;
    
    while (n--)
    {
        std::cin >> opt >> x >> y;

        if (opt == 1)
        {
            for (int i = 1; i < st.size(); ++i)
            {
                const auto& [l, r] = st[i];

                if ((x < l and l < y) or (x < r and r < y))
                {
                    e[i].push_back(st.size());
                }

                if ((l < x and x < r) or (l < y and y < r))
                {
                    e[st.size()].push_back(i);
                }
            }

            st.emplace_back(x, y);
        }
        else
        {
            auto dfs = [&, vis = std::vector<bool>(st.size())](auto& self, int u) mutable -> bool
            {
                if (u == y)
                {
                    return true;
                }

                if (vis[u])
                {
                    return false;
                }

                vis[u] = true;

                for (int i : e[u])
                {
                    if (self(self, i))
                    {
                        return true;
                    }
                }

                return false;
            };

            std::cout << (dfs(dfs, x) ? "YES\n" : "NO\n");
        }
    }
    

    return 0;
}
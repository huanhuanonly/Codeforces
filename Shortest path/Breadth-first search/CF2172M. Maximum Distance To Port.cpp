/**
 * 2025 ICPC Asia Taichung Regional Contest (Unrated, Online Mirror, ICPC Rules, Preferably Teams)
 * 
 * => M. Maximum Distance To Port ( @c 1300 )
 * 
 * -> https://codeforces.com/contest/2172/problem/M
 * 
 * Submissions ~> https://codeforces.com/contest/2172/submission/354966517 By huanhuanonly
 * 
 * @b Breadth-first-search
 * 
 * ----December 25, 2025 [00h:20m:20s]----
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

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> c(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> c[i];
    }

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    std::vector<int> dis(k + 1);

    std::queue<std::pair<int, int>> que;
    que.emplace(1, 0);

    std::vector<bool> vis(n + 1);

    while (not que.empty())
    {
        const auto [u, d] = que.front();
        que.pop();

        if (vis[u])
        {
            continue;
        }

        vis[u] = true;
        dis[c[u]] = std::max(dis[c[u]], d);

        for (const int i : e[u])
        {
            que.emplace(i, d + 1);
        }
    }

    for (int i = 1; i <= k; ++i)
    {
        std::cout << dis[i] << ' ';
    }

    return 0;
}
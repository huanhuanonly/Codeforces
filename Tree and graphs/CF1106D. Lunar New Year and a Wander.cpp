/**
 * Codeforces Round 536 (Div. 2)
 * 
 * => D. Lunar New Year and a Wander ( @c 1500 )
 * 
 * -> https://codeforces.com/problemset/problem/1106/D
 * 
 * Submissions ~> https://codeforces.com/contest/1106/submission/319333634 By huanhuanonly
 * 
 * @b Bfs
 * 
 * ----May 12, 2025 [14h:13m:47s]----
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

    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> e(n + 1);

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    std::vector<bool> vis(n + 1);

    std::vector<int> ans;
    ans.reserve(n);

    std::priority_queue<int, std::vector<int>, std::greater<int>> que;
    que.push(1);

    vis[1] = true;

    while (not que.empty())
    {
        int u = que.top();
        que.pop();

        ans.push_back(u);

        for (int i : e[u])
        {
            if (not vis[i])
            {
                que.push(i);
                vis[i] = true;
            }
        }
    }

    for (int i : ans)
    {
        std::cout << i << ' ';
    }

    return 0;
}
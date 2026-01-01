/**
 * Codeforces Round 361 (Div. 2)
 * 
 * => B. Mike and Shortcuts ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/689/problem/B
 * 
 * Submissions ~> https://codeforces.com/contest/689/submission/340327998 By huanhuanonly
 * 
 * @b Breadth-first-search
 * 
 * ----September 25, 2025 [17h:38m:29s]----
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

    int n;
    std::cin >> n;

    std::vector<int> sc(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> sc[i];
    }

    constexpr int inf = std::numeric_limits<int>::max() / 2;

    std::vector<int> dis(n + 1, inf);

    std::vector<bool> vis(n + 1);

    std::queue<int> que;
    
    que.push(1);
    dis[1] = 0;
    vis[1] = true;

    while (not que.empty())
    {
        const int u = que.front();
        que.pop();

        for (const int i : std::array{sc[u], u - 1, u + 1})
        {
            if (not vis[i] and 1 <= i and i <= n)
            {
                vis[i] = true;
                dis[i] = dis[u] + 1;

                que.push(i);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        std::cout << dis[i] << ' ';
    }

    return 0;
}
/**
 * Codeforces Round 318 [RussianCodeCup Thanks-Round] (Div. 2)
 * 
 * => B. Bear and Three Musketeers ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/574/problem/B
 * 
 * Submissions ~> https://codeforces.com/contest/574/submission/328500146 By huanhuanonly
 * 
 * @b Brute-force
 * 
 * ----July 11, 2025 [17h:12m:49s]----
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

    for (int i = 1; i <= n; ++i)
    {
        std::ranges::sort(e[i]);
    }

    int ans = std::numeric_limits<int>::max();

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < e[i].size(); ++j)
        {
            for (int k = j + 1; k < e[i].size(); ++k)
            {
                if (std::ranges::binary_search(e[e[i][j]], e[i][k]))
                {
                    ans = std::min(ans, static_cast<int>(e[i].size() + e[e[i][j]].size() + e[e[i][k]].size()) - 2 * 3);
                }
            }
        }
    }

    if (ans == std::numeric_limits<int>::max())
    {
        std::cout << -1;
    }
    else
    {
        std::cout << ans;
    }

    return 0;
}
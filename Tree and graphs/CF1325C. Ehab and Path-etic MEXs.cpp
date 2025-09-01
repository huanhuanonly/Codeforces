/**
 * Codeforces Round 628 (Div. 2)
 * 
 * => C. Ehab and Path-etic MEXs ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/1325/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/1325/submission/324788886 By huanhuanonly
 * 
 * @b Dfs
 * 
 * ----June 17, 2025 [22h:31m:27s]----
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

    std::vector<std::pair<int, int>> e(n - 1);

    std::vector<int> d(n + 1);

    for (int i = 0; i < e.size(); ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[i] = {u, v};

        ++d[u];
        ++d[v];
    }

    int cpos = -1;
    std::vector<int> ans(e.size());

    for (int i = 0; i < e.size(); ++i)
    {
        if (d[e[i].first] == 1 or d[e[i].second] == 1)
        {
            ans[i] = ++cpos;
        }
    }

    for (int i = 0; i < e.size(); ++i)
    {
        if (not(d[e[i].first] == 1 or d[e[i].second] == 1))
        {
            ans[i] = ++cpos;
        }
    }

    for (int i = 0; i < ans.size(); ++i)
    {
        std::cout << ans[i] << '\n';
    }

    return 0;
}
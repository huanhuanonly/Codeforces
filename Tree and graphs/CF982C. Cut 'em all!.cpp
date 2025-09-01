/**
 * Codeforces Round 484 (Div. 2)
 * 
 * => C. Cut 'em all! ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/982/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/982/submission/327342917 By huanhuanonly
 * 
 * @b Dfs
 * 
 * ----July 04, 2025 [15h:45m:58s]----
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

    if (n & 1)
    {
        std::cout << -1;
    }
    else
    {
        std::vector<std::vector<int>> e(n + 1);

        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            e[u].push_back(v);
            e[v].push_back(u);
        }

        int ans = 0;

        auto dfs = [&](const auto& self, int u, int fa) -> int
        {
            int cnt = 1;

            for (int i : e[u] | std::views::filter([&](int i) -> bool { return i != fa; }))
            {
                int res = self(self, i, u);

                cnt += res;
                ans += not (res & 1);
            }

            return cnt;
        };

        dfs(dfs, 1, 0);
        std::cout << ans;
    }
    
    return 0;
}
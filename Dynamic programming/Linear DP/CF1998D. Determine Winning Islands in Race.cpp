/**
 * Codeforces Round 965 (Div. 2)
 * 
 * => D. Determine Winning Islands in Race ( @c 2100 )
 * 
 * -> https://codeforces.com/contest/1998/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/1998/submission/343620760 By huanhuanonly
 * 
 * @b Linear-DP
 * 
 * ----October 14, 2025 [08h:45m:43s]----
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

        std::vector<std::vector<int>> e(n + 1);

        for (int i = 1; i < n; ++i)
        {
            e[i].push_back(i + 1);
        }
        
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            std::cin >> u >> v;
            
            e[u].push_back(v);
        }
        
        constexpr int inf = std::numeric_limits<int>::max() / 2;

        std::vector<int> dp(n + 1, inf);
        dp[0] = dp[1] = 0;
        
        std::string ans(n, '1');

        std::multiset<int, std::ranges::greater> set;

        for (int i = 1; i < n; ++i)
        {
            if (not set.empty() and *set.begin() > i)
            {
                ans[i] = '0';
            }

            for (int j : e[i])
            {
                if (dp[j] > dp[i] + 1)
                {
                    set.extract(j - dp[j]);

                    dp[j] = dp[i] + 1;
                    
                    set.insert(j - dp[j]);
                }
            }
        }

        std::cout << std::string_view(ans.begin() + 1, ans.end()) << '\n';
    }

    return 0;
}
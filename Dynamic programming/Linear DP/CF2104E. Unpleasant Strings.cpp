/**
 * Educational Codeforces Round 178 (Rated for Div. 2)
 * 
 * => E. Unpleasant Strings ( @c Rating )
 * 
 * -> https://codeforces.com/contest/2104/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2104/submission/318424852 By huanhuanonly
 * 
 * @b Linear-DP
 * 
 * ----May 05, 2025 [16h:57m:07s]----
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

    int n, k;
    std::cin >> n >> k;

    std::array<std::vector<int>, 26> log;
    
    for (int i = 0; i < n; ++i)
    {
        char c;
        std::cin >> c;

        log[c - 'a'].push_back(i);
    }
    
    const int inf = n;
    
    for (int i = 0; i < k; ++i)
    {
        log[i].push_back(inf);
    }
    
    std::vector<int> dp(n + 1);

    for (int i = n - 1; i >= 0; --i)
    {
        int mx = 0;

        for (int j = 0; j < k; ++j)
        {
            mx = std::max(mx, *std::upper_bound(log[j].begin(), log[j].end(), i));
        }

        dp[i] = dp[mx] + 1;
    }

    int q;
    std::cin >> q;
    
    std::string t;

    while (q--)
    {
        std::cin >> t;

        int pos = -1;

        for (int i = 0; i < t.size(); ++i)
        {
            pos = *std::upper_bound(log[t[i] - 'a'].begin(), log[t[i] - 'a'].end(), pos);

            if (pos == inf)
            {
                break;
            }
        }

        std::cout << dp[pos] << '\n';
    }

    return 0;
}
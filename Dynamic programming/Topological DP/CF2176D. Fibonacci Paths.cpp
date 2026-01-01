/**
 * Codeforces Round 1070 (Div. 2)
 * 
 * => D. Fibonacci Paths ( @c 1800 )
 * 
 * -> https://codeforces.com/contest/2176/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2176/submission/353130879 By huanhuanonly
 * 
 * @b Topological-DP
 * 
 * ----December 12, 2025 [09h:50m:20s]----
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
        uint64 n, m;
        std::cin >> n >> m;

        std::vector<uint64> a(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
        }
        
        std::vector<std::pair<int, int>> e(m);
        
        for (int i = 0; i < m; ++i)
        {
            std::cin >> e[i].first >> e[i].second;
        }
        
        std::ranges::sort(e, std::ranges::greater{}, [&](const auto& p) -> uint64 { return a[p.first] + a[p.second]; });
        
        std::vector<std::map<uint64, uint64>> dp(n + 1);
        
        constexpr uint64 mod = 998244353;
        uint64 ans = 0;

        for (const auto& [u, v] : e)
        {
            const auto t = 1 + dp[v][a[u] + a[v]];
            
            (dp[u][a[v]] += t) %= mod;
            (ans += t) %= mod;
        }

        std::cout << ans << '\n';
    }

    return 0;
}
/**
 * Neowise Labs Contest 1 (Codeforces Round 1018, Div. 1 + Div. 2)
 * 
 * => C. Wonderful City ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/2096/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2096/submission/316864792 By huanhuanonly
 * 
 * @b Linear-DP
 * 
 * ----April 24, 2025 [01h:13m:38s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        std::vector<std::vector<int>> v(n + 1, std::vector<int>(n + 1));

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                std::cin >> v[i][j];
            }
        }

        std::vector<int> a(n + 1), b(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
        }

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> b[i];
        }

        constexpr int64 inf = std::numeric_limits<int64>::max() / 2;

        auto sum = [&](const std::vector<int>& cost) -> int64
        {
            std::vector<std::vector<int64>> dp(2, std::vector<int64>(n + 1, inf));

            dp[0][1] = 0;
            dp[1][1] = cost[1];

            for (int i = 2; i <= n; ++i)
            {
                for (int x = 0; x <= 1; ++x)
                {
                    for (int y = 0; y <= 1; ++y)
                    {
                        bool flag = true;

                        for (int j = 1; j <= n; ++j)
                        {
                            if (v[i][j] + x == v[i - 1][j] + y)
                            {
                                flag = false;
                                break;
                            }
                        }

                        if (flag)
                        {
                            dp[x][i] = std::min(dp[x][i], dp[y][i - 1] + (x ? cost[i] : 0));
                        }
                    }
                }
            }

            return std::min(dp[0][n], dp[1][n]);
        };

        int64 ans = sum(a);

        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                std::swap(v[i][j], v[j][i]);
            }
        }

        ans += sum(b);

        if (ans >= inf)
            std::cout << -1 << '\n';
        else
            std::cout << ans << '\n';
    }

    return 0;
}
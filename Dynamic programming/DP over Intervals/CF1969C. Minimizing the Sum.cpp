/**
 * Educational Codeforces Round 165 (Rated for Div. 2)
 * 
 * => C. Minimizing the Sum
 * 
 * -> https://codeforces.com/problemset/problem/1969/C (1700)
 * 
 * @b DP-over-intervals
*/

#include <bits/stdc++.h>

using uint    = unsigned int;
using llong   = long long int;
using ullong  = unsigned long long int;
using ldouble = long double;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
    ::freopen("Input.txt", "r", stdin);
    ::freopen("Output.txt", "w", stdout);
#endif

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, K;
        std::cin >> n >> K;

        std::vector<llong> v(n + 1, INT_MAX);
        std::vector<std::vector<llong>> dp(K + 1, std::vector<llong>(n + 1, LLONG_MAX / 2));

        for (int i = 1; i <= n; ++i)
            std::cin >> v[i];

        for (int i = 0; i <= K; ++i)
            dp[i][0] = 0;

        for (int i = 1; i <= n; ++i)
            dp[0][i] = dp[0][i - 1] + v[i];

        for (int k = 1; k <= K; ++k)
        {
            for (int i = 1; i <= n; ++i)
            {
                dp[k][i] = dp[k][i - 1] + v[i];
                
                llong mn = v[i];

                for (int j = i - 1; j >= std::max(1, i - k); --j)
                {
                    mn = std::min(mn, v[j]);
                    dp[k][i] = std::min(dp[k][i], mn * (i - j + 1) + dp[k - (i - j)][j - 1]);
                }
            }
        }

        std::cout << dp[K][n] << '\n';
    }

    return 0;
}
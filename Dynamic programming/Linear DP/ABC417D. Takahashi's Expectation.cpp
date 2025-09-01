/**
 * AtCoder Beginner Contest 417
 * 
 * => D - Takahashi's Expectation ( @c 425 )
 * 
 * -> https://atcoder.jp/contests/abc417/tasks/abc417_d
 * 
 * Submissions ~> https://atcoder.jp/contests/abc417/submissions/68157211 By huanhuanonly
 * 
 * @b Linear-DP
 * 
 * ----August 02, 2025 [21h:41m:56s]----
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

    int64 n;
    std::cin >> n;

    struct item
    {
        int64 p, a, b;
    };

    std::vector<item> v(n + 1);

    std::vector<int64> pre(n + 1);

    for (int64 i = 1; i <= n; ++i)
    {
        std::cin >> v[i].p >> v[i].a >> v[i].b;
        pre[i] = pre[i - 1] + v[i].b;
    }

    std::vector dp(2000 + 1, std::vector<int64>(n + 2));

    for (int64 i = 0; i < dp.size(); ++i)
    {
        dp[i][n + 1] = i;
    }

    for (int64 j = n; j >= 1; --j)
    {
        for (int64 i = 0; i < dp.size(); ++i)
        {
            if (v[j].p >= i)
            {
                dp[i][j] = dp[i + v[j].a][j + 1];
            }
            else
            {
                dp[i][j] = dp[std::max(i - v[j].b, 0LL)][j + 1];
            }
        }
    }

    int q;
    std::cin >> q;

    while (q--)
    {
        int64 x;
        std::cin >> x;

        auto it = std::upper_bound(pre.begin(), pre.end(), x - 2000);

        if (it != pre.end())
        {
            std::cout << dp[x - *it][it - pre.begin() + 1] << '\n';
        }
        else
        {
            std::cout << x - pre.back() << '\n';
        }
    }

    return 0;
}
/**
 * Codeforces Round 105 (Div. 2)
 * 
 * => E. Porcelain ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/148/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/148/submission/371157777 By huanhuanonly
 * 
 * @b Knapsack-DP ( @a group-knapsack-problem )
 * @b Prefix-sum
 * 
 * ----April 15, 2026 [00h:22m:44s]----
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

#if defined(__SIZEOF_INT128__)
using int128 = __int128;
using uint128 = unsigned __int128;
#endif

using real32 = float;
using real64 = double;

#if defined(__SIZEOF_FLOAT80__)
using real80 = __float80;
#endif

#if defined(__SIZEOF_FLOAT128__)
using real128 = __float128;
#endif

void chmax(auto& lhs, auto&& rhs)
{
    if (lhs < rhs)
    {
        lhs = std::forward<decltype(rhs)>(rhs);
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> v(n);
    std::vector<std::vector<int>> obj(n);

    for (int i = 0; i < n; ++i)
    {
        int k;
        std::cin >> k;

        v[i].resize(k);
        obj[i].resize(k + 1);

        for (int j = 0; j < k; ++j)
        {
            std::cin >> v[i][j];
        }

        std::partial_sum(v[i].begin(), v[i].end(), v[i].begin());

        for (int l = -1; l < k; ++l)
        {
            for (int r = l + 1; r <= k; ++r)
            {
                chmax(obj[i][k - (r - l - 1)], (l >= 0 ? v[i][l] : 0) + (v[i][k - 1] - (r ? v[i][r - 1] : 0)));
            }
        }
    }

    std::vector dp(n, std::vector(m + 1, 0));

    std::ranges::copy(obj.front() | std::views::take(dp.front().size()), dp.front().begin());

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < obj[i].size(); ++j)
        {
            for (int k = j; k <= m; ++k)
            {
                chmax(dp[i][k], dp[i - 1][k - j] + obj[i][j]);
            }
        }

        for (int k = 1; k <= m; ++k)
        {
            chmax(dp[i][k], dp[i - 1][k]);
        }

        std::partial_sum(dp[i].begin(), dp[i].end(), dp[i].begin(), std::ranges::max);
    }

    std::cout << dp.back().back() << '\n';

    return 0;
}
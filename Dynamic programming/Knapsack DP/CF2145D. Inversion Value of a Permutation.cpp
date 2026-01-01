/**
 * Educational Codeforces Round 183 (Rated for Div. 2)
 * 
 * => D. Inversion Value of a Permutation ( @c 1800 )
 * 
 * -> https://codeforces.com/contest/2145/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2145/submission/342375324 By huanhuanonly
 * 
 * @b Knapsack-DP ( @a complete-knapsack-problem )
 * 
 * ----October 07, 2025 [10h:45m:00s]----
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

int calc(const auto& p)
{
    int sum = 0;

    for (int l = 0; l < p.size(); ++l)
    {
        for (int r = l + 1; r < p.size(); ++r)
        {
            bool add = false;

            for (int i = l; i <= r and not add; ++i)
            {
                for (int j = i + 1; j <= r and not add; ++j)
                {
                    if (p[i] > p[j])
                    {
                        add = true;
                    }
                }
            }

            sum += add;
        }
    }

    return sum;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#else
#   undef  assert
#   define assert(...)
#endif

    constexpr int maxn = 30;
    constexpr int inf = std::numeric_limits<int>::max() / 2;

    std::vector<int> dp(maxn * (maxn - 1) / 2 + 1, inf);
    std::vector<int> last(maxn * (maxn - 1) / 2 + 1, -1);

    dp[0] = 0;

    for (int i = 1, v = 0; i <= maxn; ++i)
    {
        const int w = i + 1;
        v += i;

        for (int j = 0; j + v < dp.size(); ++j)
        {
            if (dp[j + v] > dp[j] + w)
            {
                dp[j + v] = dp[j] + w;
                last[j + v] = j;
            }
        }
    }

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> p(n);
        std::iota(p.rbegin(), p.rend(), 1);

        if (dp[n * (n - 1) / 2 - k] > n)
        {
            std::cout << 0;
        }
        else
        {
            for (int i = 0, j = n * (n - 1) / 2 - k; i < n and ~last[j]; )
            {
                const int len = dp[j] - dp[last[j]];

                std::ranges::reverse(p.begin() + i, p.begin() + i + len);

                i += len;
                j = last[j];
            }

            assert(calc(p) == k);

            std::ranges::for_each(p, [](int i) -> void {
                std::cout << i << ' ';
            });
        }

        std::cout.put('\n');
    }

    return 0;
}
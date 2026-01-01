/**
 * Codeforces Round 1066 (Div. 1 + Div. 2)
 * 
 * => D. Billion Players Game ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/2157/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2157/submission/354630495 By huanhuanonly
 * 
 * @b Prefix-sum
 * 
 * ----December 23, 2025 [10h:41m:37s]----
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
        int64 n, l, r;
        std::cin >> n >> l >> r;

        std::vector<int64> v(n + 2);

        for (int64 i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
        }
        
        std::ranges::sort(v.begin() + 1, v.end() - 1);

        std::vector<int64> pre(n + 2), suf(n + 2);
        std::partial_sum(v.begin(), v.end(), pre.begin());
        std::partial_sum(v.rbegin(), v.rend(), suf.rbegin());

        int64 ans = 0;

        for (int64 i = 0; i <= n; ++i)
        {
            const auto a = l * (i - (n - i)) - pre[i] + suf[i + 1];
            const auto b = r * (i - (n - i)) - pre[i] + suf[i + 1];

            ans = std::max(ans, std::min(a, b));
        }

        for (int64 i = 1; i <= n; ++i)
        {
            const auto a = l * ((i - 1) - (n - i)) - pre[i - 1] + suf[i + 1];
            const auto b = r * ((i - 1) - (n - i)) - pre[i - 1] + suf[i + 1];

            ans = std::max(ans, std::min(a, b));
        }

        std::cout << ans << '\n';
    }

    return 0;
}
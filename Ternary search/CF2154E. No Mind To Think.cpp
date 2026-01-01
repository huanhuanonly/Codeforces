/**
 * Codeforces Round 1060 (Div. 2)
 * 
 * => E. No Mind To Think ( @c 2500 )
 * 
 * -> https://codeforces.com/contest/2154/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2154/submission/345207839 By huanhuanonly
 * 
 * @b Ternary-search
 * 
 * ----October 22, 2025 [22h:58m:08s]----
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
        int n, k;
        std::cin >> n >> k;

        std::vector<int64> v(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
        }

        std::ranges::sort(v | std::views::drop(1));

        auto pre = v;
        std::partial_sum(pre.begin(), pre.end(), pre.begin());

        auto get = [&](int l, int r) -> int64
        {
            return pre[r] - pre[l - 1];
        };

        int64 sum = pre.back();
        int64 ans = sum;

        for (int64 i = 1; i <= n; ++i)
        {
            const auto med = v[i];

            auto check = [&](int64 y) -> int64
            {
                const int64 x = std::min(k * y, i - 1);

                const int64 cost1 = med * x - get(1, x);
                const int64 cost2 = med * y - get(i + 1, i + y);

                return sum + cost1 + cost2;
            };

            int64 l = 0, r = std::min(i - 1, n - i), mid;

            while (l < r)
            {
                mid = l + r >> 1;

                if (check(mid) <= check(mid + 1))
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }

            ans = std::max(ans, check(l));
        }

        std::cout << ans << '\n';
    }

    return 0;
}
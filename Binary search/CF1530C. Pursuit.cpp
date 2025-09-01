/**
 * Codeforces Round 733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))
 * 
 * => C. Pursuit ( @c 1200 )
 * 
 * -> https://codeforces.com/contest/1530/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/1530/submission/328257170 By huanhuanonly
 * 
 * @b Binary-search
 * 
 * ----July 09, 2025 [23h:48m:29s]----
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
        int n;
        std::cin >> n;

        std::vector<int> a(n + 1), b(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
        }

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> b[i];
        }

        std::ranges::sort(a | std::views::drop(1), std::greater());
        std::ranges::sort(b | std::views::drop(1), std::greater());

        std::partial_sum(a.begin(), a.end(), a.begin());
        std::partial_sum(b.begin(), b.end(), b.begin());

        auto check = [&](int mid) -> bool
        {
            int k = mid - mid / 4;

            int sa = a[std::clamp(k - (std::max(mid, n) - n), 0, n)] + (std::max(mid, n) - n) * 100;
            int sb = b[std::min(k, n)];

            return sa >= sb;
        };

        check(7);

        int l = 0, r = n * 2, mid;

        while (r - l > 1)
        {
            mid = l + r >> 1;

            if (check(mid))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }

        std::cout << std::max(r - n, 0) << '\n';
    }

    return 0;
}
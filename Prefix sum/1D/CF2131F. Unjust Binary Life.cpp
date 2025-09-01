/**
 * Codeforces Round 1042 (Div. 3)
 * 
 * => F. Unjust Binary Life ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/2131/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/2131/problem/F By huanhuanonly
 * 
 * @b Prefix-sum and @b Binary-search
 * 
 * ----August 12, 2025 [20h:02m:33s]----
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
        int64 n;
        std::cin >> n;

        std::string a, b;
        std::cin >> a >> b;

        int64 ans = n * n * (n + 1);

        std::vector<int64> prea(n + 1), preb(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            prea[i] = prea[i - 1] + (a[i - 1] == '0' ? +1 : -1);
        }

        for (int i = 1; i <= n; ++i)
        {
            preb[i] = preb[i - 1] + (b[i - 1] == '1' ? +1 : -1);
        }

        std::ranges::sort(preb | std::views::drop(1));

        auto sum = preb;
        std::partial_sum(sum.begin() + 1, sum.end(), sum.begin() + 1);

        auto get = [&sum](int l, int r) -> int64
        {
            return sum[r] - sum[l - 1];
        };

        for (int i = 1; i <= n; ++i)
        {
            int64 pos = std::ranges::upper_bound(preb, prea[i]) - preb.begin();

            if (pos != 0)
            {
                ans -= prea[i] * (pos - 1) - get(1, pos - 1);
            }
            else
            {
                pos = 1;
            }

            if (pos != n + 1)
            {
                ans -= get(pos, n) - prea[i] * (n - pos + 1);
            }
        }

        std::cout << ans / 2 << '\n';
    }

    return 0;
}
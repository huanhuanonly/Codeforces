/**
 * Codeforces Round 1053 (Div. 2)
 * 
 * => C. Incremental Stay ( @c 1400 )
 * 
 * -> https://codeforces.com/contest/2151/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2151/submission/340169584 By huanhuanonly
 * 
 * @b Even-odd-prefix-sum
 * 
 * ----September 25, 2025 [11h:21m:42s]----
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

        std::vector<int64> v(n * 2 + 1);

        for (int i = 1; i <= n * 2; ++i)
        {
            std::cin >> v[i];
        }

        auto pre = v;

        for (int i = 3; i <= n * 2; ++i)
        {
            pre[i] += pre[i - 2];
        }

        int64 sum = 0;

        for (int i = 0; i < n; ++i)
        {
            std::cout << sum + (pre[n * 2 - i] - pre[1 + i + 1 - 2]) - (pre[n * 2 - i - 1] - pre[std::max(1 + i - 2, 0)]) << ' ';

            sum += v[n * 2 - i] - v[1 + i];
        }

        std::cout.put('\n');
    }

    return 0;
}
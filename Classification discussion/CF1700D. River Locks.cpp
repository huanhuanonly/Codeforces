/**
 * Codeforces Round 802 (Div. 2)
 * 
 * => D. River Locks ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/1700/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/1700/submission/342779051 By huanhuanonly
 * 
 * @b Classification-discussion
 * 
 * ----October 09, 2025 [23h:25m:16s]----
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

    int n;
    std::cin >> n;

    std::vector<int64> v(n + 1);

    int64 max = 0;

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
        v[i] += v[i - 1];

        max = std::max(max, (v[i] + i - 1) / i);
    }

    int q;
    std::cin >> q;

    while (q--)
    {
        int64 t;
        std::cin >> t;

        if (t < max)
        {
            std::cout << -1 << '\n';
        }
        else
        {
            std::cout << (v[n] + t - 1) / t << '\n';
        }
    }

    return 0;
}
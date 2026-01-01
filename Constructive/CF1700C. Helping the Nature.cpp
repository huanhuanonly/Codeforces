/**
 * Codeforces Round 802 (Div. 2)
 * 
 * => C. Helping the Nature ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/1700/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/1700/submission/342761363 By huanhuanonly
 * 
 * @b Constructive ( @a Normalization )
 * 
 * ----October 09, 2025 [21h:36m:51s]----
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

        std::vector<int64> v(n);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i];
        }

        int64 cnt = 0;

        int64 add = 0;

        for (int i = 1; i < n; ++i)
        {
            v[i] += add;

            if (v[i - 1] >= v[i])
            {
                cnt += v[i - 1] - v[i];
            }
            else
            {
                const auto diff = v[i] - v[i - 1];

                v[i] = v[i - 1];
                
                cnt += diff;
                add -= diff;
            }
        }

        std::cout << cnt + std::abs(v.back()) << '\n';
    }

    return 0;
}
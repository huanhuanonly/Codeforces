/**
 * Codeforces Round 321 (Div. 2)
 * 
 * => B. Kefa and Company ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/580/problem/B
 * 
 * Submissions ~> https://codeforces.com/contest/580/submission/329169558 By huanhuanonly
 * 
 * @b Two-pointers ( @a ==> )
 * 
 * ----July 16, 2025 [17h:25m:46s]----
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

    int64 n, d;
    std::cin >> n >> d;

    std::vector<std::pair<int, int>> v(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i].first >> v[i].second;
    }

    std::ranges::sort(v);

    int64 ans = 0, sum = v[0].second;

    for (int i = 0, j = 0; j < n; )
    {
        if (std::abs(v[j].first - v[i].first) < d)
        {
            ans = std::max(ans, sum);
            
            if (++j < n)
            {
                sum += v[j].second;
            }
        }
        else
        {
            sum -= v[i++].second;
        }
    }

    std::cout << ans;

    return 0;
}
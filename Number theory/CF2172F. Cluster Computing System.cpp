/**
 * 2025 ICPC Asia Taichung Regional Contest (Unrated, Online Mirror, ICPC Rules, Preferably Teams)
 * 
 * => F. Cluster Computing System ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/2172/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/2172/submission/355013359 By huanhuanonly
 * 
 * @b Number-theory ( @a greatest-common-divisor )
 * 
 * ----December 25, 2025 [14h:25m:33s]----
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

    std::vector<int> v(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
    }

    std::vector<int> pre(n), suf(n);

    std::partial_sum(v.begin(), v.end(), pre.begin(), &std::gcd<int, int>);
    std::partial_sum(v.rbegin(), v.rend(), suf.rbegin(), &std::gcd<int, int>);

    int64 sum = 0;

    for (int i = 1; i < n - 1; ++i)
    {
        if (const auto dl = pre[i], dr = suf[i]; dl <= dr)
        {
            sum += dl;
        }
        else
        {
            sum += dr;
        }
    }

    sum += pre[n - 1];

    std::cout << sum;

    return 0;
}
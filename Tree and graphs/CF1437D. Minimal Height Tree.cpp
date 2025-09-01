/**
 * Educational Codeforces Round 97 (Rated for Div. 2)
 * 
 * => D. Minimal Height Tree ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/1437/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/1437/submission/330785779 By huanhuanonly
 * 
 * @b Trees
 * 
 * ----July 25, 2025 [17h:38m:17s]----
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

        std::vector<int> v(n);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i];
        }

        int ans = 0;
        int fork = 1;

        for (int i = 1; i < n; )
        {
            ++ans;
            int cur = fork;

            for (++i; i < n; ++i)
            {
                if (v[i - 1] < v[i])
                {
                    ++fork;
                }
                else if (--cur == 0)
                {
                    break;
                }
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}
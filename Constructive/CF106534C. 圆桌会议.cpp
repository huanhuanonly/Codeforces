/**
 * CCPC2026黑龙江省大学生程序设计竞赛
 *
 * => C. 圆桌会议
 *
 * -> https://codeforces.com/gym/106534/problem/C
 *
 * Submissions ~> https://codeforces.com/gym/106534/submission/375347012 By huanhuanonly
 *
 * @b Constructive
 *
 * ----May 20, 2026 [20h:27m:13s]----
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

#if defined(__SIZEOF_INT128__)
using int128 = __int128;
using uint128 = unsigned __int128;
#endif

using real32 = float;
using real64 = double;

#if defined(__SIZEOF_FLOAT80__)
using real80 = __float80;
#endif

#if defined(__SIZEOF_FLOAT128__)
using real128 = __float128;
#endif

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

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

        int idx = 0;

        for (int i = 0; i < n; i += 3)
        {
            v[i] = ++idx;

            if (i + 1 < n)
            {
                v[i + 1] = n - idx + 1;
            }
        }

        for (int i = 2; i < n; i += 3)
        {
            v[i] = ++idx;
        }

        for (int i = 0; i < n; ++i)
        {
            std::cout << v[i] << " \n"[i + 1 == n];
        }
    }

    return 0;
}
/**
 * 牛客周赛 Round 145
 *
 * => F-小红的好串构造 ( @c 1700 )
 *
 * -> https://ac.nowcoder.com/acm/contest/134981/F
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83710706 By huanhuanonly
 *
 * @b Constructive
 *
 * ----May 27, 2026 [21h:15m:17s]----
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
        int n, k;
        std::cin >> n >> k;

        const int d = 2 * (n - 2) - k;

        std::string s = "a" + std::string(n - 2 - d, 'b');

        for (int i = 0; s.size() < n; ++i %= 3)
        {
            s.push_back("cde"[i]);
        }

        std::cout << s << '\n';
    }

    return 0;
}
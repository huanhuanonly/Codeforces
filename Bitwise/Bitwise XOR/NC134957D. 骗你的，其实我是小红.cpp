/**
 * 牛客周赛 Round 144
 *
 * => D-骗你的，其实我是小红 ( @c 1300 )
 *
 * -> https://ac.nowcoder.com/acm/contest/134957/D
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83649401 By huanhuanonly
 *
 * @b Bitwise-XOR
 *
 * ----May 20, 2026 [11h:19m:19s]----
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

    uint64 l, r, k;
    std::cin >> l >> r >> k;

    const uint64 len = r - l + 1;
    const uint64 cnt = len / k;
    const uint64 rem = len % k;

    static const auto $ = [](uint64 n) -> uint64
    {
        return n * (n - 1) / 2;
    };

    std::cout << (k - rem) * $(cnt) + rem * $(cnt + 1) << '\n';

    return 0;
}
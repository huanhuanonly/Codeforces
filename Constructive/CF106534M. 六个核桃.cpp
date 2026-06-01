/**
 * CCPC2026黑龙江省大学生程序设计竞赛
 *
 * => M. 六个核桃
 *
 * -> https://codeforces.com/gym/106534/problem/M
 *
 * Submissions ~> https://codeforces.com/gym/106534/submission/375339346 By huanhuanonly
 *
 * @b Constructive
 *
 * ----May 20, 2026 [19h:25m:42s]----
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

    int n, m;
    std::cin >> n >> m;

    std::vector<int> v(n);
    std::ranges::iota(v, 1);

    std::ranges::rotate(v, v.begin() + std::min(m, n / 2));

    std::ranges::for_each(v, [](int i) { std::cout << i << ' '; });

    return 0;
}
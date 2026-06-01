/**
 * The 2026 ICPC China Wuhan National Invitational and Hubei Provincial Programming Contest
 *
 * => D. Prime Game
 *
 * -> https://qoj.ac/contest/3757/problem/22151
 *
 * Submissions ~> https://qoj.ac/submission/2405392 By huanhuanonly
 *
 * @b Game-theory
 *
 * ----May 19, 2026 [23h:14m:33s]----
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

int A(uint64);
int B(uint64);

int A(uint64 n)
{
    int ans = 0;

    for (uint64 i = 1; i < n << 1; i *= 3)
    {
        uint64 j = i;
        for (; j < n; j <<= 1);

        ans = std::max(ans, B(j));
    }

    return ans;
}

int B(uint64 n)
{
    static std::map<uint64, int> map;

    if (n <= 1)
    {
        return 0;
    }

    if (map.contains(n))
    {
        return map[n];
    }

    if (std::has_single_bit(n))
    {
        return map[n] = A(n / 2) + 1;
    }
    else
    {
        return map[n] = A(n / 3) + 1;
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    uint64 n;
    std::cin >> n;

    std::cout << A(n) << '\n';

    return 0;
}
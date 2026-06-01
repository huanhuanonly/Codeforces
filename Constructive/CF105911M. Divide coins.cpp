/**
 * 2025 ICPC Nanchang Invitational and Jiangxi Provincial Collegiate Programming Contest
 * 
 * => M. Divide coins
 * 
 * -> https://codeforces.com/gym/105911/problem/M
 * 
 * Submissions ~> https://codeforces.com/gym/105911/submission/372777693 By huanhuanonly
 * 
 * @b Constructive
 * 
 * ----April 28, 2026 [14h:50m:58s]----
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

    int n, k;
    std::cin >> n >> k;

    std::cout << std::string(k, '1') << std::string(n - k, '4') << '\n';

    return 0;
}
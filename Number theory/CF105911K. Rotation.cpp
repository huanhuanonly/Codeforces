/**
 * 2025 ICPC Nanchang Invitational and Jiangxi Provincial Collegiate Programming Contest
 * 
 * => K. Rotation
 * 
 * -> https://codeforces.com/gym/105911/problem/K
 * 
 * Submissions ~> https://codeforces.com/gym/105911/submission/372780876 By huanhuanonly
 * 
 * @b Number-theory ( @a modular-arithmetic )
 * 
 * ----April 28, 2026 [15h:50m:08s]----
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

    int n;
    std::cin >> n;

    std::array<int, 4> cnt{};

    for (int i = 0, v; i < n; ++i)
    {
        std::cin >> v;
        ++cnt[v];
    }

    int ans = std::numeric_limits<int>::max();

    int sum;
    
    sum = cnt[1] + cnt[2] * 2 + cnt[3] * 3;
    sum += (4 - ((0 + sum) % 4)) % 4;
    ans = std::min(ans, sum);
    
    sum = cnt[0] * 3 + cnt[2] + cnt[3] * 2;
    sum += (4 - ((1 + sum) % 4)) % 4;
    ans = std::min(ans, sum);
    
    sum = cnt[0] * 2 + cnt[1] * 3 + cnt[3];
    sum += (4 - ((2 + sum) % 4)) % 4;
    ans = std::min(ans, sum);
    
    sum = cnt[0] + cnt[1] * 2 + cnt[2] * 3;
    sum += (4 - ((3 + sum) % 4)) % 4;
    ans = std::min(ans, sum);

    std::cout << ans << '\n';

    return 0;
}
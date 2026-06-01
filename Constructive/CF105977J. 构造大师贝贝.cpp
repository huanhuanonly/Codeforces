/**
 * 2025 National Invitational of CCPC (Fujian), The 12th Fujian Collegiate Programming Contest
 * 
 * => J. 构造大师贝贝
 * 
 * -> https://codeforces.com/gym/105977/problem/J
 * 
 * Submissions ~> https://codeforces.com/gym/105977/submission/372732637 By huanhuanonly
 * 
 * @b Constructive
 * @b Number-theory ( @a divisor )
 * 
 * ----April 28, 2026 [00h:06m:30s]----
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
        uint64 n;
        std::cin >> n;

        std::vector<uint64> ans;

        for (; std::pow(uint64(std::sqrt(n)), 2) != n; ans.push_back(n & -n), n += n & -n);

        std::cout << ans.size() << '\n';

        for (const auto& i : ans)
        {
            std::cout << i << ' ';
        }

        std::cout.put('\n');
    }

    return 0;
}
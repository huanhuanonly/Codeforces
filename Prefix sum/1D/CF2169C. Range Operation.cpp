/**
 * Educational Codeforces Round 184 (Rated for Div. 2)
 * 
 * => C. Range Operation ( @c 1300 )
 * 
 * -> https://codeforces.com/contest/2169/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2169/submission/348982748 By huanhuanonly
 * 
 * @b Prefix-sum
 * 
 * ----November 15, 2025 [00h:42m:34s]----
*/

/**
 * l * (r - l + 1) + r * (r - l + 1) - s[r] + s[l - 1]
 * 
 * j = l - 1
 * 
 * (r - l + 1) * (l + r) - s[r] + s[j]
 * 
 * (r - j) * (j + 1 + r) - s[r] + s[j]
 * 
 * r * (j + 1 + r) - j * (j + 1 + r) - s[r] + s[j]
 * 
 * rj + r + r^2 - (j^2 + j + jr) - s[r] + s[j]
 * 
 * rj + r + r^2 - j^2 - j - jr - s[r] + s[j]
 * 
 * r + r^2 - s[r] - j^2 - j + s[j]
 * 
 * r + r^2 - s[r] - (j^2 + j - s[j])
 * 
 * r + r^2 - s[r] + (s[j] - j^2 - j)
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
        int64 n;
        std::cin >> n;

        std::vector<int64> v(n + 1);

        for (int64 i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
        }

        auto s = v;
        std::partial_sum(s.begin(), s.end(), s.begin());

        int64 add = 0, max = 0;

        for (int64 i = 1; i <= n; ++i)
        {
            add = std::max(add, (i + i * i - s[i]) + max);
            max = std::max(max, s[i] - i * i - i);
        }

        std::cout << s[n] + add << '\n';
    }

    return 0;
}
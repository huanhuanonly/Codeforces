/**
 * Codeforces Round 603 (Div. 2)
 * 
 * => C. Everyone is a Winner! ( @c 1400 )
 * 
 * -> https://codeforces.com/contest/1263/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/1263/submission/327499063 By huanhuanonly
 * 
 * @b Number-theory ( @a division-based-decomposition )
 * 
 * ----July 05, 2025 [17h:40m:41s]----
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

        std::vector<int> ans;

        for (int i = 1; i <= n; i = n / (n / i) + 1)
        {
            ans.push_back(n / i);
        }

        ans.push_back(0);

        std::cout << ans.size() << '\n';

        for (int i : ans | std::views::reverse)
        {
            std::cout << i << ' ';
        }

        std::cout.put('\n');
    }

    return 0;
}
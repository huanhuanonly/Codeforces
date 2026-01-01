/**
 * Codeforces Round 1059 (Div. 3)
 * 
 * => G. Beautiful Tree ( @c 2200 )
 * 
 * -> https://codeforces.com/contest/2162/problem/G
 * 
 * Submissions ~> https://codeforces.com/contest/2162/submission/344864881 By huanhuanonly
 * 
 * @b Constructive and @b Trees
 * 
 * ----October 20, 2025 [20h:30m:28s]----
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

        switch (n)
        {
        case 2:

            std::cout << "-1\n";
            break;

        case 3:
            
            std::cout << "1 3\n";
            std::cout << "2 3\n";
            break;

        case 4:

            std::cout << "1 2\n";
            std::cout << "1 3\n";
            std::cout << "1 4\n";
            break;

        default:

            std::cout << "2 1\n";
            std::cout << "2 3\n";
            std::cout << "3 4\n";

            for (int i = 5; i <= n - 1; ++i)
            {
                std::cout << 2 << ' ' << i << '\n';
            }

            std::cout << 1 << ' ' << n << '\n';
            break;
        }
    }

    return 0;
}
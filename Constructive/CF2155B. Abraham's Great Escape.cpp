/**
 * Codeforces Round 1056 (Div. 2)
 * 
 * => B. Abraham's Great Escape ( @c 1100 )
 * 
 * -> https://codeforces.com/contest/2155/problem/B
 * 
 * Submissions ~> https://codeforces.com/contest/2155/submission/342470239 By huanhuanonly
 * 
 * @b Constructive
 * 
 * ----October 07, 2025 [23h:59m:29s]----
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
        int n, k;
        std::cin >> n >> k;

        if (n * n - 1 == k)
        {
            std::cout << "NO\n";
        }
        else
        {
            std::cout << "YES\n";

            std::vector<std::string> mp(n, std::string(n, 'D'));

            mp.back() = std::string(n, 'R');
            mp.back().back() = 'L';

            for (int i = 0; i < n and k; ++i)
            {
                for (int j = 0; j < n and k; ++j)
                {
                    mp[i][j] = 'U';
                    --k;
                }
            }

            for (int i = 0; i < n; ++i)
            {
                std::cout << mp[i] << '\n';
            }
        }
    }

    return 0;
}
/**
 * Codeforces Round 1056 (Div. 2)
 * 
 * => E. Mimo & Yuyu ( @c 2200 )
 * 
 * -> https://codeforces.com/contest/2155/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2155/submission/342832318 By huanhuanonly
 * 
 * @b Game-theory and @b Classification-discussion
 * 
 * ----October 10, 2025 [10h:02m:19s]----
*/

/// @brief This is an @c interesting problem!

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
        int n, m, k;
        std::cin >> n >> m >> k;

        std::vector<std::pair<int, int>> v(k);

        std::map<int, int> mp{{2, 0}};

        for (int i = 0; i < k; ++i)
        {
            std::cin >> v[i].first >> v[i].second;

            if (v[i].second != 1)
            {
                ++mp[v[i].second];
            }
        }

        if (n == 1)
        {
            if (mp[2] & 1)
            {
                std::cout << "Mimo\n";
            }
            else
            {
                std::cout << "Yuyu\n";
            }
        }
        else
        {
            bool found = false;

            for (const auto& [key, value] : mp)
            {
                if (value & 1)
                {
                    found = true;
                    break;
                }
            }

            if (found)
            {
                std::cout << "Mimo\n";
            }
            else
            {
                std::cout << "Yuyu\n";
            }
        }
    }

    return 0;
}
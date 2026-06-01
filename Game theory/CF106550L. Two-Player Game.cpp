/**
 * The 2026 Jiangsu Collegiate Programming Contest, The 2026 Guangdong Provincial Collegiate Programming Contest
 *
 * => L. Two-Player Game
 *
 * -> https://codeforces.com/gym/106550/problem/L
 *
 * Submissions ~> https://codeforces.com/gym/106550/submission/376462716 By huanhuanonly
 *
 * @b Game-theory
 *
 * ----May 29, 2026 [09h:16m:36s]----
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
        int64 n;
        std::cin >> n;

        std::map<int64, int64> cnt;

        for (int64 i = 0, v; i < n; ++i)
        {
            std::cin >> v;
            ++cnt[v];
        }

        bool win = false;

        int64 sum = 0, rem = n;

        for (const auto& [key, value] : cnt)
        {
            sum += key * value;
            rem -= value;

            if ((sum + key * rem) & 1)
            {
                win = true;
                break;
            }
        }

        if (win)
        {
            std::cout << "Insight\n";
        }
        else
        {
            std::cout << "Maya\n";
        }
    }

    return 0;
}
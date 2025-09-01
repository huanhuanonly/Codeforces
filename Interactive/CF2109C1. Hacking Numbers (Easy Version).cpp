/**
 * Codeforces Round 1025 (Div. 2)
 * 
 * => C1. Hacking Numbers (Easy Version) ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/2109/problem/C1
 * 
 * Submissions ~> https://codeforces.com/contest/2109/submission/326732307 By huanhuanonly
 * 
 * @b Interactive
 * 
 * ----July 01, 2025 [11h:38m:08s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int64 n;
        std::cin >> n;

        auto query = [](const char* const command, int64 y) -> bool
        {
            std::cout << command << ' ' << y << std::endl;

            int res;
            std::cin >> res;

            return res;
        };

        auto answer = []() -> bool
        {
            std::cout << '!' << std::endl;

            int res;
            std::cin >> res;

            return res != -1;
        };

        auto do_digit = []() -> void
        {
            std::cout << "digit" << std::endl;

            int res;
            std::cin >> res;
        };

        do_digit();
        do_digit();
        
        query("add", -8);
        query("add", -4);
        query("add", -2);
        query("add", -1);

        if (n - 1)
        {
            query("add", n - 1);
        }

        if (not answer())
        {
            return 666;
        }
    }

    return 0;
}
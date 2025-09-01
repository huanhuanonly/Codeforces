/**
 * Codeforces Round 1025 (Div. 2)
 * 
 * => C2. Hacking Numbers (Medium Version) ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/2109/problem/C2
 * 
 * Submissions ~> https://codeforces.com/contest/2109/submission/326736879 By huanhuanonly
 * 
 * @b Interactive
 * 
 * ----July 01, 2025 [12h:24m:06s]----
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

        query("mul", 9);

        do_digit();
        do_digit();

        if (n - 9)
        {
            query("add", n - 9);
        }

        if (not answer())
        {
            return 666;
        }
    }

    return 0;
}
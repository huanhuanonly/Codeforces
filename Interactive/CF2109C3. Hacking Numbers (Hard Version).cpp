/**
 * Codeforces Round 1025 (Div. 2)
 * 
 * => C3. Hacking Numbers (Hard Version) ( @c 2600 )
 * 
 * -> https://codeforces.com/contest/2109/problem/C3
 * 
 * Submissions ~> https://codeforces.com/contest/2109/submission/326751616 By huanhuanonly
 * 
 * @b Interactive
 * 
 * ----July 01, 2025 [15h:19m:55s]----
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

        /**
         * @b i can only be 9, because @b x is at most 10^9.
         * 
         * If @b i is less than 9, say 8, and @b x is 10^9-1, then the calculation will be
         * x*(10^8-1), whose digit sum will be 81 (i.e., 9×9), not the expected 72 (i.e., 9×8).
         * 
         * If @b i is greater than 9, an arithmetic overflow may occur during multiplication.
         */
        constexpr int64 i = 9;

        query("mul", static_cast<int64>(std::pow(10ULL, i)) - 1);

        do_digit();

        if (n - i * 9)
        {
            query("add", n - i * 9);
        }

        if (not answer())
        {
            return 666;
        }
    }

    return 0;
}
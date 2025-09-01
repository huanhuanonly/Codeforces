/**
 * Codeforces Round 1042 (Div. 3)
 * 
 * => E. Adjacent XOR ( @c 1400 )
 * 
 * -> https://codeforces.com/contest/2131/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2131/problem/E By huanhuanonly
 * 
 * @b Bitwise-XOR
 * 
 * ----August 11, 2025 [23h:48m:09s]----
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

        std::vector<int> a(n + 1), b(n + 1);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
        }

        for (int i = 0; i < n; ++i)
        {
            std::cin >> b[i];
        }

        bool yes = true;

        for (int i = 0; i < n; ++i)
        {
            if (not (a[i] == b[i] or b[i] == (a[i] ^ b[i + 1]) or b[i] == (a[i] ^ a[i + 1])))
            {
                yes = false;
                break;
            }
        }

        if (yes)
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}
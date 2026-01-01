/**
 * Codeforces Round 1065 (Div. 3)
 * 
 * => C2. Renako Amaori and XOR Game (hard version) ( @c 1400 )
 * 
 * -> https://codeforces.com/contest/2171/problem/C2
 * 
 * Submissions ~> https://codeforces.com/contest/2171/submission/349914614 By huanhuanonly
 * 
 * @b Game-theory and @b Bitwise-XOR
 * 
 * ----November 20, 2025 [23h:29m:50s]----
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

        std::vector<int> a(n), b(n);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
        }

        for (int i = 0; i < n; ++i)
        {
            std::cin >> b[i];
        }

        bool found = false;

        for (int bit = 22; bit >= 0 and not found; --bit)
        {
            std::array<int, 2> sum{};
            std::array<int, 2> has{-1, -1};

            int eq = 0;

            for (int i = 0; i < n; ++i)
            {
                if ((a[i] & (1 << bit)) == (b[i] & (1 << bit)))
                {
                    sum[0] ^= a[i] & (1 << bit);
                    sum[1] ^= b[i] & (1 << bit);
                }
                else
                {
                    eq ^= 1;
                    has[i & 1] = i;
                }
            }

            if (has[0] > has[1])
            {
                if (eq)
                {
                    found = true;
                    std::cout << "Ajisai\n";
                }
            }
            else if (has[1] > has[0])
            {
                if (eq)
                {
                    found = true;
                    std::cout << "Mai\n";
                }
            }
            else
            {
                if (sum[0] > sum[1])
                {
                    found = true;
                    std::cout << "Ajisai\n";
                }
                else if (sum[0] < sum[1])
                {
                    found = true;
                    std::cout << "Mai\n";
                }
            }
        }

        if (not found)
        {
            std::cout << "Tie\n";
        }
    }

    return 0;
}
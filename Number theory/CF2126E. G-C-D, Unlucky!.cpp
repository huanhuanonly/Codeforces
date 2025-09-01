/**
 * Codeforces Round 1037 (Div. 3)
 * 
 * => E. G-C-D, Unlucky! ( @c 1400 )
 * 
 * -> https://codeforces.com/contest/2126/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2126/submission/329458015 By huanhuanonly
 * 
 * @b Number-theory ( @a greatest-common-divisor )
 * 
 * ----July 17, 2025 [23h:43m:15s]----
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

        std::vector<uint64> p(n), s(n);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> p[i];
        }

        for (int i = 0; i < n; ++i)
        {
            std::cin >> s[i];
        }

        bool yes = (p.back() == s.front());

        for (int i = 0; i < n - 1; ++i)
        {
            if (std::gcd(p[i], p[i + 1]) != p[i + 1])
            {
                yes = false;
                break;
            }
        }

        for (int i = n - 1; i > 0; --i)
        {
            if (std::gcd(s[i - 1], s[i]) != s[i - 1])
            {
                yes = false;
                break;
            }
        }

        std::vector<uint64> v(n);

        for (int i = 0; i < n; ++i)
        {
            v[i] = std::lcm(p[i], s[i]);
        }

        uint64 pre = v.front();

        for (int i = 0; i < n; ++i)
        {
            pre = std::gcd(pre, v[i]);

            if (pre != p[i])
            {
                yes = false;
                break;
            }
        }

        uint64 suf = v.back();

        for (int i = n - 1; i >= 0; --i)
        {
            suf = std::gcd(suf, v[i]);

            if (suf != s[i])
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
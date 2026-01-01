/**
 * Codeforces Global Round 29 (Div. 1 + Div. 2)
 * 
 * => C. Rabbits ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/2147/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2147/submission/349526028 By huanhuanonly
 * 
 * @b Classification-discussion
 * 
 * ----November 18, 2025 [11h:58m:50s]----
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

        std::string s;
        std::cin >> s;

        bool yes = true;

        int l = 0, r = 0;

        for (int i = 1; i < n; ++i)
        {
            if (s[i] != s[i - 1])
            {
                r = i;
            }
            else
            {
                if (std::ranges::count(std::string_view(s).substr(l, r - l + 1), '0') & 1)
                {
                    if (s[l] == '1' and s[r] == '1')
                    {
                        yes = false;
                        break;
                    }
                }

                l = r = i;
            }
        }

        if (std::ranges::count(std::string_view(s).substr(l, r - l + 1), '0') & 1)
        {
            if (s[l] == '1' and s[r] == '1')
            {
                yes = false;
            }
        }

        if (yes and (s == "101" or s.starts_with("1011") or s.ends_with("1101") or s.find("11011") != s.npos))
        {
            yes = false;
        }

        std::cout << (yes ? "YES\n" : "NO\n");
    }

    return 0;
}
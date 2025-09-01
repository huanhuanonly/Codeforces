/**
 * Educational Codeforces Round 179 (Rated for Div. 2)
 * 
 * => E. Changing the String ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/2111/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2111/submission/324657253 By huanhuanonly
 * 
 * @b Classification-discussion
 * 
 * ----June 16, 2025 [22h:17m:26s]----
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

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, q;
        std::cin >> n >> q;

        std::string s;
        std::cin >> s;

        std::set<int> ba, ca, bc, cb;

        for (int i = 0; i < q; ++i)
        {
            char x, y;
            std::cin >> x >> y;

            if (x == 'b' and y == 'a')
            {
                ba.insert(i);
            }
            else if (x == 'c' and y == 'a')
            {
                ca.insert(i);
            }
            else if (x == 'b' and y == 'c')
            {
                bc.insert(i);
            }
            else if (x == 'c' and y == 'b')
            {
                cb.insert(i);
            }
        }

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'b')
            {
                if (not ba.empty())
                {
                    s[i] = 'a';
                    ba.erase(ba.begin());
                }
                else if (not bc.empty() and not ca.empty())
                {
                    if (auto it = ca.upper_bound(*bc.begin()); it != ca.end())
                    {
                        s[i] = 'a';
                        bc.erase(bc.begin());
                        ca.erase(it);
                    }
                }
            }
            else if (s[i] == 'c')
            {
                if (not ca.empty())
                {
                    s[i] = 'a';
                    ca.erase(ca.begin());
                }
                else if (not cb.empty())
                {
                    if (auto it = ba.upper_bound(*cb.begin()); it != ba.end())
                    {
                        s[i] = 'a';
                        cb.erase(cb.begin());
                        ba.erase(it);
                    }
                    else
                    {
                        s[i] = 'b';
                        cb.erase(cb.begin());
                    }
                }
            }
        }

        std::cout << s << '\n';
    }

    return 0;
}
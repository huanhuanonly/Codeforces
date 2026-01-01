/**
 * Codeforces Round 1067 (Div. 2)
 * 
 * => D. Palindrome Flipping ( @c 2000 )
 * 
 * -> https://codeforces.com/contest/2158/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2158/submission/351976132 By huanhuanonly
 * 
 * @b Constructive ( @a Normalization )
 * 
 * ----December 05, 2025 [17h:18m:01s]----
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
        int n;
        std::cin >> n;

        auto normalize = [&](std::string s) -> auto
        {
            std::vector<std::pair<int, int>> st;
            st.reserve(n);

            int l, r, b;

            bool found = false;

            for (int i = 1; i < n; ++i)
            {
                if (s[i - 1] == s[i])
                {
                    found = true;
                    l = i - 1, r = i, b = s[i];
                    break;
                }
            }

            if (found)
            {
                for (; l > 0 and s[l - 1] == b; --l);
                for (; r < n - 1 and s[r + 1] == b; ++r);
            }
            else
            {
                st.emplace_back(0, 2);
                
                s[0] = !(s[0] - '0') + '0';
                s[1] = !(s[1] - '0') + '0';
                s[2] = !(s[2] - '0') + '0';

                l = 2, r = 3, b = s[2];
            }

            while (not (l == 0 and r == n - 1))
            {
                st.emplace_back(l, r);
                b = !(b - '0') + '0';

                for (; l > 0 and s[l - 1] == b; --l);
                for (; r < n - 1 and s[r + 1] == b; ++r);
            }

            if (b == '1')
            {
                st.emplace_back(l, r);
            }

            return st;
        };

        std::string s, t;
        std::cin >> s >> t;

        const auto&& sc = normalize(s);
        const auto&& tc = normalize(t);

        std::cout << sc.size() + tc.size() << '\n';

        for (const auto& [l, r] : sc)
        {
            std::cout << l + 1 << ' ' << r + 1 << '\n';
        }

        for (const auto& [l, r] : tc | std::views::reverse)
        {
            std::cout << l + 1 << ' ' << r + 1 << '\n';
        }
    }

    return 0;
}
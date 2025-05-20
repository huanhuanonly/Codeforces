/**
 * Codeforces Round 1020 (Div. 3)
 * 
 * => F. Goblin ( @c Rating )
 * 
 * -> https://codeforces.com/contest/2106/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/2106/submission/317144279 By huanhuanonly
 * 
 * @b Classification-discussion
 * 
 * ----April 25, 2025 [15h:55m:17s]----
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

#ifdef __localhost
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

        uint64 ans = 0;

        std::list<std::pair<uint64, uint64>> list{{0, 0}};

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '0')
            {
                for (auto& [first, second] : list)
                {
                    first  += n - (i + 1);
                    second += i;
                }
            }
            else
            {
                if (list.size() == 2)
                {
                    ans = std::max(ans, list.front().second);
                    list.pop_front();
                }

                list.front().second = list.front().first + 1;
                list.push_back({0, 0});
            }
        }

        ans = std::max(ans, list.front().second);

        std::cout << ans << '\n';
    }

    return 0;
}
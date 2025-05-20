/**
 * Neowise Labs Contest 1 (Codeforces Round 1018, Div. 1 + Div. 2)
 * 
 * => D. Wonderful Lightbulbs ( @c 2000 )
 * 
 * -> https://codeforces.com/contest/2096/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2096/submission/316917999 By huanhuanonly
 * 
 * @b Classification-discussion
 * 
 * ----April 24, 2025 [14h:26m:43s]----
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

        std::pair<int, int> ans;

        std::map<int, std::set<std::pair<int, int>>> mp;
        
        for (int i = 0; i < n; ++i)
        {
            int x, y;
            std::cin >> x >> y;

            ans.first ^= x;
            mp[x + y].insert({x, y});
        }

        for (const auto& [diff, st] : mp)
        {
            if (st.size() & 1)
            {
                auto [x, y] = *st.begin();

                ans.second = y + (x - ans.first);

                break;
            }
        }

        std::cout << ans.first << ' ' << ans.second << '\n';
    }

    return 0;
}
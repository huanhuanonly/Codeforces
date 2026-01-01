/**
 * Educational Codeforces Round 183 (Rated for Div. 2)
 * 
 * => C. Monocarp's String ( @c 1300 )
 * 
 * -> https://codeforces.com/contest/2145/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2145/submission/342262154 By huanhuanonly
 * 
 * @b Prefix-sum
 * 
 * ----October 07, 2025 [10h:49m:47s]----
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

        std::vector<int> v(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            v[i] = v[i - 1] + (s[i - 1] == 'a' ? 1 : -1);
        }

        std::map<int, int> mp{{0, 0}};

        int ans = n;

        for (int i = 0; i <= n; ++i)
        {
            auto it = mp.find(v[i] - v[n]);

            if (it != mp.end())
            {
                ans = std::min(ans, i - it->second);
            }

            mp[v[i]] = i;
        }

        if (ans == n)
        {
            std::cout << -1 << '\n';
        }
        else
        {
            std::cout << ans << '\n';
        }
    }

    return 0;
}
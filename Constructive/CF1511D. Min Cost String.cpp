/**
 * Educational Codeforces Round 107 (Rated for Div. 2)
 * 
 * => D. Min Cost String ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/1511/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/1511/submission/340319890 By huanhuanonly
 * 
 * @b Constructive
 * 
 * ----September 25, 2025 [16h:38m:26s]----
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

    int n, k;
    std::cin >> n >> k;

    std::string s;
    
    for (char i = 'a'; i < 'a' + k; ++i)
    {
        s.push_back(i);

        for (char j = i + 1; j < 'a' + k; ++j)
        {
            s.push_back(i);
            s.push_back(j);
        }
    }

    std::string ans;

    while (ans.size() < n)
    {
        ans += s;
    }

    for (; ans.size() > n; ans.pop_back());

    std::cout << ans;

    return 0;
}
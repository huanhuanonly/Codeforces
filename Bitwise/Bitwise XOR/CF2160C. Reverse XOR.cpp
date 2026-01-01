/**
 * Codeforces Round 1058 (Div. 2)
 * 
 * => C. Reverse XOR ( @c 1300 )
 * 
 * -> https://codeforces.com/contest/2160/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2160/submission/343337755 By huanhuanonly
 * 
 * @b Bitwise-XOR
 * 
 * ----October 13, 2025 [10h:30m:12s]----
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
        uint32 n;
        std::cin >> n;

        std::string s = std::bitset<32>(n).to_string();

        s.erase(s.begin(), std::ranges::find(s, '1'));
        
        for (; not s.empty() and s.back() == '0'; s.pop_back());

        std::string t = s;
        std::ranges::reverse(t);

        if (s == t and (s.size() % 2 == 0 or s[(s.size() - 1) / 2] == '0'))
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
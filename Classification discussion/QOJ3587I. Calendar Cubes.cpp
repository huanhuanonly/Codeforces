/**
 * The 2026 ICPC China Shenzhen Invitational Contest
 * 
 * => I. Calendar Cubes
 * 
 * -> https://qoj.ac/contest/3587/problem/17761
 * 
 * Submissions ~> https://qoj.ac/submission/2292777 By huanhuanonly
 * 
 * @b Classification-discussion
 * 
 * ----April 28, 2026 [13h:24m:32s]----
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

#if defined(__SIZEOF_INT128__)
using int128 = __int128;
using uint128 = unsigned __int128;
#endif

using real32 = float;
using real64 = double;

#if defined(__SIZEOF_FLOAT80__)
using real80 = __float80;
#endif

#if defined(__SIZEOF_FLOAT128__)
using real128 = __float128;
#endif

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    const std::map<std::string, std::array<int, 12>> ans{
        {"01", {0,0,0,0,0,0,  0,0,0,0,0,0}},
        {"02", {0,0,0,0,0,0,  1,0,0,0,0,0}},
        {"03", {0,0,0,0,0,0,  1,2,0,0,0,0}},
        {"04", {0,0,0,0,0,0,  1,2,3,0,0,0}},
        {"05", {0,0,0,0,0,0,  1,2,3,4,0,0}},
        {"06", {0,0,0,0,0,0,  1,2,3,4,5,0}},
        {"07", {0,0,0,0,0,0,  1,2,3,4,5,6}},
        {"08", {6,7,0,0,0,0,  1,2,3,4,5,0}},
        {"11", {6,7,8,0,0,0,  1,2,3,4,5,0}},
        {"22", {6,7,8,1,0,0,  1,2,3,4,5,0}},
        {"33", {6,7,8,1,2,0,  1,2,3,4,5,0}}
    };

    int _;
    std::cin >> _;

    while (_--)
    {
        std::string s;
        std::cin >> s;

        if (auto it = ans.find(s); it != ans.end())
        {
            std::cout << "Yes\n";

            for (int i : it->second)
            {
                std::cout << i << ' ';
            }

            std::cout.put('\n');
        }
        else
        {
            std::cout << "No\n";
        }
    }

    return 0;
}
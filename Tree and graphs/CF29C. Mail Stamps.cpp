/**
 * Codeforces Beta Round 29 (Div. 2, Codeforces format)
 * 
 * => C. Mail Stamps ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/29/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/29/submission/339254649 By huanhuanonly
 * 
 * @b Graphs
 * 
 * ----September 18, 2025 [20h:19m:03s]----
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

    int n;
    std::cin >> n;

    std::map<int, std::vector<int>> e;

    for (int i = 0; i < n; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    int cpos = std::ranges::find(e, 1, [](const auto& s) -> int { return s.second.size(); })->first;
    int last = 0;

    std::cout << cpos << ' ';
    
    for (;;)
    {
        if (e[cpos][0] != last)
        {
            last = std::exchange(cpos, e[cpos][0]);
        }
        else if (e[cpos].size() > 1 and e[cpos][1] != last)
        {
            last = std::exchange(cpos, e[cpos][1]);
        }
        else
        {
            break;
        }

        std::cout << cpos << ' ';
    }

    return 0;
}
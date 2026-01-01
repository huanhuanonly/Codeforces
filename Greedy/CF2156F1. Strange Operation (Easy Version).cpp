/**
 * Codeforces Round 1061 (Div. 2)
 * 
 * => F1. Strange Operation (Easy Version) ( @c 2200 )
 * 
 * -> https://codeforces.com/contest/2156/problem/F1
 * 
 * Submissions ~> https://codeforces.com/contest/2156/submission/347522054 By huanhuanonly
 * 
 * @b Greedy
 * 
 * ----November 05, 2025 [16h:46m:28s]----
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

        std::vector<int> v(n + 1);
        std::vector<int> pos(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
            pos[v[i]] = i;
        }

        for (int i = 1; i <= n - 2; ++i)
        {
            for (int x = i; x >= 1; --x)
            {
                if (pos[x + 2] < pos[x] and pos[x + 2] < pos[x + 1])
                {
                    std::swap(v[pos[x + 2]], v[pos[x]]);
                    std::swap(pos[x + 2], pos[x]);
    
                    std::swap(v[pos[x + 2]], v[pos[x + 1]]);
                    std::swap(pos[x + 2], pos[x + 1]);
                }
            }
        }
        
        for (int i = 1; i <= n; ++i)
        {
            std::cout << v[i] << " \n"[i == n];
        }
    }

    return 0;
}
/**
 * Codeforces Round 1047 (Div. 3)
 * 
 * => F. Prefix Maximum Invariance ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/2137/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/2137/submission/337973647 By huanhuanonly
 * 
 * @b Jumping-chain
 * 
 * ----September 10, 2025 [23h:40m:40s]----
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

        std::vector<int> a(n + 1), b(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
        }

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> b[i];
        }

        std::vector<int> prev(n + 1);
        {
            std::set<std::pair<int, int>> st;
            
            for (int i = n; i >= 1; --i)
            {
                for (auto it = st.begin(); it != st.end() and it->first <= a[i]; it = st.erase(it))
                {
                    prev[it->second] = i;
                }
                
                st.insert({std::max(a[i], b[i]), i});
            }
        }

        uint64 ans = 0;
        
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == b[i])
            {
                ans += i * uint64(n - i + 1);
            }
            else
            {
                ans += prev[i] * uint64(n - i + 1);
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}
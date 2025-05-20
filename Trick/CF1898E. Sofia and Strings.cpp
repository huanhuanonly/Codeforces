/**
 * Codeforces Round 910 (Div. 2)
 * 
 * => E. Sofia and Strings ( @c 2200 )
 * 
 * -> https://codeforces.com/contest/1898/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/1898/submission/316928478 By huanhuanonly
 * 
 * ----April 24, 2025 [16h:19m:23s]----
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
        int n, m;
        std::cin >> n >> m;
        
        std::string s, t;
        std::cin >> s >> t;

        std::array<std::vector<int>, 26> st;

        for (int i = 0; i < n; ++i)
        {
            st[s[i] - 'a'].push_back(i);
        }

        bool yes = true;

        for (int i = m - 1; i >= 0; --i)
        {
            if (st[t[i] - 'a'].empty())
            {
                yes = false;
                break;
            }

            int pos = st[t[i] - 'a'].back();
            st[t[i] - 'a'].pop_back();

            for (int j = t[i] - 'a' + 1; j < st.size(); ++j)
            {
                while (not st[j].empty() and st[j].back() > pos)
                {
                    st[j].pop_back();
                }
            }
        }

        std::cout << (yes ? "YES\n" : "NO\n");
    }

    return 0;
}
/**
 * Codeforces Round 1032 (Div. 3)
 * 
 * => F. Yamakasi ( @c 1800 )
 * 
 * -> https://codeforces.com/contest/2121/problem/F
 * 
 * Submissions ~> https://codeforces.com/contest/2121/submission/324975281 By huanhuanonly
 * 
 * @b Binary-search
 * 
 * ----June 18, 2025 [12h:21m:28s]----
*/

/// @brief This is an @c interesting problem!

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
        int64 n, s, x;
        std::cin >> n >> s >> x;

        std::vector<int64> v(n + 1);
        std::set<int64, std::greater<int64>> st{0};

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> v[i];

            if (v[i] > x)
            {
                st.insert(i);
            }

            v[i] += v[i - 1];
        }

        std::map<int64, std::vector<int>> mp{{0, {1}}};

        int64 ans = 0;

        int64 last = -1;

        for (int i = 1; i <= n; ++i)
        {
            if (v[i] - v[i - 1] == x)
            {
                last = i;
            }

            if (v[i] - v[i - 1] <= x)
            {
                auto mit = mp.find(v[i] - s);
                auto sit = st.upper_bound(i);
                
                if (mit != mp.end() and sit != st.end())
                {
                    auto it = std::upper_bound(mit->second.begin(), mit->second.end(), *sit);
                    auto jt = std::lower_bound(mit->second.rbegin(), mit->second.rend(), last, std::greater());
                    
                    if (it != mit->second.end() and jt != mit->second.rend())
                    {
                        ans += std::max<int64>(jt.base() - it, 0);
                    }
                }
            }

            mp[v[i]].push_back(i + 1);
        }

        std::cout << ans << '\n';
    }

    return 0;
}
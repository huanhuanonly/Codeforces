/**
 * Codeforces Round 1054 (Div. 3)
 * 
 * => E. Hidden Knowledge of the Ancients ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/2149/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2149/submission/340488993 By huanhuanonly
 * 
 * @b Two-pointers
 * 
 * ----September 26, 2025 [21h:41m:39s]----
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
        int64 n, k, l, r;
        std::cin >> n >> k >> l >> r;

        std::vector<int64> v(n + 1);

        std::map<int64, std::vector<int64>> mp;
        std::map<int64, int64> id;

        for (int64 i = 1; i <= n; ++i)
        {
            std::cin >> v[i];
            mp[v[i]].push_back(i);
        }

        std::set<int64> st{n + 1};

        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            st.insert(it->second.front());
        }

        int64 ans = 0;

        if (k >= st.size())
        {
            std::cout << 0 << '\n';
            continue;
        }

        auto it = st.begin(), jt = std::next(st.begin(), k - 1);

        while (*jt != n + 1)
        {
            int64 len = *jt - *it + 1;
            int64 dif = *std::next(jt) - *jt;

            int64 add = std::min(r + 1, len + dif) - std::max(l, len);
            
            if (add > 0)
            {
                ans += add;
            }

            int64 nid = ++id[v[*it]];

            if (nid >= mp[v[*it]].size())
            {
                ++it, ++jt;
            }
            else
            {
                int64 pos = mp[v[*it]][nid];
                
                st.insert(pos);

                if (pos > *jt)
                {
                    ++it, ++jt;
                }
                else
                {
                    ++it;
                }
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}
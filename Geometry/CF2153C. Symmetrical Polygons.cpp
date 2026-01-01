/**
 * Codeforces Round 1057 (Div. 2)
 * 
 * => C. Symmetrical Polygons ( @c 1500 )
 * 
 * -> https://codeforces.com/contest/2153/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/2153/submission/342975715 By huanhuanonly
 * 
 * @b Geometry
 * 
 * ----October 11, 2025 [10h:44m:51s]----
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

        std::map<uint64, uint64> mp;

        for (int i = 0, v; i < n; ++i)
        {
            std::cin >> v;
            ++mp[v];
        }

        uint64 sum = 0;
        uint64 cnt = 0;

        std::vector<int> v;
        v.reserve(n);

        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            if (it->second & 1)
            {
                sum += it->first * (it->second - 1);
                cnt += it->second - 1;
                v.push_back(it->first);
            }
            else
            {
                sum += it->first * it->second;
                cnt += it->second;
            }
        }

        uint64 ans = sum;
        uint64 mct = cnt;

        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i] < sum)
            {
                ans = std::max(ans, sum + v[i]);
                mct = std::max(mct, cnt + 1);
            }

            if (i and v[i] < sum + v[i - 1])
            {
                ans = std::max(ans, sum + v[i - 1] + v[i]);
                mct = std::max(mct, cnt + 2);
            }
        }

        if (mct < 3)
        {
            std::cout << 0 << '\n';
        }
        else
        {
            std::cout << ans << '\n';
        }
    }

    return 0;
}
/**
 * Cloudflare纪念赛
 * 
 * => I-可删去01字符串2
 * 
 * -> https://ac.nowcoder.com/acm/contest/123509/I
 * 
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=80616156 By huanhuanonly
 * 
 * @b Integer-bit-packing
 * 
 * ----November 19, 2025 [11h:37m:42s]----
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

    std::string s;

    std::map<uint64, int> mp;
    
    for (int i = 0; i < n; ++i)
    {
        std::cin >> s;

        const uint64 cnt = std::ranges::count(s, '0');
        ++mp[cnt << 32 | s.size() - cnt];
    }

    int cnt = 0;

    for (auto itc = mp.begin(); itc != mp.end(); ++itc)
    {
        for (auto ita = mp.begin(); ita != itc; ++ita)
        {
            if (ita->first * 2 == itc->first)
            {
                if (ita->second >= 2)
                {
                    cnt += itc->second;
                    break;
                }
            }
            else if (mp.find(itc->first - ita->first) != mp.end())
            {
                cnt += itc->second;
                break;
            }
        }
    }

    std::cout << cnt;

    return 0;
}
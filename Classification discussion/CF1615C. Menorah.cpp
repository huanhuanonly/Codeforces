/**
 * Codeforces Global Round 18
 * 
 * => C. Menorah ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/1615/problem/C
 * 
 * Submissions ~> https://codeforces.com/contest/1615/submission/340364089 By huanhuanonly
 * 
 * @b Classification-discussion
 * 
 * ----September 25, 2025 [21h:50m:14s]----
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

        std::string s, t;
        std::cin >> s >> t;

        // 0 1 0 1
        // 0 0 1 1
        std::array<int, 4> cnt{};

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '0' and t[i] == '0')
            {
                ++cnt[0];
            }
            else if (s[i] == '1' and t[i] == '0')
            {
                ++cnt[1];
            }
            else if (s[i] == '0' and t[i] == '1')
            {
                ++cnt[2];
            }
            else
            {
                ++cnt[3];
            }
        }

        std::vector<int> ans;

        if (cnt[1] == cnt[2])
        {
            ans.push_back(cnt[1] + cnt[2]);
        }

        if (cnt[3])
        {
            --cnt[3];
            std::swap(cnt[0], cnt[1]);
            std::swap(cnt[2], cnt[3]);
            ++cnt[3];

            if (cnt[1] == cnt[2])
            {
                ans.push_back(1 + cnt[1] + cnt[2]);
            }
        }

        if (ans.empty())
        {
            std::cout << -1 << '\n';
        }
        else
        {
            std::cout << *std::ranges::min_element(ans) << '\n';
        }
    }

    return 0;
}
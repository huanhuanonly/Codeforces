/**
 * Neowise Labs Contest 1 (Codeforces Round 1018, Div. 1 + Div. 2)
 * 
 * => E. Wonderful Teddy Bears ( @c 2400 )
 * 
 * -> https://codeforces.com/contest/2096/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2096/submission/319066602 By huanhuanonly
 * 
 * @b Classification-discussion
 * 
 * ----May 10, 2025 [21h:43m:26s]----
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
        int n;
        std::cin >> n;

        std::string s;
        std::cin >> s;

        std::list<int> v;

        for (auto i = s.find_first_of('P'); i < n; ++i)
        {
            if (i and s[i] == s[i - 1])
            {
                ++v.back();
            }
            else
            {
                v.push_back(1);
            }
        }

        if (v.size() & 1)
        {
            v.pop_back();
        }
        
        uint64 pre = 0, suf = 0;
        
        for (auto it = v.begin(); it != v.end(); ++it)
        {
            suf += *++it;
        }

        uint64 ans = 0;

        for (auto [it, i] = std::tuple(v.begin(), 0); it != v.end(); )
        {
            if (*it & 1)
            {
                // B
                if (i & 1)
                {
                    ans += *it / 2 * pre;
                    suf -= *it;
                }
                // P
                else
                {
                    ans += *it / 2 * suf;
                    ++pre;
                }

                *it = 1;

                ++it, ++i;
            }
            else
            {
                // B
                if (i & 1)
                {
                    ans += *it / 2 * pre;
                    suf -= *it;
                }
                // P
                else
                {
                    ans += *it / 2 * suf;
                }

                if (it = v.erase(it); it != v.begin() and it != v.end())
                {
                    int value = *it;
                    it = v.erase(it);

                    if (i & 1)
                        --pre;
                    else
                        ++suf;

                    --it, --i;

                    *it += value;
                }
                else if (it == v.begin() and it != v.end())
                {
                    suf -= *it;
                    it = v.erase(it);
                }
            }
        }

        if (v.size() & 1)
        {
            v.pop_back();
        }

        for (auto [it, cnt] = std::tuple(v.begin(), 0); it != v.end(); ++it, ++it)
        {
            ans += ((*it + cnt) * *std::next(it) + 1) / 2;

            cnt += *it;
        }

        std::cout << ans << '\n';
    }

    return 0;
}
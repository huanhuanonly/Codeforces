/**
 * CCPC2026黑龙江省大学生程序设计竞赛
 *
 * => B. 最大数码 2
 *
 * -> https://codeforces.com/gym/106534/problem/B
 *
 * Submissions ~> https://codeforces.com/gym/106534/submission/375358092 By huanhuanonly
 *
 * @b Classification-discussion
 *
 * ----May 20, 2026 [21h:49m:56s]----
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

#if defined(__SIZEOF_INT128__)
using int128 = __int128;
using uint128 = unsigned __int128;
#endif

using real32 = float;
using real64 = double;

#if defined(__SIZEOF_FLOAT80__)
using real80 = __float80;
#endif

#if defined(__SIZEOF_FLOAT128__)
using real128 = __float128;
#endif

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int _;
    std::cin >> _;

    while (_--)
    {
        int l, r;
        std::cin >> l >> r;

        auto sl = std::to_string(l);
        auto sr = std::to_string(r);

        int md = 9;

        if (sl.size() == sr.size())
        {
            if (std::string_view(sl.c_str(), sl.size() - 1) == std::string_view(sr.c_str(), sr.size() - 1))
            {
                md = std::max(std::ranges::max(sl), std::ranges::max(sr)) - '0';

                if (sl.find(md + '0') != sl.npos)
                {
                    std::cout << md << ' ' << sl << '\n';
                }
                else
                {
                    std::cout << md << ' ' << sr << '\n';
                }
            }
            else
            {
                std::string s = sl;
                md = 0;

                for (int i = 0; i < sl.size() - 1; ++i)
                {
                    md = std::max(md, sl[i] - '0');
                }

                if (md != 9)
                {
                    s.back() = '9';
                }

                std::cout << "9 " << s << '\n';
            }
        }
        else
        {
            std::string s("1");

            s.append(std::string(sr.size() - 1, '0'));
            s.back() = '9';

            if (s > sr)
            {
                if (sr.size() - sl.size() > 1)
                {
                    s.erase(1, 1);
                    std::cout << "9 " << s << '\n';
                }
                else
                {
                    if (sl.find('9') == sl.npos)
                    {
                        sl.back() = '9';
                    }

                    std::cout << "9 " << sl << '\n';
                }
            }
            else
            {
                std::cout << "9 " << s << '\n';
            }
        }
    }

    return 0;
}
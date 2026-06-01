/**
 * 牛客周赛 Round 145
 *
 * => D-小红的排列构造 ( @c 1200 )
 *
 * -> https://ac.nowcoder.com/acm/contest/134981/D
 *
 * Submissions ~> https://ac.nowcoder.com/acm/contest/view-submission?submissionId=83709773 By huanhuanonly
 *
 * @b Constructive
 *
 * ----May 27, 2026 [19h:58m:07s]----
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

    int n;
    std::cin >> n;

    std::vector<int> a(n);

    std::map<int, std::vector<int>> pos;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        pos[a[i]].push_back(i);
    }

    std::vector<int> b(n), c(n);

    const auto iota = std::views::iota(1, n + 1);
    std::set setb(iota.begin(), iota.end());
    std::set setc(iota.begin(), iota.end());

    bool yes = true;

    for (const auto& [key, value] : pos)
    {
        if (value.size() > 2)
        {
            yes = false;
            break;
        }

        if (value.size() == 2)
        {
            b[value.front()] = c[value.back()] = key;

            setb.erase(key);
            setc.erase(key);
        }
        else if (setb.size() > setc.size())
        {
            b[value.front()] = key;
            setb.erase(key);
        }
        else
        {
            c[value.front()] = key;
            setc.erase(key);
        }
    }

    if (not yes)
    {
        std::cout << "-1\n";
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            if (b[i] == 0)
            {
                if (a[i] != *setb.begin())
                {
                    b[i] = *setb.begin();
                    setb.erase(setb.begin());
                }
                else
                {
                    b[i] = *setb.rbegin();
                    setb.erase(std::prev(setb.end()));
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (c[i] == 0)
            {
                if (a[i] != *setc.begin())
                {
                    c[i] = *setc.begin();
                    setc.erase(setc.begin());
                }
                else
                {
                    c[i] = *setc.rbegin();
                    setc.erase(std::prev(setc.end()));
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            std::cout << b[i] << " \n"[i + 1 == n];
        }

        for (int i = 0; i < n; ++i)
        {
            std::cout << c[i] << " \n"[i + 1 == n];
        }
    }

    return 0;
}
/**
 * Codeforces Round 733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))
 * 
 * => E. Minimax ( @c 2100 )
 * 
 * -> https://codeforces.com/contest/1530/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/1530/submission/328356332 By huanhuanonly
 * 
 * @b Classification-discussion
 * 
 * ----July 10, 2025 [17h:44m:42s]----
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
        std::string s;
        std::cin >> s;

        std::ranges::sort(s);

        std::array<int, 26> cnt{};

        for (const char c : s)
        {
            ++cnt[c - 'a'];
        }

        if (auto fit = std::ranges::find(cnt, 1); fit != cnt.end())
        {
            char c = 'a' + (fit - cnt.begin());
            s.erase(s.find(c), 1);
            
            std::cout << c << s << '\n';
        }
        else if (s[0] != s[1])
        {
            std::cout << s << '\n';
        }
        else if (s.front() == s.back())
        {
            std::cout << s << '\n';
        }
        else
        {
            std::array<std::multiset<char>, 2> mst;

            for (const char c : s)
            {
                mst[c != s[0]].insert(c);
            }

            if (static_cast<int>(mst[0].size()) - 2 <= static_cast<int>(mst[1].size()))
            {
                std::cout << mst[0].extract(mst[0].begin()).value();
                std::cout << mst[0].extract(mst[0].begin()).value();

                for (int i = 1; not mst[0].empty() and not mst[1].empty(); i = not i)
                {
                    std::cout << mst[i].extract(mst[i].begin()).value();
                }

                while (not mst[0].empty())
                {
                    std::cout << mst[0].extract(mst[0].begin()).value();
                }

                while (not mst[1].empty())
                {
                    std::cout << mst[1].extract(mst[1].begin()).value();
                }

                std::cout.put('\n');
            }
            else
            {
                std::cout << mst[0].extract(mst[0].begin()).value();

                char c = mst[1].extract(mst[1].begin()).value();
                std::cout << c;
                
                if (not mst[1].empty() and *mst[1].begin() == c and *mst[1].rbegin() == c)
                {
                    while (not mst[1].empty())
                    {
                        std::cout << mst[1].extract(mst[1].begin()).value();
                    }
                }

                while (not mst[0].empty())
                {
                    std::cout << mst[0].extract(mst[0].begin()).value();
                }
                
                if (not mst[1].empty() and *mst[1].begin() == c and *mst[1].rbegin() != c)
                {
                    std::cout << mst[1].extract(mst[1].upper_bound(c)).value();
                }

                while (not mst[1].empty())
                {
                    std::cout << mst[1].extract(mst[1].begin()).value();
                }

                std::cout.put('\n');
            }
        }
    }

    return 0;
}
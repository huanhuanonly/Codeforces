/**
 * Codeforces Round 1051 (Div. 2)
 * 
 * => E. Make Good ( @c 2400 )
 * 
 * -> https://codeforces.com/contest/2143/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2143/submission/341010907 By huanhuanonly
 * 
 * @b Constructive ( @a Normalization )
 * 
 * ----September 29, 2025 [14h:15m:43s]----
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

        std::string s;
        std::cin >> s;

        if (n & 1)
        {
            std::cout << -1 << '\n';
        }
        else
        {
            for (int i = 1; i < n; ++i)
            {
                if (s[i - 1] == ')' and s[i] == ')')
                {
                    s[i - 1] = s[i] = '(';
                }
            }

            std::list<int> pos;

            for (int i = 0; i < n; ++i)
            {
                if (s[i] == ')')
                {
                    pos.push_front(i);
                }
            }

            for (auto it = pos.begin(); it != pos.end(); )
            {
                if (it == pos.begin())
                {
                    const int x = (n - *it + 1) / 2 - 1;
 
                    std::swap(s[*it], s[*it + 2 * x]);
                    *it += 2 * x;
 
                    ++it;
                }
                else
                {
                    auto prev = std::prev(it);
 
                    const int x = (*prev - *it + 1) / 2 - 1;
 
                    if (*it + 1 == *prev)
                    {
                        s[*prev] = s[*it] = '(';
 
                        pos.erase(prev);
                        ++it;
                        pos.erase(std::prev(it));
                    }
                    else
                    {
                        std::swap(s[*it], s[*it + 2 * x]);
                        *it += 2 * x;
 
                        ++it;
                    }
                }
            }

            pos.reverse();

            for (auto it = pos.begin(); it != pos.end(); )
            {
                if (it == pos.begin())
                {
                    const int x = (*it + 1) / 2 - 1;

                    std::swap(s[*it], s[*it - 2 * x]);
                    *it -= 2 * x;

                    ++it;
                }
                else
                {
                    auto prev = std::prev(it);

                    const int x = (*it - *prev + 1) / 2 - 1;

                    if (*it - 2 * x == *prev + 1)
                    {
                        s[*prev] = s[*it] = '(';

                        pos.erase(prev);
                        ++it;
                        pos.erase(std::prev(it));
                    }
                    else
                    {
                        std::swap(s[*it], s[*it - 2 * x]);
                        *it -= 2 * x;

                        ++it;
                    }
                }
            }

            int cnt = 0;

            for (int i = 0; i < n; ++i)
            {
                if (s[i] == '(')
                {
                    if (cnt >= 2 and i + 1 < n and s[i + 1] == '(')
                    {
                        s[i] = s[i + 1] = ')';
                        --cnt;
                    }
                    else
                    {
                        ++cnt;
                    }
                }
                else
                {
                    if (--cnt < 0)
                    {
                        break;
                    }
                }
            }

            if (cnt == 0)
            {
                std::cout << s << '\n';
            }
            else
            {
                std::cout << -1 << '\n';
            }
        }
    }

    return 0;
}
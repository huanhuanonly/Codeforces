/**
 * => P12135 [蓝桥杯 2025 省 B] 水质检测 ( @c 普及/提高− )
 * 
 * -> https://www.luogu.com.cn/problem/P12135
 * 
 * Submissions ~> https://www.luogu.com.cn/record/213643413 By huanhuanonly
 * 
 * @b Classification-discussion
 * 
 * ----April 13, 2025 [21h:26m:42s]----
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

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    std::string a, b;
    std::cin >> a >> b;

    std::string_view va(a), vb(b);

    while (not va.empty() and va.front() == '.' and vb.front() == '.')
    {
        va.remove_prefix(1);
        vb.remove_prefix(1);
    }

    while (not va.empty() and va.back() == '.' and vb.back() == '.')
    {
        va.remove_suffix(1);
        vb.remove_suffix(1);
    }

    enum POS { Up, Down, All };

    std::queue<POS> que;

    for (int i = 1; i < va.size(); ++i)
    {
        if (va[i] == '#' and vb[i] == '#')
        {
            que.push(All);
        }
        else if (va[i] == '#')
        {
            que.push(Up);
        }
        else if (vb[i] == '#')
        {
            que.push(Down);
        }
    }

    int cnt = 0;

    for (int i = 1; i < va.size(); ++i)
    {
        if (va[i] == '#' and vb[i] == '#')
        {
            que.pop();
        }
        else if (va[i] == '#' and va[i - 1] == '#')
        {
            que.pop();
        }
        else if (vb[i] == '#' and vb[i - 1] == '#')
        {
            que.pop();
        }
        else if (va[i] == '#')
        {
            que.pop();
            const_cast<char&>(vb[i]) = '#';
            ++cnt;
        }
        else if (vb[i] == '#')
        {
            que.pop();
            const_cast<char&>(va[i]) = '#';
            ++cnt;
        }
        else // if (va[i] == '.' and vb[i] == '.')
        {
            if (va[i - 1] == '#' and vb[i - 1] == '#')
            {
                if (que.front() == Up)
                {
                    const_cast<char&>(va[i]) = '#';
                }
                else
                {
                    const_cast<char&>(vb[i]) = '#';
                }
            }
            else if (va[i - 1] == '#')
            {
                const_cast<char&>(va[i]) = '#';
            }
            else
            {
                const_cast<char&>(vb[i]) = '#';
            }

            ++cnt;
        }
    }

    std::cout << cnt;

    return 0;
}
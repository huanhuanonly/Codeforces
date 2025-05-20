/**
 * 第十三届重庆市大学生程序设计竞赛
 * 
 * => H. 连接
 * 
 * -> https://codeforces.com/gym/105887/problem/H
 * 
 * Submissions ~> https://codeforces.com/gym/105887/submission/319758138 By huanhuanonly
 * 
 * @b Classification-discussion
 * 
 * ----May 16, 2025 [14h:49m:41s]----
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

        std::vector<int> a(n), b(n), pos(n + 1);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
        }

        for (int i = 0; i < n; ++i)
        {
            std::cin >> b[i];
            pos[b[i]] = i;
        }

        std::vector<bool> c(n);

        for (int i = 0, v; i < n; ++i)
        {
            std::cin >> v;
            c[i] = v;
        }

        std::set<int> st;

        int mx = 0;
        bool yes = true;

        for (int i = 0; i < n; ++i)
        {
            if (pos[a[i]] < mx and c[i] and st.upper_bound(pos[a[i]]) != st.end())
            {
                yes = false;
                break;
            }

            if (c[i])
            {
                st.insert(pos[a[i]]);
            }

            mx = std::max(mx, pos[a[i]]);
        }

        if (yes)
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
    }

    return 0;
}
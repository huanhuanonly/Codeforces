/**
 * AtCoder Beginner Contest 419
 * 
 * => D - Substr Swap ( @c 400 )
 * 
 * -> https://atcoder.jp/contests/abc419/tasks/abc419_d
 * 
 * Submissions ~> https://atcoder.jp/contests/abc419/submissions/68551971 By huanhuanonly
 * 
 * @b Difference-array
 * 
 * ----August 16, 2025 [21h:47m:37s]----
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

    int n, m;
    std::cin >> n >> m;

    std::string s, t;
    std::cin >> s >> t;

    std::vector<bool> v(n + 2);

    for (int i = 0; i < m; ++i)
    {
        int l, r;
        std::cin >> l >> r;

        v[l] = not v[l];
        v[r + 1] = not v[r + 1];
    }

    bool cur = false;

    for (int i = 0; i < n; ++i)
    {
        if (v[i + 1])
        {
            cur = not cur;
        }

        if (cur)
        {
            std::cout << t[i];
        }
        else
        {
            std::cout << s[i];
        }
    }

    return 0;
}
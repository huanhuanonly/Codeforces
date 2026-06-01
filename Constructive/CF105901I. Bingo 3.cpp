/**
 * 2025 ICPC Wuhan Invitational Contest (The 3rd Universal Cup. Stage 37: Wuhan)
 * 
 * => I. Bingo 3
 * 
 * -> https://codeforces.com/gym/105901/problem/I
 * 
 * Submissions ~> https://codeforces.com/gym/105901/submission/369121275 By huanhuanonly
 * 
 * @b Constructive
 * 
 * ----April 01, 2026 [22h:25m:59s]----
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
        int n, k;
        std::cin >> n >> k;

        if (n * n - k + 1 >= n and k >= n)
        {
            std::cout << "Yes\n";

            std::vector<bool> vis(n * n + 1);

            std::vector v(n, std::vector(n, 0));

            v[0][0] = k;
            vis[k] = true;

            for (int i = 1; i < n; ++i)
            {
                v[0][i] = i;
                vis[i] = true;
            }

            for (int i = 1; i < n; ++i)
            {
                v[i][i] = n * n - i + 1;
                vis[n * n - i + 1] = true;
            }

            int pos = 1;

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (not v[i][j])
                    {
                        for (; vis[pos]; ++pos);
                        v[i][j] = pos++;
                    }
                }
            }

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    std::cout << v[i][j] << " \n"[j + 1 == n];
                }
            }
        }
        else
        {
            std::cout << "No\n";
        }
    }

    return 0;
}
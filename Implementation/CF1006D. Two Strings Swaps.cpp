/**
 * Codeforces Round 498 (Div. 3)
 * 
 * => D. Two Strings Swaps ( @c 1700 )
 * 
 * -> https://codeforces.com/contest/1006/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/1006/submission/347430362 By huanhuanonly
 * 
 * @b Implementation
 * 
 * ----November 04, 2025 [23h:46m:22s]----
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

    int n;
    std::cin >> n;

    std::string a, b;
    std::cin >> a >> b;

    static auto check = [](char a, char b, char c, char d) -> bool
    {
        if (a == b and c == d)
        {
            return true;
        }
        else if (a == c and b == d)
        {
            return true;
        }
        else if (a == d and b == c)
        {
            return true;
        }
        else
        {
            return false;
        }
    };

    int cnt = 0;

    for (int i = 0; i < n / 2; ++i)
    {
        if (check(a[i], b[i], a[n - i - 1], b[n - i - 1]))
        {
            cnt += 0;
        }
        else if (check(b[i], b[i], a[n - i - 1], b[n - i - 1]))
        {
            cnt += 1;
        }
        else if (check(a[i], b[i], b[n - i - 1], b[n - i - 1]))
        {
            cnt += 1;
        }
        else if (check(b[n - i - 1], b[i], a[n - i - 1], b[n - i - 1]))
        {
            cnt += 1;
        }
        else if (check(a[i], b[i], b[i], b[n - i - 1]))
        {
            cnt += 1;
        }
        else if (check(a[n - i - 1], b[i], a[n - i - 1], b[n - i - 1]))
        {
            cnt += 1;
        }
        else if (check(a[i], b[i], a[i], b[n - i - 1]))
        {
            cnt += 1;
        }
        else
        {
            cnt += 2;
        }
    }

    if ((n & 1) and a[n / 2] != b[n / 2])
    {
        ++cnt;
    }

    std::cout << cnt;

    return 0;
}
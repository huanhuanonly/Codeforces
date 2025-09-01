/**
 * Codeforces Beta Round 94 (Div. 1 Only)
 * 
 * => D. Numbers ( @c 2000 )
 * 
 * -> https://codeforces.com/contest/128/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/128/submission/328883769 By huanhuanonly
 * 
 * @b Constructive
 * 
 * ----July 14, 2025 [18h:07m:10s]----
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

    std::map<int, int> cnt;

    for (int i = 0, v; i < n; ++i)
    {
        std::cin >> v;
        ++cnt[v];
    }

    auto take = [&]() -> bool
    {
        auto fit = cnt.begin(), sit = std::next(cnt.begin());

        if (sit->first - fit->first != 1)
        {
            return false;
        }

        int min = std::min(fit->second, sit->second);

        if ((fit->second -= min) == 0)
        {
            cnt.erase(fit);
        }

        if ((sit->second -= min) == 0)
        {
            cnt.erase(sit);
        }

        return not cnt.empty();
    };

    bool yes = true;

    for (auto [i, it] = std::tuple(cnt.begin()->first, cnt.begin()); it != cnt.end(); ++i, ++it)
    {
        if (it->first != i or (it->second == 1 and it != cnt.begin() and it != std::prev(cnt.end())))
        {
            yes = false;
            break;
        }
    }

    for (auto it = std::next(cnt.begin()), end = std::prev(cnt.end()); it != end; )
    {
        if ((it->second -= 2) == 0)
        {
            it = cnt.erase(it);
        }
        else
        {
            ++it;
        }
    }

    if (auto it = cnt.begin(); --it->second == 0)
    {
        cnt.erase(it);
    }

    if (auto it = cnt.end(); --(--it)->second == 0)
    {
        cnt.erase(it);
    }

    if (yes and not cnt.empty()) while (take());

    if (yes and cnt.empty())
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }

    return 0;
}
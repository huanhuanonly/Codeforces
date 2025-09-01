/**
 * Codeforces Beta Round 94 (Div. 1 Only)
 * 
 * => B. String ( @c 2100 )
 * 
 * -> https://codeforces.com/contest/128/problem/B
 * 
 * Submissions ~> https://codeforces.com/contest/128/submission/329312732 By huanhuanonly
 * 
 * @b Greedy
 * 
 * ----July 17, 2025 [17h:32m:10s]----
*/

/// @brief This is an @c interesting problem!

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

    std::string s;
    std::cin >> s;

    int k;
    std::cin >> k;

    std::priority_queue<std::string_view, std::vector<std::string_view>, std::ranges::greater> que;

    for (auto it = s.begin(); it != s.end(); ++it)
    {
        que.emplace(it, it + 1);
    }

    for (; k > 1 and not que.empty(); --k)
    {
        auto cur = que.top();
        que.pop();

        if (cur.end() != s.end().base())
        {
            que.emplace(cur.begin(), cur.end() + 1);
        }
    }

    if (k == 1 and not que.empty())
    {
        std::cout << que.top();
    }
    else
    {
        std::cout << "No such line.";
    }

    return 0;
}
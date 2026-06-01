/**
 * Codeforces Round 1089 (Div. 2)
 *
 * => D. A Simple RBS Problem ( @c 2100 )
 *
 * -> https://codeforces.com/contest/2210/problem/D
 *
 * Submissions ~> https://codeforces.com/contest/2210/submission/368858218 By huanhuanonly
 *
 * @b Constructive ( @a Normalization )
 * @b Bracket-tree
 *
 * ----March 30, 2026 [22h:20m:11s]----
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

std::pair<int, int> calc(const std::string& str)
{
    std::string_view s(str);
    std::vector<int> rp(s.size(), -1);

    std::stack<int> stack;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            stack.push(i);
        }
        else
        {
            rp[stack.top()] = i - stack.top() + 1;
            stack.pop();
        }
    }

    std::pair<int, int> ret;

    for (int i = 0; i < rp.size() and rp[i] == s.size(); ++i, s.remove_prefix(1), s.remove_suffix(1), ++ret.first);

    for (int i = s.find("()"); i != s.npos; i = s.find("()", i + 1), ++ret.second);

    return ret;
}

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
        int n;
        std::cin >> n;

        std::string s, t;
        std::cin >> s >> t;

        if (calc(s) == calc(t))
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}
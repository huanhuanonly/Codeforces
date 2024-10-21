/**
 * Codeforces Beta Round 93 (Div. 1 Only)
 * 
 * => B. Password
 * 
 * -> https://codeforces.com/problemset/problem/126/B (1700)
 * 
 * @b Hashing + BinarySearch
*/

#include <bits/stdc++.h>

using uint = unsigned int;
using llong = long long int;
using ullong = unsigned long long int;
using ldouble = long double;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
    ::freopen("Input.txt", "r", stdin);
    ::freopen("Output.txt", "w", stdout);
#endif

    std::string s;
    std::cin >> s;

    constexpr int P = 131;

    std::vector<ullong> p(s.size() + 1, 1);
    std::vector<ullong> h(s.size() + 1);

    for (int i = 1; i <= s.size(); ++i)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + s[i - 1];
    }

    auto get_hash = [&](int l, int r) -> ullong
    {
        return h[r] - h[l - 1] * p[r - l + 1];
    };

    auto check = [&](int mid) -> bool
    {
        for (int i = 2; i <= int(s.size()) - mid; ++i)
        {
            if (get_hash(1, mid) == get_hash(i, i + mid - 1))
            {
                return true;
            }
        }

        return false;
    };

    std::vector<int> v;
    
    for (int i = 1; i < s.size(); ++i)
    {
        if (get_hash(1, i) == get_hash(s.size() - i + 1, s.size()))
        {
            v.push_back(i);
        }
    }

    int l = 1, r = int(v.size()) + 1, mid;

    while (r - l > 1)
    {
        mid = l + r >> 1;

        if (check(v[mid - 1]))
            l = mid;
        else
            r = mid;
    }

    if (v.size() and check(v[l - 1]))
        std::cout << std::string_view(s.c_str(), v[l - 1]);
    else
        std::cout << "Just a legend";

    return 0;
}
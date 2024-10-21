/**
 * => P3805 【模板】manacher
 * 
 * -> https://www.luogu.com.cn/problem/P3805
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

    constexpr const int P = 131;

    std::vector<ullong> p(s.size() + 1, 1);

    std::vector<ullong> h(s.size() + 1), rh(s.size() + 1);

    for (int i = 1; i <= s.size(); ++i)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + s[i - 1];
        rh[i] = rh[i - 1] * P + s[s.size() - i];
    }

    auto get_hash = [&](int l, int r) -> ullong
    {
        return h[r] - h[l - 1] * p[r - l + 1];
    };

    auto get_rhash = [&](int l, int r) -> ullong
    {
        return rh[r] - rh[l - 1] * p[r - l + 1];
    };

    auto check = [&](int mid) -> bool
    {
        for (int i = 1; i + mid - 1 <= s.size(); ++i)
        {
            if (get_hash(i, i + mid - 1) == get_rhash(s.size() - i + 1 - mid + 1, s.size() - i + 1))
                return true;
        }

        return false;
    };
    
    int ans = 1;

    // Odd number

    int l = 1, r = s.size() + 1, mid;

    while (r - l > 1)
    {
        mid = l + r >> 1;

        if (check(mid * 2 - 1))
            l = mid;
        else
            r = mid;
    }

    ans = std::max(ans, l * 2 - 1);

    // Even number

    l = 2, r = s.size() + 1;

    while (r - l > 1)
    {
        mid = l + r >> 1;

        if (check(mid * 2 - 2))
            l = mid;
        else
            r = mid;
    }

    ans = std::max(ans, l * 2 - 2);

    std::cout << ans;

    return 0;
}
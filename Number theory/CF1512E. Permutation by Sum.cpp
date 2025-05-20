/**
 * Codeforces Round 713 (Div. 3)
 * 
 * => E. Permutation by Sum ( @c 1600 )
 * 
 * -> https://codeforces.com/contest/1512/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/1512/submission/315927282 By huanhuanonly
 * 
 * @b Number-theory
 * 
 * ----April 17, 2025 [16h:14m:11s]----
*/

/**
 * If we choose $k$ numbers from a permutation of length $n$, then the minimum sum of $k$ numbers
 * is $\frac{k(k+1)}{2}$,  the maximum sum is $\frac{k(2n+1-k)}{2}$  and any sum between them  is
 * achievable (that is, you can choose exactly $k$ numbers from $n$ so that their sum is equal to
 * the desired one).
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, l, r, s;
        std::cin >> n >> l >> r >> s;

        auto check = [](int n, int m, int sum) -> bool
        {
            static auto get = [](int len) -> int
            {
                return len * (len + 1) / 2;
            };

            return sum >= get(m) and sum <= get(n) - get(n - m);
        };

        if (not check(n, r - l + 1, s))
        {
            std::cout << -1 << '\n';
            continue;
        }

        std::vector<int> log;
        log.reserve(r - l + 1);

        std::set<int> st;

        for (const auto& i : std::views::iota(1, n + 1))
        {
            st.insert(i);
        }

        for (int i = n; i >= 1; --i)
        {
            if (check(n - 1, r - l + 1 - log.size() - 1, s - i))
            {
                s -= i;
                log.push_back(i);
                st.erase(i);
            }
        }

        for (auto [i, it] = std::make_tuple(0, st.begin()); i < st.size(); ++i, ++it)
        {
            if (i == l - 1)
            {
                for (const auto& j : log)
                {
                    std::cout << j << ' ';
                }

                log.clear();
            }
            
            std::cout << *it << ' ';
        }

        for (const auto& j : log)
        {
            std::cout << j << ' ';
        }

        std::cout.put('\n');
    }

    return 0;
}
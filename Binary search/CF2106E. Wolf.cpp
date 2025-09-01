/**
 * Codeforces Round 1020 (Div. 3)
 * 
 * => E. Wolf ( @c 1800 )
 * 
 * -> https://codeforces.com/contest/2106/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/2106/submission/317136077 By huanhuanonly
 * 
 * @b Binary-search-simulation
 * 
 * ----April 25, 2025 [14h:29m:57s]----
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
        int n, q;
        std::cin >> n >> q;

        std::vector<int> p(n + 1);

        std::vector<int> mp(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> p[i];
            mp[p[i]] = i;
        }

        while (q--)
        {
            int l, r, k;
            std::cin >> l >> r >> k;
            
            std::pair<int, int> global_cnt{k - 1, n - k};

            int pos = mp[k];

            if (not (pos >= l and pos <= r))
            {
                std::cout << -1 << ' ';
                continue;
            }

            std::pair<int, int> cnt;

            while (true)
            {
                int mid = l + r >> 1;

                if (pos < mid)
                {
                    if (not (p[mid] > k))
                    {
                        ++cnt.second;
                    }
                    else
                    {
                        --global_cnt.second;
                    }

                    r = mid - 1;
                }
                else if (pos > mid)
                {
                    if (not (p[mid] < k))
                    {
                        ++cnt.first;
                    }
                    else
                    {
                        --global_cnt.first;
                    }

                    l = mid + 1;
                }
                else
                {
                    break;
                }
            }

            bool yes = true;
            int ans = std::min(cnt.first, cnt.second) * 2;

            global_cnt.first -= std::min(cnt.first, cnt.second);
            global_cnt.second -= std::min(cnt.first, cnt.second);

            if (cnt.first > cnt.second)
            {
                cnt.first -= cnt.second;

                if (cnt.first > global_cnt.first)
                {
                    yes = false;
                }
                else
                {
                    ans += cnt.first * 2;
                }
            }
            else if (cnt.second > cnt.first)
            {
                cnt.second -= cnt.first;

                if (cnt.second > global_cnt.second)
                {
                    yes = false;
                }
                else
                {
                    ans += cnt.second * 2;
                }
            }

            if (yes)
                std::cout << ans << ' ';
            else
                std::cout << -1 << ' ';
        }

        std::cout.put('\n');
    }

    return 0;
}
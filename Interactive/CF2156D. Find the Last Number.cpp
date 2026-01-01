/**
 * Codeforces Round 1061 (Div. 2)
 * 
 * => D. Find the Last Number ( @c 1900 )
 * 
 * -> https://codeforces.com/contest/2156/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/2156/submission/345960907 By huanhuanonly
 * 
 * @b Interactive
 * @b Constructive
 * @b Bitwise-AND
 * 
 * ----October 27, 2025 [11h:24m:11s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n;
        std::cin >> n;

        static auto query = [](int i, int x) -> bool
        {
            std::cout << "? " << i << ' ' << x << std::endl;

            bool res;
            std::cin >> res;

            return res;
        };

        static auto answer = [](int x) -> void
        {
            std::cout << "! " << x << std::endl;
        };

        std::array<int, 30> cnt{};

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < cnt.size(); ++j)
            {
                if (i & (1 << j))
                {
                    ++cnt[j];
                }
            }
        }

        std::set<int> removed_number, removed_id;
        std::array<std::vector<int>, 2> log;

        int ans = 0;

        for (int j = 0; j < cnt.size(); ++j)
        {
            for (int i = 1; i < n; ++i)
            {
                if (removed_id.contains(i))
                {
                    continue;
                }

                const bool res = query(i, 1 << j);

                log[res].push_back(i);

                if (res)
                {
                    --cnt[j];
                }
            }

            if (cnt[j])
            {
                ans |= 1 << j;

                for (int i = 1; i <= n; ++i)
                {
                    if (not (i & (1 << j)) and not removed_number.contains(i))
                    {
                        removed_number.insert(i);

                        for (int k = j + 1; k < cnt.size(); ++k)
                        {
                            if (i & (1 << k))
                            {
                                --cnt[k];
                            }
                        }
                    }
                }
            }
            else for (int i = 1; i <= n; ++i)
            {
                if ((i & (1 << j)) and not removed_number.contains(i))
                {
                    removed_number.insert(i);

                    for (int k = j + 1; k < cnt.size(); ++k)
                    {
                        if (i & (1 << k))
                        {
                            --cnt[k];
                        }
                    }
                }
            }

            for (int i : log[not cnt[j]])
            {
                removed_id.insert(i);
            }

            log[0].clear();
            log[1].clear();
        }

        answer(ans);
    }

    return 0;
}
/**
 * Tokio Marine & Nichido Fire Insurance Programming Contest 2026 (AtCoder Beginner Contest 459)
 *
 * => D - Adjacent Distinct String ( @c 400 )
 *
 * -> https://atcoder.jp/contests/abc459/tasks/abc459_d
 *
 * Submissions ~> https://atcoder.jp/contests/abc459/submissions/76173127 By huanhuanonly
 *
 * @b Constructive
 *
 * ----May 27, 2026 [22h:45m:53s]----
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
        std::string s;
        std::cin >> s;

        std::array<std::pair<int, char>, 26> cnt{};

        for (int i = 0; i < 26; ++i)
        {
            cnt[i].second = 'a' + i;
        }

        for (char c : s)
        {
            ++cnt[c - 'a'].first;
        }

        std::ranges::sort(cnt, std::ranges::greater{});

        std::string que(1, cnt.front().second);
        --cnt.front().first;

        std::ranges::sort(cnt, std::ranges::greater{});

        for (; cnt[0].first and cnt[1].first; std::ranges::sort(cnt, std::ranges::greater{}))
        {
            while (cnt[0].first and cnt[1].first)
            {
                if (que.back() != cnt[0].second)
                {
                    que.push_back(cnt[0].second);
                    --cnt[0].first;
                }
                else
                {
                    que.push_back(cnt[1].second);
                    --cnt[1].first;
                }
            }
        }

        std::string ans;

        for (int i = 0; i < que.size(); )
        {
            if (cnt[0].first and (ans.empty() or cnt[0].second != ans.back()) and cnt[0].second != que[i])
            {
                ans.push_back(cnt[0].second);
                --cnt[0].first;
            }
            else
            {
                ans.push_back(que[i]);
                ++i;
            }
        }

        if (cnt[0].first and (ans.empty() or cnt[0].second != ans.back()))
        {
            ans.push_back(cnt[0].second);
            --cnt[0].first;
        }

        if (cnt[0].first)
        {
            std::cout << "No\n";
        }
        else
        {
            std::cout << "Yes\n";
            std::cout << ans << '\n';
        }
    }

    return 0;
}
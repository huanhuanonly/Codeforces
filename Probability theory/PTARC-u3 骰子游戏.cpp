/**
 * 2023 睿抗机器人开发者大赛CAIP-编程技能赛-本科组（省赛）
 * 
 * => RC-u3 骰子游戏 ( @c 20 )
 * 
 * -> https://pintia.cn/problem-sets/1680597991209951232/exam/problems/type/7?problemSetProblemId=1680598077168017410
 * 
 * Submissions ~> https://pintia.cn/problem-sets/1680597991209951232/exam/submissions/1931216204108771328 By huanhuanonly
 * 
 * @b Dfs and @b Probability-theory
 * 
 * ----June 07, 2025 [13h:05m:01s]----
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

    int _;
    std::cin >> _;

    while (_--)
    {
        using dices = std::array<int, 5>;
        using counter = std::array<int, 7>;

        dices a{};

        for (int i = 0; i < a.size(); ++i)
        {
            std::cin >> a[i];
        }

        static const std::vector<bool (*)(const counter&)> checkers{
            [](const counter& cnt) -> bool {
                return std::ranges::count(cnt, 5);
            },
            [](const counter& cnt) -> bool {
                return std::ranges::count(cnt, 4);
            },
            [](const counter& cnt) -> bool {
                return std::ranges::count(cnt, 2) and std::ranges::count(cnt, 3);
            },
            [](const counter& cnt) -> bool {
                return cnt[1] == 0 and std::ranges::count(cnt, 1) == 5;
            },
            [](const counter& cnt) -> bool {
                return cnt[6] == 0 and std::ranges::count(cnt, 1) == 5;
            },
            [](const counter& cnt) -> bool {
                return std::ranges::count(cnt, 3);
            },
            [](const counter& cnt) -> bool {
                return std::ranges::count(cnt, 2) == 2;
            },
            [](const counter& cnt) -> bool {
                return std::ranges::count(cnt, 2);
            },
            [](const counter&) -> bool {
                return true;
            }
        };

        auto get_rank = [&](const dices& ds) -> int
        {
            std::array<int, 7> cnt{};
            for (int i : ds)
            {
                ++cnt[i];
            }

            for (int i = 0; i < checkers.size(); ++i)
            {
                if (checkers[i](cnt))
                {
                    return i;
                }
            }

            return 0;
        };

        int rank = get_rank(a);

        if (rank == 0)
        {
            std::cout << "0 0 1\n";
            continue;
        }

        int min = 0;

        // count, size
        std::pair<int, int> ans{0, 1};

        std::vector<int> sel(5);
        int pos = 0;
        
        auto eval = [&](const auto& self, int cpos, dices& ds, std::pair<int, int>& value) -> void
        {
            if (cpos == pos)
            {
                value.first += (get_rank(ds) < rank);
                ++value.second;
                return;
            }

            for (int i = 1; i <= 6; ++i)
            {
                ds[sel[cpos]] = i;
                self(self, cpos + 1, ds, value);
            }
        };

        auto dfs = [&](const auto& self, int i, int cnt) -> void
        {
            if (cnt == 0)
            {
                auto ds = a;
                
                std::pair<int, int> value;
                
                eval(eval, 0, ds, value);

                if (value.first * ans.second > ans.first * value.second)
                {
                    min = pos;
                    ans = value;
                }
                return;
            }

            for (; i < a.size(); ++i)
            {
                sel[pos++] = i;

                self(self, i + 1, cnt - 1);

                sel[--pos] = 0;
            }
        };

        for (int i = 1; i <= a.size(); ++i)
        {
            dfs(dfs, 0, i);
        }

        auto gcd = std::gcd(ans.first, ans.second);
        std::cout << min << ' ' << ans.first / gcd << ' ' << ans.second / gcd << '\n';
    }

    return 0;
}
/**
 * AtCoder Beginner Contest 417
 * 
 * => G - Binary Cat ( @c 625 )
 * 
 * -> https://atcoder.jp/contests/abc417/tasks/abc417_g
 * 
 * Submissions ~> https://atcoder.jp/contests/abc417/submissions/68894482 By huanhuanonly
 * 
 * @b Heavy-Light-decomposition and @b Binary-lifting on @a Trees
 * 
 * ----August 30, 2025 [18h:27m:32s]----
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

    struct node
    {
        uint64 length;

        std::array<int, 2> son;
        bool heavy;

        std::array<int, 20> up;
        std::array<uint64, 20> sum;
    };
    
    enum { none = -1 };

    std::vector<node> tree(2);
    tree[0].length = tree[1].length = 1;
    tree[0].son.fill(none), tree[1].son.fill(none);
    tree[0].up.fill(none), tree[1].up.fill(none);

    tree.reserve(2 + 5e5);

    auto merge = [&](int l, int r) -> void
    {
        tree.emplace_back();
        
        tree.back().length = std::min(tree[l].length + tree[r].length, static_cast<uint64>(1e18));
        tree.back().son = {l, r};
        tree.back().heavy = tree[l].length < tree[r].length;

        tree.back().up[0] = tree.back().son[tree.back().heavy];
        tree.back().sum[0] = tree.back().heavy == 1 ? tree[l].length : 0;

        for (int i = 1; i < 20; ++i)
        {
            if (tree.back().up[i - 1] != none)
            {
                tree.back().up[i] = tree[tree.back().up[i - 1]].up[i - 1];
                tree.back().sum[i] = std::min(tree.back().sum[i - 1] + tree[tree.back().up[i - 1]].sum[i - 1], static_cast<uint64>(1e18));
            }
            else
            {
                tree.back().up[i] = none;
                tree.back().sum[i] = tree.back().sum[i - 1];
            }
        }
    };

    auto find = [&](uint64 x) -> bool
    {
        int cpos = tree.size() - 1;

        while (cpos > 1)
        {
            const bool d = x > tree[tree[cpos].son[0]].length;

            if (tree[cpos].heavy != d)
            {
                if (d == 1)
                {
                    x -= tree[tree[cpos].son[0]].length;
                }

                cpos = tree[cpos].son[d];
            }
            else
            {
                for (int i = 20 - 1; i >= 0; --i)
                {
                    if (tree[cpos].up[i] == none)
                    {
                        continue;
                    }

                    if (tree[cpos].sum[i] < x and tree[cpos].sum[i] + tree[tree[cpos].up[i]].length >= x)
                    {
                        x -= tree[cpos].sum[i];
                        cpos = tree[cpos].up[i];
                    }
                }
            }
        }

        return cpos;
    };

    int q;
    std::cin >> q;

    while (q--)
    {
        int l, r;
        uint64 x;

        std::cin >> l >> r >> x;

        merge(l, r);
        std::cout << find(x) << '\n';
    }

    return 0;
}
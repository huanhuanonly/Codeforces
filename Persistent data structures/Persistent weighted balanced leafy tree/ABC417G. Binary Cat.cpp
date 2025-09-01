/**
 * AtCoder Beginner Contest 417
 * 
 * => G - Binary Cat ( @c 625 )
 * 
 * -> https://atcoder.jp/contests/abc417/tasks/abc417_g
 * 
 * Submissions ~> https://atcoder.jp/contests/abc417/submissions/68962989 By huanhuanonly
 * 
 * @b Persistent-weighted-balanced-leafy-tree
 * 
 * ----August 31, 2025 [15h:14m:44s]----
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

class WeightedBalancedLeafyTree
{
public:

    struct node
    {
        int ls, rs;
        uint64 size;

        bool value;

        node operator+(const node& other) const noexcept
        {
            return node{.size = size + other.size};
        }

        std::weak_ordering operator<=>(const node& other) const noexcept
        {
            if (size > other.size * 3)
            {
                return std::weak_ordering::greater;
            }
            else if (size * 3 < other.size)
            {
                return std::weak_ordering::less;
            }
            else
            {
                return std::weak_ordering::equivalent;
            }
        }
    };

    std::vector<node> tree;
    std::vector<int> roots;

    WeightedBalancedLeafyTree()
        : tree(3), roots(2)
    {
        tree.reserve(1e7);
        roots.reserve(2 + 5e5);

        tree[1].size = tree[2].size = 1;

        tree[1].value = 0;
        tree[2].value = 1;

        roots[0] = 1;
        roots[1] = 2;
    }

    int apply_node()
    {
        tree.emplace_back();
        return tree.size() - 1;
    }

    void push_up(int u)
    {
        tree[u].size = std::min(tree[tree[u].ls].size + tree[tree[u].rs].size, static_cast<uint64>(1e18));
    }

    std::pair<int, int> cut(int u)
    {
        return {tree[u].ls, tree[u].rs};
    }

    int join(int u, int v)
    {
        auto fa = apply_node();

        tree[fa].ls = u;
        tree[fa].rs = v;

        push_up(fa);
        return fa;
    }

    int merge(int u, int v)
    {
        if (u == 0 or v == 0)
        {
            return u | v;
        }
        else if (tree[u].size >= static_cast<uint64>(1e18))
        {
            return u;
        }

        if (tree[u] > tree[v])
        {
            auto [ul, ur] = cut(u);

            if (tree[ul] < tree[ur] + tree[v])
            {
                auto [url, urr] = cut(ur);
                return merge(merge(ul, url), merge(urr, v));
            }
            else
            {
                return merge(ul, merge(ur, v));
            }
        }
        else if (tree[u] < tree[v])
        {
            auto [vl, vr] = cut(v);

            if (tree[u] + tree[vl] > tree[vr])
            {
                auto [vll, vlr] = cut(vl);
                return merge(merge(u, vll), merge(vlr, vr));
            }
            else
            {
                return merge(merge(u, vl), vr);
            }
        }
        else
        {
            return join(u, v);
        }
    }

    bool find(int u, uint64 x)
    {
        if (tree[u].size == 1)
        {
            return tree[u].value;
        }
        else if (x <= tree[tree[u].ls].size)
        {
            return find(tree[u].ls, x);
        }
        else
        {
            return find(tree[u].rs, x - tree[tree[u].ls].size);
        }
    }
};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __huanhuanonly_localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    WeightedBalancedLeafyTree tree;

    int q;
    std::cin >> q;

    while (q--)
    {
        int l, r;
        uint64 x;

        std::cin >> l >> r >> x;

        tree.roots.push_back(tree.merge(tree.roots[l], tree.roots[r]));
        std::cout << tree.find(tree.roots.back(), x) << '\n';
    }

    return 0;
}
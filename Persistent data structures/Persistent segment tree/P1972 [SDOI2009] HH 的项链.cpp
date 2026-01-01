/**
 * => P1972 [SDOI2009] HH 的项链 ( @c 提高+/省选− )
 * 
 * -> https://www.luogu.com.cn/problem/P1972
 * 
 * Submissions ~> https://www.luogu.com.cn/record/244169410 By huanhuanonly
 * 
 * @b Persistent-segment-tree
 * 
 * ----October 30, 2025 [16h:36m:33s]----
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

class PersistentSegmentTree
{
public:

    struct node
    {
        int ls, rs;
        int cnt;
    };

    std::vector<node> tree;
    std::vector<int> roots;

    explicit PersistentSegmentTree(int n)
        : tree(1), roots(1)
    {
        tree.reserve(n << 5);
    }

    void push_up(int u)
    {
        tree[u].cnt = tree[tree[u].ls].cnt + tree[tree[u].rs].cnt;
    }

    void add(int oroot, int& nroot, int l, int r, int i)
    {
        tree.emplace_back(tree[oroot]);
        nroot = tree.size() - 1;

        if (l == r)
        {
            ++tree[nroot].cnt;
            return;
        }

        const int mid = l + r >> 1;

        if (i <= mid)
        {
            add(tree[oroot].ls, tree[nroot].ls, l, mid, i);
        }
        else
        {
            add(tree[oroot].rs, tree[nroot].rs, mid + 1, r, i);
        }

        push_up(nroot);
    }

    int count(int lroot, int rroot, int l, int r, int x, int y)
    {
        if (x <= l and r <= y)
        {
            return tree[rroot].cnt - tree[lroot].cnt;
        }

        const int mid = l + r >> 1;

        int cnt = 0;

        if (x <= mid)
        {
            cnt += count(tree[lroot].ls, tree[rroot].ls, l, mid, x, y);
        }
        if (y > mid)
        {
            cnt += count(tree[lroot].rs, tree[rroot].rs, mid + 1, r, x, y);
        }

        return cnt;
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

    int n;
    std::cin >> n;

    std::vector<int> v(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
    }

    auto s = v;
    std::ranges::sort(s);
    s.erase(std::ranges::unique(s).begin(), s.end());

    std::ranges::transform(v, v.begin(), [&](int i) -> int
    {
        return std::ranges::lower_bound(s, i) - s.begin();
    });

    PersistentSegmentTree seg(n + 1);

    std::vector<int> prev(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        seg.roots.emplace_back();
        seg.add(seg.roots[seg.roots.size() - 2], seg.roots[seg.roots.size() - 1], 1, n + 1, prev[v[i]] + 1);

        prev[v[i]] = i;
    }

    int q;
    std::cin >> q;

    while (q--)
    {
        int l, r;
        std::cin >> l >> r;

        std::cout << seg.count(seg.roots[l - 1], seg.roots[r], 1, n + 1, 1, l) << '\n';
    }

    return 0;
}
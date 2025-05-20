/**
 * => P3372 【模板】线段树 1 ( @c 普及+/提高 )
 * 
 * -> https://www.luogu.com.cn/problem/P3372
 * 
 * Submissions ~> https://www.luogu.com.cn/record/214212400 By huanhuanonly
 * 
 * @b Segment-tree
 * 
 * ----April 19, 2025 [00h:09m:17s]----
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

class SegmentTree
{
public:

    std::vector<uint64> tree, lazy;

    explicit SegmentTree(int n)
        : tree(n << 2), lazy(n << 2)
    { }

    static int ls(int p) { return p << 1; }
    static int rs(int p) { return p << 1 | 1; }

    void push_up(int p)
    {
        tree[p] = tree[ls(p)] + tree[rs(p)];
    }

    void add_lazy(int p, int l, int r, uint64 x)
    {
        lazy[p] += x;
        tree[p] += (r - l + 1) * x;
    }

    void push_down(int p, int l, int r)
    {
        if (lazy[p])
        {
            int mid = l + r >> 1;

            add_lazy(ls(p), l, mid, lazy[p]);
            add_lazy(rs(p), mid + 1, r, lazy[p]);

            lazy[p] = 0;
        }
    }

    void build(const std::vector<uint64>& v, int p, int l, int r)
    {
        if (l == r)
        {
            tree[p] = v[l];
            return;
        }

        int mid = l + r >> 1;

        build(v, ls(p), l, mid);
        build(v, rs(p), mid + 1, r);

        push_up(p);
    }

    void add(int p, int l, int r, int x, int y, uint64 value)
    {
        if (x <= l and r <= y)
        {
            add_lazy(p, l, r, value);
            return;
        }

        push_down(p, l, r);

        int mid = l + r >> 1;

        if (x <= mid)
        {
            add(ls(p), l, mid, x, y, value);
        }
        if (y > mid)
        {
            add(rs(p), mid + 1, r, x, y, value);
        }

        push_up(p);
    }

    uint64 sum(int p, int l, int r, int x, int y)
    {
        if (x <= l and r <= y)
        {
            return tree[p];
        }

        push_down(p, l, r);

        int mid = l + r >> 1;

        uint64 res = 0;

        if (x <= mid)
        {
            res += sum(ls(p), l, mid, x, y);
        }
        if (y > mid)
        {
            res += sum(rs(p), mid + 1, r, x, y);
        }

        return res;
    }
};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    int n, m;
    std::cin >> n >> m;

    SegmentTree seg(n);

    std::vector<uint64> v(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
    }

    seg.build(v, 1, 1, n);

    while (m--)
    {
        uint64 opt, x, y, k;
        std::cin >> opt >> x >> y;

        if (opt == 1)
        {
            std::cin >> k;

            seg.add(1, 1, n, x, y, k);
        }
        else
        {
            std::cout << seg.sum(1, 1, n, x, y) << '\n';
        }
    }

    return 0;
}
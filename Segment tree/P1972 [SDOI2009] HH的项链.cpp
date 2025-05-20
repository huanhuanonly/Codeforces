/**
 * => P1972 [SDOI2009] HH的项链 ( @c 提高+/省选− )
 * 
 * -> https://www.luogu.com.cn/problem/P1972
 * 
 * Submissions ~> https://www.luogu.com.cn/record/214757704 By huanhuanonly
 * 
 * @b Segment-tree and @b offline
 * 
 * ----April 22, 2025 [22h:08m:21s]----
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

    std::vector<int> tree;

    explicit SegmentTree(int n) : tree(n << 2) { }

    static int ls(int p) { return p << 1; }
    static int rs(int p) { return p << 1 | 1; }

    void push_up(int p)
    {
        tree[p] = tree[ls(p)] + tree[rs(p)];
    }

    void set_value(int p, int l, int r, int pos, int value)
    {
        if (l == r)
        {
            tree[p] = value;
            return;
        }

        int mid = l + r >> 1;

        if (pos <= mid)
            set_value(ls(p), l, mid, pos, value);
        else
            set_value(rs(p), mid + 1, r, pos, value);

        push_up(p);
    }

    int sum(int p, int l, int r, int x, int y)
    {
        if (x <= l and r <= y)
        {
            return tree[p];
        }

        int mid = l + r >> 1;
        int res = 0;

        if (x <= mid)
            res = sum(ls(p), l, mid, x, y);
        if (y > mid)
            res += sum(rs(p), mid + 1, r, x, y);

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

    int n;
    std::cin >> n;

    std::vector<int> v(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
    }

    SegmentTree seg(n + 1);

    int m;
    std::cin >> m;

    struct query
    {
        int i, l, r, ans;
    };

    std::vector<query> qs(m);

    for (int i = 0; i < m; ++i)
    {
        qs[i].i = i;
        std::cin >> qs[i].l >> qs[i].r;
    }

    std::sort(qs.begin(), qs.end(), [](const auto& lv, const auto& rv) -> bool
    {
        return lv.r < rv.r;
    });

    std::map<int, int> mp;

    for (int i = 1, pos = 0; pos < m; ++i)
    {
        if (auto it = mp.find(v[i]); it != mp.end())
        {
            seg.set_value(1, 1, n, it->second, 0);
            it->second = i;
        }
        else
        {
            mp[v[i]] = i;
        }

        seg.set_value(1, 1, n, i, 1);

        while (pos < m and qs[pos].r == i)
        {
            qs[pos].ans = seg.sum(1, 1, n, qs[pos].l, qs[pos].r);
            ++pos;
        }
    }

    std::sort(qs.begin(), qs.end(), [](const auto& lv, const auto& rv) -> bool
    {
        return lv.i < rv.i;
    });

    for (const auto& i : qs)
    {
        std::cout << i.ans << '\n';
    }

    return 0;
}
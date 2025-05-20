/**
 * Codeforces Round 947 (Div. 1 + Div. 2)
 * 
 * => E. Chain Queries ( @c 2100 )
 * 
 * -> https://codeforces.com/contest/1975/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/1975/submission/318966815 By huanhuanonly
 * 
 * @b Bfs-order and @b Segment-tree
 * 
 * ----May 10, 2025 [00h:40m:48s]----
*/

/// @brief This is an @c interesting problem!

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

template<typename _ValueType>
class SegmentTree
{
public:
    using value_type = _ValueType;

    std::vector<value_type> tree;

    std::function<value_type(const value_type&, const value_type&)> merge;

    explicit SegmentTree(
        std::size_t n,
        const decltype(merge)& func = [](const value_type& lv, const value_type& rv) -> value_type { return lv + rv; })
            : tree(n << 2), merge(func)
    { }

    SegmentTree(
        std::size_t n,
        const value_type& value,
        const decltype(merge)& func = [](const value_type& lv, const value_type& rv) -> value_type { return lv + rv; })
            : tree(n << 2, value), merge(func)
    { }

    static constexpr std::size_t ls(std::size_t p) { return p << 1; }
    static constexpr std::size_t rs(std::size_t p) { return p << 1 | 1; }

    void push_up(int p)
    {
        tree[p] = merge(tree[ls(p)], tree[rs(p)]);
    }

    virtual void push_down(int p, int l, int r)
    { }

    void build(int p, int l, int r, const std::vector<value_type>& arr)
    {
        if (l == r)
        {
            tree[p] = arr[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(ls(p), l, mid, arr);
        build(rs(p), mid + 1, r, arr);

        push_up(p);
    }

    value_type get_sum(int p, int l, int r, int x, int y)
    {
        if (x <= l and r <= y)
            return tree[p];

        push_down(p, l, r);

        value_type res{};
        int mid = (l + r) >> 1;

        if (x <= mid)
            res = merge(res, get_sum(ls(p), l, mid, x, y));
        if (y > mid)
            res = merge(res, get_sum(rs(p), mid + 1, r, x, y));

        return res;
    }
};

template<typename _ValueType, typename _LazyType>
class LazySegmentTree : public SegmentTree<_ValueType>
{
public:
    using value_type = _ValueType;
    using lazy_type  = _LazyType;

    using SegmentTree<_ValueType>::ls;
    using SegmentTree<_ValueType>::rs;

    using SegmentTree<_ValueType>::push_up;

    using SegmentTree<_ValueType>::tree;

    std::vector<lazy_type> lazy;

    template<typename ...Args>
    LazySegmentTree(Args&& ...args)
        : SegmentTree<_ValueType>(args...), lazy(tree.size()) { }

    virtual void add_lazy(int p, int l, int r, const value_type& v)
    {
        // sum
        if constexpr (false)
        {
            lazy[p] += v;
            tree[p] += (r - l + 1) * v;
        }
        // max/min
        else
        {
            lazy[p] += v;
            tree[p] += v;
        }
    }

    virtual void push_down(int p, int l, int r) override
    {
        if (lazy[p])
        {
            int mid = (l + r) >> 1;

            add_lazy(ls(p), l, mid, lazy[p]);
            add_lazy(rs(p), mid + 1, r, lazy[p]);
            lazy[p] = 0;
        }
    }

    void update(int p, int l, int r, int x, int y, const value_type& v)
    {
        if (x <= l and r <= y)
        {
            add_lazy(p, l, r, v);
            return;
        }

        push_down(p, l, r);

        int mid = (l + r) >> 1;

        if (x <= mid)
            update(ls(p), l, mid, x, y, v);
        if (y > mid)
            update(rs(p), mid + 1, r, x, y, v);
        
        push_up(p);
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

    int _;
    std::cin >> _;

    while (_--)
    {
        int n, q;
        std::cin >> n >> q;

        struct node
        {
            bool color;

            int  parent;
            int  pos;
        };

        std::vector<node> tree(n + 1);

        std::vector<int> c;
        c.reserve(n);

        for (int i = 1, value; i <= n; ++i)
        {
            std::cin >> value;

            if (value)
            {
                c.push_back(i);
            }
        }

        std::vector<std::vector<int>> e(n + 1);

        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            e[u].push_back(v);
            e[v].push_back(u);
        }

        auto dfs = [&](const auto& self, int u) -> void
        {
            for (int i : e[u])
            {
                if (i == tree[u].parent)
                {
                    continue;
                }

                tree[i].parent = u;

                self(self, i);
            }
        };
        
        auto bfs = [&](int start) -> void
        {
            int cpos = 0;
            
            std::queue<int> que;
            que.push(start);

            while (not que.empty())
            {
                int u = que.front();
                que.pop();
                
                tree[u].pos = ++cpos;
                
                for (int i : e[u])
                {
                    if (i == tree[u].parent)
                    {
                        continue;
                    }
                    
                    que.push(i);
                }
            }
        };
        
        dfs(dfs, 1);
        bfs(1);
        
        LazySegmentTree<int, int> seg(n, [](int lv, int rv) -> int { return std::max(lv, rv); });

        int cnt_chain = 0;

        auto flip = [&](int u) -> void
        {
            auto children = e[u] | std::views::filter([&](int i) -> bool { return i != tree[u].parent; });

            if (tree[u].color == 0)
            {
                if (not children.empty())
                {
                    seg.update(1, 1, n, tree[children.front()].pos, tree[children.back()].pos, 1);
                }

                if (u != 1)
                {
                    seg.update(1, 1, n, tree[tree[u].parent].pos, tree[tree[u].parent].pos, 1);
                }

                cnt_chain -= seg.get_sum(1, 1, n, tree[u].pos, tree[u].pos) - 1;
            }
            else
            {
                if (not children.empty())
                {
                    seg.update(1, 1, n, tree[children.front()].pos, tree[children.back()].pos, -1);
                }

                if (u != 1)
                {
                    seg.update(1, 1, n, tree[tree[u].parent].pos, tree[tree[u].parent].pos, -1);
                }

                cnt_chain += seg.get_sum(1, 1, n, tree[u].pos, tree[u].pos) - 1;
            }

            tree[u].color = !tree[u].color;
        };

        for (int i : c)
        {
            flip(i);
        }

        
        while (q--)
        {
            int u;
            std::cin >> u;
            
            flip(u);

            if (cnt_chain == 1 and seg.get_sum(1, 1, n, 1, n) <= 2)
                std::cout << "Yes\n";
            else
                std::cout << "No\n";
        }
    }

    return 0;
}
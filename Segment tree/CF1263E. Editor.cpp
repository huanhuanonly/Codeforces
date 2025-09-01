/**
 * Codeforces Round 603 (Div. 2)
 * 
 * => E. Editor ( @c 2100 )
 * 
 * -> https://codeforces.com/contest/1263/problem/E
 * 
 * Submissions ~> https://codeforces.com/contest/1263/submission/327511612 By huanhuanonly
 * 
 * @b Segment-tree
 * 
 * ----July 05, 2025 [19h:21m:16s]----
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

class SegmentTree
{
public:

    struct node
    {
        int min, max;
    };

private:

    std::vector<node> tree;
    std::vector<int>  lazy;

public:

    explicit SegmentTree(int n) : tree(n << 2), lazy(n << 2) { }

    static int ls(int u) { return u << 1; }
    static int rs(int u) { return u << 1 | 1; }

    void push_up(int u)
    {
        tree[u].min = std::min(tree[ls(u)].min, tree[rs(u)].min);
        tree[u].max = std::max(tree[ls(u)].max, tree[rs(u)].max);
    }

    void add_lazy(int u, int value)
    {
        lazy[u] += value;

        tree[u].min += value;
        tree[u].max += value;
    }

    void push_down(int u)
    {
        if (lazy[u])
        {
            add_lazy(ls(u), lazy[u]);
            add_lazy(rs(u), lazy[u]);

            lazy[u] = 0;
        }
    }

    void add(int u, int l, int r, int x, int y, int value)
    {
        if (x <= l and r <= y)
        {
            add_lazy(u, value);
            return;
        }

        push_down(u);

        int mid = l + r >> 1;

        if (x <= mid)
        {
            add(ls(u), l, mid, x, y, value);
        }
        if (y > mid)
        {
            add(rs(u), mid + 1, r, x, y, value);
        }

        push_up(u);
    }

    int at(int u, int l, int r, int pos)
    {
        if (l == r)
        {
            return tree[u].max;
        }

        push_down(u);

        int mid = l + r >> 1;

        if (pos <= mid)
        {
            return at(ls(u), l, mid, pos);
        }
        else
        {
            return at(rs(u), mid + 1, r, pos);
        }
    }

    std::pair<int, int> minmax() const
    {
        return std::make_pair(tree[1].min, tree[1].max);
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

    std::string ops;
    std::cin >> ops;

    const int N = std::ranges::count(ops, 'R') + 1;
    SegmentTree seg(N);

    int pos = 1;
    std::string s(N + 1, ' ');

    for (const char c : ops)
    {
        switch (c)
        {
        case 'L':
            pos - 1 >= 1 ? --pos : int();
            break;

        case 'R':
            ++pos;
            break;

        default:

            if (s[pos] == c)
            {
                break;
            }
            
            if (s[pos] == '(')
            {
                seg.add(1, 1, N, pos, N, -1);
            }
            else if (s[pos] == ')')
            {
                seg.add(1, 1, N, pos, N, +1);
            }

            if (c == '(')
            {
                seg.add(1, 1, N, pos, N, +1);
            }
            else if (c == ')')
            {
                seg.add(1, 1, N, pos, N, -1);
            }

            s[pos] = c;

            break;
        }

        if (auto [min, max] = seg.minmax(); seg.at(1, 1, N, N) == 0 and min >= 0)
        {
            std::cout << max << ' ';
        }
        else
        {
            std::cout << -1 << ' ';
        }
    }

    return 0;
}
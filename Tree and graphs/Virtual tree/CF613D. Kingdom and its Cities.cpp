/**
 * Codeforces Round 339 (Div. 1)
 * 
 * => D. Kingdom and its Cities ( @c 2800 )
 * 
 * -> https://codeforces.com/contest/613/problem/D
 * 
 * Submissions ~> https://codeforces.com/contest/613/submission/334749505 By huanhuanonly
 * 
 * @b Virtual-tree ( @a stack )
 * @b Lowest-common-ancestor ( @a binary-lifting )
 * @b DP on @a Trees
 * 
 * ----August 21, 2025 [14h:32m:22s]----
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

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> e(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    struct node
    {
        int depth;
        std::array<int, 20> up;
    };

    std::vector<node> tree(n + 1);
    std::vector<int> dfn(n + 1);

    auto build = [&, cnt = 0](auto& self, int u, int fa, int depth) mutable -> void
    {
        tree[u].depth = depth;
        tree[u].up[0] = fa;

        dfn[u] = ++cnt;

        for (int i : e[u] | std::views::filter([fa](int i) -> bool { return i != fa; }))
        {
            self(self, i, u, depth + 1);
        }
    };

    build(build, 1, 0, 1);

    for (int lay = 1; lay < 20; ++lay)
    {
        for (int i = 1; i <= n; ++i)
        {
            tree[i].up[lay] = tree[tree[i].up[lay - 1]].up[lay - 1];
        }
    }

    static auto lowbit = [](int x) -> int
    {
        return x & -x;
    };

    auto lca = [&](int u, int v) -> int
    {
        if (tree[u].depth < tree[v].depth)
        {
            std::swap(u, v);
        }

        for (uint32 x = tree[u].depth - tree[v].depth; x; x -= lowbit(x))
        {
            u = tree[u].up[std::countr_zero(x)];
        }

        if (u == v)
        {
            return u;
        }

        for (int i = 20 - 1; i >= 0; --i)
        {
            if (tree[u].up[i] != tree[v].up[i])
            {
                u = tree[u].up[i];
                v = tree[v].up[i];
            }
        }

        return tree[u].up[0];
    };

    std::vector<std::vector<int>> ve(n + 1);
    std::vector<int> log;

    int q;
    std::cin >> q;

    while (q--)
    {
        int k;
        std::cin >> k;

        std::vector<int> set(k);

        for (int i = 0; i < k; ++i)
        {
            std::cin >> set[i];
        }

        auto compare = [&](int fv, int sv) -> int { return dfn[fv] < dfn[sv]; };

        std::ranges::sort(set, compare);

        std::stack<int> stack;
        stack.push(1);

        bool yes = true;

        for (int i : set | std::views::drop(set.front() == 1))
        {
            if (std::ranges::binary_search(set, tree[i].up[0], compare))
            {
                yes = false;
                break;
            }

            int lca_ = lca(stack.top(), i);

            if (lca_ == stack.top())
            {
                stack.push(i);
            }
            else
            {
                int cur = stack.top();
                stack.pop();

                while (tree[stack.top()].depth > tree[lca_].depth)
                {
                    ve[stack.top()].push_back(cur);

                    cur = stack.top();
                    stack.pop();
                }

                if (stack.top() != lca_)
                {
                    log.push_back(lca_);
                    stack.push(lca_);
                }
                
                ve[stack.top()].push_back(cur);
                stack.push(i);
            }
        }

        if (not stack.empty())
        {
            int cur = stack.top();
            stack.pop();

            while (not stack.empty())
            {
                ve[stack.top()].push_back(cur);
                cur = stack.top();
                stack.pop();
            }
        }

        int ans = 0;

        auto dfs = [&](const auto& self, int u, bool is_key_father) -> int
        {
            bool is_key = std::ranges::binary_search(set, u, compare);
            int cnt = 0;

            for (int i : ve[u])
            {
                cnt += self(self, i, is_key);
            }

            if (cnt > 1 or (cnt + is_key and is_key_father))
            {
                ++ans;
                return 0;
            }
            else
            {
                return cnt or is_key;
            }
        };

        if (yes)
        {
            dfs(dfs, 1, false);
            std::cout << ans << '\n';
        }
        else
        {
            std::cout << -1 << '\n';
        }

        for (int i : set)
        {
            ve[i].clear();
        }

        for (int i : log)
        {
            ve[i].clear();
        }

        ve[1].clear();

        log.clear();
    }

    return 0;
}
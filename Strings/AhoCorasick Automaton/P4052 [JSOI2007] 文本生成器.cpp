/**
 * P4052 [JSOI2007] 文本生成器
 * 
 * -> https://www.luogu.com.cn/problem/P4052
 * 
 * @b Digit-DP on @a AhoCorasick-Automaton
*/

#include <bits/stdc++.h>

using uint    = unsigned int;
using llong   = long long int;
using ullong  = unsigned long long int;
using ldouble = long double;

ullong quick_pow(ullong a, ullong b, ullong mod)
{
    a %= mod;

    ullong ans = 1;
    while (b)
    {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

class AhoCorasickAutomaton
{
public:

    struct node
    {
        int word[26];
        int fail;

        bool end;
    };

    std::vector<node> tree;

    AhoCorasickAutomaton() : tree(1) { }

    int push_node()
    {
        tree.push_back({});
        return tree.size() - 1;
    }

    void insert(const std::string& s)
    {
        int now = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            int c = s[i] - 'A';

            if (tree[now].word[c] == 0)
                tree[now].word[c] = push_node();

            now = tree[now].word[c];
        }

        tree[now].end = true;
    }

    void build_fail()
    {
        std::queue<int> que;
        
        for (int i = 0; i < 26; ++i)
            if (tree[0].word[i])
                que.push(tree[0].word[i]);

        while (not que.empty())
        {
            int now = que.front();
            que.pop();

            for (int i = 0; i < 26; ++i)
            {
                if (tree[now].word[i])
                {
                    tree[tree[now].word[i]].fail = tree[tree[now].fail].word[i];
                    que.push(tree[now].word[i]);
                }
                else
                {
                    tree[now].word[i] = tree[tree[now].fail].word[i];
                }
            }

            tree[now].end |= tree[tree[now].fail].end;
        }
    }

    // The second solution
    ullong query(int len, int mod)
    {
        ullong sum = 0;

        std::vector<std::vector<int>> dp(len + 1, std::vector<int>(tree.size()));

        dp[0][0] = 1;

        for (int l = 1; l <= len; ++l)
            for (int now = 0; now < tree.size(); ++now)
                for (int i = 0; i < 26; ++i)
                    if (not tree[tree[now].word[i]].end)
                        dp[l][tree[now].word[i]] = (dp[l][tree[now].word[i]] + dp[l - 1][now]) % mod;
        
        for (int i = 0; i < tree.size(); ++i)
            sum = (sum + dp[len][i]) % mod;

        return (quick_pow(26, len, mod) + mod - sum) % mod;
    }
};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
    ::freopen("Input.txt", "r", stdin);
    ::freopen("Output.txt", "w", stdout);
#endif

    int n, m;
    std::cin >> n >> m;

    AhoCorasickAutomaton tree;

    std::string s;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> s;

        tree.insert(s);
    }

    tree.build_fail();

    std::vector<std::vector<ullong>> dp(m + 1, std::vector<ullong>(tree.tree.size(), ~0ull));

    constexpr int MOD = 1e4 + 7;

    // The first solution
    std::function<ullong(int, int)> dfs = [&](int pos, int now) -> ullong
    {
        if (pos == m)
            return not tree.tree[now].end;

        if (~dp[pos][now])
            return dp[pos][now];

        ullong sum = 0;

        for (int i = 0; i < 26; ++i)
        {
            if (tree.tree[tree.tree[now].word[i]].end)
                continue;

            sum += dfs(pos + 1, tree.tree[now].word[i]) % MOD;
            sum %= MOD;
        }

        dp[pos][now] = sum;

        return sum;
    };
    
    // std::cout << tree.query(m, MOD) << '\n';

    std::cout << (quick_pow(26, m, MOD) + MOD - dfs(0, 0)) % MOD << '\n';

    return 0;
}
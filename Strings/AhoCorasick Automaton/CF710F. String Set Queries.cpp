/**
 * Educational Codeforces Round 16
 * 
 * => F. String Set Queries
 * 
 * -> https://codeforces.com/problemset/problem/710/F (2400)
 * 
 * @b AhoCorasick-Automaton with @b BinaryOnline
*/

#include <bits/stdc++.h>

using uint = unsigned int;
using llong = long long int;
using ullong = unsigned long long int;
using ldouble = long double;

class AhoCorasickAutomaton
{
public:

    struct node
    {
        int word[26];   // Next word pointer
        int sonptr[26]; // Next son node pointer

        int fail;

        int end;
        int cnt;
    };

    std::vector<node> v;

    // The number of root in v, it's a stack
    std::vector<int> root;
    // The count of string in each root
    std::vector<int> count;

    // The index of the root node cannot be 0
    inline explicit AhoCorasickAutomaton() : v(1, node()) { }

    static constexpr inline std::size_t toindex(int c) { return c - 'a'; }

    inline std::size_t add_node()
    {
        v.push_back(node());
        return v.size() - 1;
    }

    // Merge y into x
    int merge(int x, int y)
    {
        // Directly using non-empty nodes (if found)
        if (x == 0 or y == 0) return x + y;

        v[x].end += v[y].end;
        for (int i = 0; i < 26; ++i)
        {
            v[x].sonptr[i] = merge(v[x].sonptr[i], v[y].sonptr[i]);
        }
        return x;
    }

    /** @param start is root node */
    void build_fail(int start)
    {
        std::queue<int> que;

        for (int i = 0; i < 26; ++i)
        {
            if (v[start].sonptr[i])
            {
                v[start].word[i] = v[start].sonptr[i];

                v[v[start].sonptr[i]].fail = start;
                que.push(v[start].word[i]);
            }
            else
            {
                /** Here is the difference between @b sonptr and @b word */
                v[start].word[i] = start;
            }
        }

        while (not que.empty())
        {
            int ct = que.front();
            que.pop();

            for (int i = 0; i < 26; ++i)
            {
                if (v[ct].sonptr[i])
                {
                    v[ct].word[i] = v[ct].sonptr[i];

                    v[v[ct].word[i]].fail = v[v[ct].fail].word[i];
                    que.push(v[ct].word[i]);
                }
                else
                {
                    v[ct].word[i] = v[v[ct].fail].word[i];
                }
            }
            v[ct].cnt = v[ct].end + v[v[ct].fail].cnt;
        }

        return;
    }

    void insert(const std::string& s)
    {
        // Insert a root node in end
        root.push_back(add_node());
        count.push_back(1);

        int now = root.back();

        for (const char& c : s)
        {
            if (v[now].sonptr[toindex(c)] == 0)
            {
                v[now].sonptr[toindex(c)] = add_node();
            }
            now = v[now].sonptr[toindex(c)];
        }
        v[now].end = 1;

        while (count.size() >= 2 and count[count.size() - 1] == count[count.size() - 2])
        {
            root[root.size() - 2] = merge(root[root.size() - 2], root[root.size() - 1]);
            count[count.size() - 2] += count[count.size() - 1];

            root.pop_back();
            count.pop_back();
        }
        build_fail(root.back());
        return;
    }

    int query(const std::string& s)
    {
        int sum = 0;

        for (int now : root)
        {
            for (const char& c : s)
            {
                now = v[now].word[toindex(c)];
                sum += v[now].cnt;
            }
        }
        return sum;
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

    int n;
    std::cin >> n;
    
    AhoCorasickAutomaton trie, trash;

    int op;
    std::string s;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> op >> s;
        switch (op)
        {
        case 1:
            trie.insert(s);
            break;
        case 2:
            trash.insert(s);
            break;
        case 3:
            std::cout << trie.query(s) - trash.query(s) << std::endl; '\n';
        }
    }

    return 0;
}
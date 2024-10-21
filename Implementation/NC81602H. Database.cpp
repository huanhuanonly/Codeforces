/**
 * 2024 牛客暑期多校训练营 7
 * 
 * => H - Database
 * 
 * -> https://ac.nowcoder.com/acm/contest/81602/H
 * 
 * @b Implementing a simple database
*/

#include <bits/stdc++.h>

using uint    = unsigned int;
using llong   = long long int;
using ullong  = unsigned long long int;
using ldouble = long double;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

#ifdef __localhost
    ::freopen("in", "r", stdin);
    ::freopen("out", "w", stdout);
#endif

    auto $ = std::bind(&std::hash<std::string_view>::operator(), reinterpret_cast<std::hash<std::string_view>*>(0), std::placeholders::_1);

    int n, q;
    std::cin >> n >> q;

    std::map<ullong, int> map_fields;
    
    for (int i = 0; i < n; ++i)
    {
        std::string t;
        std::cin >> t;

        std::string_view v(t);

        map_fields[$(std::ref(v))] = i;
    }

    std::cin.get();

    struct DataItem
    {
        std::vector<std::string> item;
        std::vector<ullong> item_hash;
        
        int flags = 0;

        enum
        {
            flag_inserted = 0x01,
            flag_removed  = 0x02,
        };

        bool is_inserted() const noexcept
        {
            return (flags & flag_inserted) == flag_inserted;
        }

        bool is_removed() const noexcept
        {
            return (flags & flag_removed) == flag_removed;
        }

        void insert() noexcept
        {
            flags |= flag_inserted;
        }

        void remove() noexcept
        {
            flags |= flag_removed;
        }

        void uninsert() noexcept
        {
            flags &= ~flag_inserted;
        }

        void unremove() noexcept
        {
            flags &= ~flag_removed;
        }
    };

    std::list<DataItem> db;
    std::set<ullong> selected_set;

    std::string buffer;

    while (q--)
    {
        std::getline(std::cin, buffer);
        
        auto exec = [&](auto&& exec, std::string_view command, bool output = false) -> void
        {
            std::string_view instruct(command.substr(0, command.find_first_of('(')));
            
            if (instruct == "insert")
            {
                DataItem item;
                item.insert();

                int l = instruct.size() + 1;
                int r = command.find_first_of(",)", l);

                while (r != std::string_view::npos)
                {
                    std::string_view sv(command.begin() + l, command.begin() + r);
                    item.item.emplace_back(sv.begin(), sv.end());
                    item.item_hash.push_back($(std::ref(sv)));

                    l = r + 1;
                    r = command.find_first_of(",)", l);
                }

                db.push_back(std::move(item));
            }
            else if (instruct == "select")
            {
                int pos = instruct.size() + 1;

                std::string_view output_field_name = command.substr(pos, command.find_first_of(',', pos) - pos);

                pos += output_field_name.size() + 1;

                std::string_view condition_field_name = command.substr(pos, command.find_first_of(',', pos) - pos);

                pos += condition_field_name.size() + 1;

                std::string_view condition_value = command.substr(pos, command.size() - 1 - pos);

                ullong hash_output_field_name = $(std::ref(output_field_name));
                ullong hash_condition_field_name = $(std::ref(condition_field_name));
                ullong hash_condition_value = $(std::ref(condition_value));

                int oid = map_fields[hash_output_field_name];
                int cid = map_fields[hash_condition_field_name];

                std::vector<std::string*> que;

                for (auto it = db.begin(); it != db.end(); ++it)
                {
                    if (not it->is_removed() and it->item_hash[cid] == hash_condition_value)
                    {
                        if (output)
                            que.push_back(&(it->item[oid]));
                        else
                            selected_set.insert(it->item_hash[oid]);
                    }
                }

                if (output)
                {
                    std::cout << que.size() << '\n';

                    if (que.size())
                    {
                        std::cout << *que.front() << '\n';
                        std::cout << *que[que.size() / 2 + que.size() % 2 - 1] << '\n';
                        std::cout << *que.back() << '\n';
                    }
                }
            }
            else if (instruct == "delete")
            {
                int pos = instruct.size() + 1;

                std::string_view condition_field_name = command.substr(pos, command.find_first_of(',', pos) - pos);

                pos += condition_field_name.size() + 1;

                std::string_view condition_value = command.substr(pos, command.size() - 1 - pos);

                ullong hash_condition_field_name = $(std::ref(condition_field_name));
                ullong hash_condition_value = $(std::ref(condition_value));

                int cid = map_fields[hash_condition_field_name];

                int cnt = 0;

                for (auto it = db.begin(); it != db.end(); ++it)
                {
                    if (not it->is_removed() and it->item_hash[cid] == hash_condition_value)
                    {
                        it->remove();
                        ++cnt;
                    }
                }

                if (output)
                {
                    std::cout << cnt << '\n';
                }
            }
            else if (instruct == "select_in")
            {
                int pos = instruct.size() + 1;

                std::string_view output_field_name = command.substr(pos, command.find_first_of(',', pos) - pos);

                pos += output_field_name.size() + 1;

                std::string_view condition_field_name = command.substr(pos, command.find_first_of(',', pos) - pos);

                pos += condition_field_name.size() + 1;

                std::string_view condition_value_set = command.substr(pos, command.size() - 1 - pos);

                exec(exec, condition_value_set);

                ullong hash_output_field_name = $(std::ref(output_field_name));
                ullong hash_condition_field_name = $(std::ref(condition_field_name));

                int oid = map_fields[hash_output_field_name];
                int cid = map_fields[hash_condition_field_name];

                std::vector<std::string*> que;

                decltype(selected_set) new_selected_set;

                for (auto it = db.begin(); it != db.end(); ++it)
                {
                    if (not it->is_removed() and selected_set.find(it->item_hash[cid]) != selected_set.end())
                    {
                        if (output)
                            que.push_back(&(it->item[oid]));
                        else
                            new_selected_set.insert(it->item_hash[oid]);
                    }
                }

                if (output)
                {
                    std::cout << que.size() << '\n';

                    if (que.size())
                    {
                        std::cout << *que.front() << '\n';
                        std::cout << *que[que.size() / 2 + que.size() % 2 - 1] << '\n';
                        std::cout << *que.back() << '\n';
                    }
                }
                else
                {
                    selected_set = std::move(new_selected_set);
                }
            }
            else if (instruct == "delete_in")
            {
                int pos = instruct.size() + 1;

                std::string_view condition_field_name = command.substr(pos, command.find_first_of(',', pos) - pos);

                pos += condition_field_name.size() + 1;

                std::string_view condition_value_set = command.substr(pos, command.size() - 1 - pos);

                exec(exec, condition_value_set);

                ullong hash_condition_field_name = $(std::ref(condition_field_name));

                int cid = map_fields[hash_condition_field_name];

                decltype(selected_set) new_selected_set;

                int cnt = 0;

                for (auto it = db.begin(); it != db.end(); ++it)
                {
                    if (not it->is_removed() and selected_set.find(it->item_hash[cid]) != selected_set.end())
                    {
                        it->remove();
                        ++cnt;
                    }
                }

                if (output)
                {
                    std::cout << cnt << '\n';
                }
                else
                {
                    selected_set = std::move(new_selected_set);
                }
            }
            else if (instruct == "commit")
            {
                for (auto it = db.begin(); it != db.end(); )
                {
                    if (it->is_removed())
                    {
                        it = db.erase(it);
                    }
                    else
                    {
                        it->uninsert();
                        ++it;
                    }
                }
            }
            else if (instruct == "abort")
            {
                for (auto it = db.begin(); it != db.end(); )
                {
                    if (it->is_inserted())
                    {
                        it = db.erase(it);
                    }
                    else
                    {
                        it->unremove();
                        ++it;
                    }
                }
            }
            else /* if (instruct == "begin") */
            {
                return;
            }
        };

        exec(exec, buffer, true);

        selected_set.clear();
    }

    return 0;
}
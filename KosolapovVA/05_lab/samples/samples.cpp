#include "polinom.h"
#include "arrayhashtable.h"
#include "sortedtable.h"
#include <iomanip>
void main()
{
    try
    {
        ScanTable<std::string, Polinom> scan_t(20);
        SortedTable<std::string, Polinom> sort_t(20);
        ArrayHashTable<std::string, Polinom> ahash_t(20, 3);
        std::string p_scan, p_sort, p_ahash;
        std::cout << "Enter polynom to scan table: ";
        std::cin >> p_scan;
        std::cout << "Enter polynom to sorted table: ";
        std::cin >> p_sort;
        std::cout << "Enter polynom to hash table: ";
        std::cin >> p_ahash;
        scan_t.Insert(new TabRecord<std::string, Polinom>
            (p_scan, new Polinom(p_scan)));
        sort_t.Insert(new TabRecord<std::string, Polinom>
            (p_sort, new Polinom(p_sort)));
        ahash_t.Insert(new TabRecord<std::string, Polinom>
            (p_ahash, new Polinom(p_ahash)));
        std::cout << "|" << scan_t.GetCurr()->key << std::setw(10) << "|"
            << sort_t.GetCurr()->key << std::setw(10) << "|"
            << ahash_t.GetCurr()->key << std::setw(10) << "|\n";
        int flag = 0;
        int ch_table;
        int ch_op;
        int ch_res;
        bool op_status = 0;
        std::string temp;
        TabRecord<std::string, Polinom>* tr_scan;
        TabRecord<std::string, Polinom>* tr_sort;
        TabRecord<std::string, Polinom>* tr_ahash;
        Polinom pol_1;
        Polinom pol_2;
        Polinom res;
        while (flag != -1)
        {
            switch (flag)
            {
            case 0:
                std::cout << "Chooce operation:\n"
                    << "| 1. Insert polynom | 2. Remove polynom | 3. Find polynom | -1. End working |: ";
                std::cin >> flag;
                if (flag == -1)
                    break;
                std::cout << "Choose table:\n"
                    << "| 1. Scan table | 2. Sort table | 3. Hash table | 4. All table|: ";
                std::cin >> ch_table;
                break;
            case 1:
                std::cout << "Enter polynom to insert: ";
                std::cin >> temp;
                switch (ch_table)
                {
                case 1:
                    scan_t.Insert(new TabRecord<std::string, Polinom>
                        (temp, new Polinom(temp)));
                    break;
                case 2:
                    sort_t.Insert(new TabRecord<std::string, Polinom>
                        (temp, new Polinom(temp)));
                    break;
                case 3:
                    ahash_t.Insert(new TabRecord<std::string, Polinom>
                        (temp, new Polinom(temp)));
                    break;
                case 4:
                    scan_t.Insert(new TabRecord<std::string, Polinom>
                        (temp, new Polinom(temp)));
                    sort_t.Insert(new TabRecord<std::string, Polinom>
                        (temp, new Polinom(temp)));
                    ahash_t.Insert(new TabRecord<std::string, Polinom>
                        (temp, new Polinom(temp)));
                    break;
                }
                scan_t.Reset(); sort_t.Reset(); ahash_t.Reset();
                while (!scan_t.IsTabEnd() || !sort_t.IsTabEnd() || !ahash_t.IsTabEnd())
                {
                    std::cout << "|";
                    if (!scan_t.IsTabEnd())
                    {
                        std::cout << scan_t.GetCurr()->key;
                        scan_t.Next();
                    }
                    else
                        std::cout << " - ";
                    std::cout << std::setw(10) << "|";
                    if (!sort_t.IsTabEnd())
                    {
                        std::cout << sort_t.GetCurr()->key;
                        sort_t.Next();
                    }
                    else
                        std::cout << " - ";
                    std::cout << std::setw(10) << "|";
                    if (!ahash_t.IsTabEnd())
                    {
                        std::cout << ahash_t.GetCurr()->key;
                        ahash_t.Next();
                    }
                    else
                        std::cout << " - ";
                    std::cout << std::setw(10) << "|\n";
                }
                flag = 0;
                break;
            case 2:
                std::cout << "Enter polynom to remove: ";
                std::cin >> temp;
                switch (ch_table)
                {
                case 1:
                    scan_t.Remove(temp);
                    break;
                case 2:
                    sort_t.Remove(temp);
                    break;
                case 3:
                    ahash_t.Remove(temp);
                    break;
                case 4:
                    scan_t.Remove(temp);
                    sort_t.Remove(temp);
                    ahash_t.Remove(temp);
                    break;
                }
                scan_t.Reset(); sort_t.Reset(); ahash_t.Reset();
                while (!scan_t.IsTabEnd() || !sort_t.IsTabEnd() || !ahash_t.IsTabEnd())
                {
                    std::cout << "|";
                    if (!scan_t.IsTabEnd())
                        std::cout << scan_t.GetCurr()->key;
                    else
                        std::cout << " - ";
                    std::cout << std::setw(10) << "|";
                    if (!sort_t.IsTabEnd())
                        std::cout << sort_t.GetCurr()->key;
                    else
                        std::cout << " - ";
                    std::cout << std::setw(10) << "|";
                    if (!ahash_t.IsTabEnd())
                        std::cout << ahash_t.GetCurr()->key;
                    else
                        std::cout << " - ";
                    std::cout << std::setw(10) << "|\n";
                    scan_t.Next(); sort_t.Next(); ahash_t.Next();
                }
                flag = 0;
                break;
            case 3:
                std::cout << "Enter polynom to find: ";
                std::cin >> temp;
                switch (ch_table)
                {
                case 1:
                    tr_scan = scan_t.Find(temp);
                    if (tr_scan != nullptr)
                    {
                        std::cout << "Polynom was found\n";
                        flag = 4;
                    }
                    else
                    {
                        std::cout << "Polynom wasnot found\n";
                        flag = 0;
                    }
                    break;
                case 2:
                    tr_sort = sort_t.Find(temp);
                    if (tr_sort != nullptr)
                    {
                        std::cout << "Polynom was found\n";
                        flag = 4;
                    }
                    else
                    {
                        std::cout << "Polynom wasnot found\n";
                        flag = 0;
                    }
                    break;
                case 3:
                    tr_ahash = ahash_t.Find(temp);
                    if (tr_ahash != nullptr)
                    {
                        std::cout << "Polynom was found\n";
                        flag = 4;
                    }
                    else
                    {
                        std::cout << "Polynom wasnot found\n";
                        flag = 0;
                    }
                    break;
                case 4:
                    tr_scan = scan_t.Find(temp);
                    tr_sort = sort_t.Find(temp);
                    tr_ahash = ahash_t.Find(temp);
                    if (tr_scan != nullptr || tr_sort != nullptr || tr_ahash != nullptr)
                    {
                        std::cout << "Polynom was found: ";
                        if (tr_scan != nullptr)
                            std::cout << "in scan table; ";
                        if (tr_sort != nullptr)
                            std::cout << "in sort table; ";
                        if (tr_ahash != nullptr)
                            std::cout << "in hash table; ";
                        flag = 4;
                    }
                    else
                    {
                        std::cout << "Polynom wasnot found\n";
                        flag = 0;
                    }
                    break;
                }
                break;
            case 4:
                if (!op_status)
                {
                    std::cout << "Choose what to do with the found polynom:\n"
                        << "| 1. add polynom | 2. substruct polynom | 3. multiply polynom | 4. nothing |: ";
                    std::cin >> ch_op;
                    if (ch_op == 4)
                    {
                        flag = 0;
                        op_status = 0;
                        break;
                    }
                }
                if (ch_table == 4)
                {
                    std::cout << "Choose one of polynom:\n";
                    if (tr_scan != nullptr)
                        std::cout << "| 1. from scan table |";
                    if (tr_sort != nullptr)
                        std::cout << "| 2 from sort table |";
                    if (tr_ahash != nullptr)
                        std::cout << "| 3 from hash table |";
                    std::cin >> ch_table;
                }
                if (!op_status)
                {
                    switch (ch_table)
                    {
                    case 1:
                        if (tr_scan == nullptr)
                            throw std::exception("Polynom not found");
                        pol_1 = Polinom(tr_scan->key);
                        break;
                    case 2:
                        if (tr_sort == nullptr)
                            throw std::exception("Polynom not found");
                        pol_1 = Polinom(tr_sort->key);
                        break;
                    case 3:
                        if (tr_ahash == nullptr)
                            throw std::exception("Polynom not found");
                        pol_1 = Polinom(tr_ahash->key);
                        break;
                    }
                    std::cout << "Find 2nd polynom\n";
                    std::cout << "Choose table:\n"
                        << "| 1. Scan table | 2. Sort table | 3. Hash table | 4. All table|: ";
                    std::cin >> ch_table;
                    flag = 3;
                    op_status = 1;
                }
                else
                {
                    switch (ch_table)
                    {
                    case 1:
                        if (tr_scan == nullptr)
                            throw std::exception("Polynom not found");
                        pol_2 = Polinom(tr_scan->key);
                        break;
                    case 2:
                        if (tr_sort == nullptr)
                            throw std::exception("Polynom not found");
                        pol_2 = Polinom(tr_sort->key);
                        break;
                    case 3:
                        if (tr_ahash == nullptr)
                            throw std::exception("Polynom not found");
                        pol_2 = Polinom(tr_ahash->key);
                        break;
                    }
                    flag += ch_op;
                }
                break;
            case 5:
                res = pol_1 + pol_2;
                std::cout << "Result polynom: ";
                std::cout<< res<<"\n";
                std::cout << "Choose what to do with the result: "
                    <<"| 1. if you want insert result | 2. nothing |:";
                std::cin >> ch_res;
                op_status = 0;
                if (ch_res == 1)
                    flag = 8;
                else
                    flag = 0;
                break;
            case 6:
                res = pol_1 - pol_2;
                std::cout << "Result polynom: ";
                std::cout << res << "\n";
                std::cout << "Choose what to do with the result: "
                    << "| 1. if you want insert result | 2. nothing |:";
                std::cin >> ch_res;
                op_status = 0;
                if (ch_res == 1)
                    flag = 8;
                else
                    flag = 0;
                break;
            case 7:
                res = pol_1 * pol_2;
                std::cout << "Result polynom: ";
                std::cout << res << "\n";
                std::cout << "Choose what to do with the result: "
                    << "| 1. if you want insert result | 2. nothing |:";
                std::cin >> ch_res;
                op_status = 0;
                if (ch_res == 1)
                    flag = 8;
                else
                    flag = 0;
                break;
            case 8:
                std::cout << "Choose table:\n"
                    << "| 1. Scan table | 2. Sort table | 3. Hash table | 4. All table|: ";
                std::cin >> ch_table;
                switch (ch_table)
                {
                case 1:
                    scan_t.Insert(new TabRecord<std::string, Polinom> 
                        (res.GetStr(), new Polinom(res)));
                    break;
                case 2:
                    sort_t.Insert(new TabRecord<std::string, Polinom>
                        (res.GetStr(), new Polinom(res)));
                    break;
                case 3:
                    ahash_t.Insert(new TabRecord<std::string, Polinom>
                        (res.GetStr(), new Polinom(res)));
                    break;
                case 4:
                    scan_t.Insert(new TabRecord<std::string, Polinom>
                        (res.GetStr(), new Polinom(res)));
                    sort_t.Insert(new TabRecord<std::string, Polinom>
                        (res.GetStr(), new Polinom(res)));
                    ahash_t.Insert(new TabRecord<std::string, Polinom>
                        (res.GetStr(), new Polinom(res)));
                    break;
                }
                scan_t.Reset(); sort_t.Reset(); ahash_t.Reset();
                while (!scan_t.IsTabEnd() || !sort_t.IsTabEnd() || !ahash_t.IsTabEnd())
                {
                    std::cout << "|";
                    if (!scan_t.IsTabEnd())
                    {
                        std::cout << scan_t.GetCurr()->key;
                        scan_t.Next();
                    }
                    else
                        std::cout << " - ";
                    std::cout << std::setw(10) << "|";
                    if (!sort_t.IsTabEnd())
                    {
                        std::cout << sort_t.GetCurr()->key;
                        sort_t.Next();
                    }
                    else
                        std::cout << " - ";
                    std::cout << std::setw(10) << "|";
                    if (!ahash_t.IsTabEnd())
                    {
                        std::cout << ahash_t.GetCurr()->key;
                        ahash_t.Next();
                    }
                    else
                        std::cout << " - ";
                    std::cout << std::setw(10) << "|\n";
                }
                flag = 0;
                break;
            }
        }
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what();
    }
}